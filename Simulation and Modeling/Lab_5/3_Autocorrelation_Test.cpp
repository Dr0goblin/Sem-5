#include <iostream>
#include <vector>
#include <cmath>
#include <map>
#include <cstdlib>
#include <iomanip>

using namespace std;

double autocorrelation(vector<double>& data, int lag) {
    int n = data.size();
    
    double mean = 0.0;
    for (double val : data) {
        mean += val;
    }
    mean /= n;

    double numerator = 0.0;
    double denominator = 0.0;

    for (int i = 0; i < n - lag; i++) {
        numerator += (data[i] - mean) * (data[i + lag] - mean);
    }

    for (int i = 0; i < n; i++) {
        denominator += (data[i] - mean) * (data[i] - mean);
    }

    if (denominator == 0) return 0.0;
    return numerator / denominator;
}

struct AutocorrResult {
    int sample_size;
    map<int, double> autocorrelations;
    double confidence_limit;
    int significant_count;
    bool independent;
};

AutocorrResult autocorrelation_test(vector<double>& data, int max_lag = 10) {
    int n = data.size();
    double confidence_limit = 1.96 / sqrt(n);

    map<int, double> autocorrelations;
    for (int lag = 1; lag <= max_lag; lag++) {
        autocorrelations[lag] = autocorrelation(data, lag);
    }

    int significant_count = 0;
    for (auto& pair : autocorrelations) {
        if (abs(pair.second) > confidence_limit) {
            significant_count++;
        }
    }

    bool independent = (significant_count <= max_lag * 0.05);

    return {n, autocorrelations, confidence_limit, significant_count, independent};
}

void display_results(AutocorrResult& result) {
    cout << "Sample size: " << result.sample_size << "\n";
    cout << "Confidence limit: \u00b1" << fixed << setprecision(6) 
         << result.confidence_limit << "\n";
    cout << "Significant: " << result.significant_count << "/" 
         << result.autocorrelations.size() << "\n";

    for (auto& pair : result.autocorrelations) {
        string sig = abs(pair.second) > result.confidence_limit ? "*" : " ";
        cout << "Lag " << pair.first << ": " << setprecision(6) 
             << pair.second << " " << sig << "\n";
    }

    cout << "=> " << (result.independent ? "Independent (random)" : "Autocorrelated (not random)") << "\n";
}

int main() {
    srand(time(0));

    // TEST 1: Random numbers
    cout << "TEST 1: Random numbers\n";
    vector<double> random_data;
    for (int i = 0; i < 100; i++) {
        random_data.push_back((double)rand() / RAND_MAX);
    }
    AutocorrResult result1 = autocorrelation_test(random_data, 10);
    display_results(result1);

    // TEST 2: Autocorrelated data
    cout << "\nTEST 2: Autocorrelated data\n";
    vector<double> autocorr_data;
    autocorr_data.push_back((double)rand() / RAND_MAX);
    for (int i = 0; i < 99; i++) {
        double next_val = 0.8 * autocorr_data[i] + 0.2 * ((double)rand() / RAND_MAX);
        autocorr_data.push_back(next_val);
    }
    AutocorrResult result2 = autocorrelation_test(autocorr_data, 10);
    display_results(result2);

    // TEST 3: Periodic data (sin wave)
    cout << "\nTEST 3: Periodic data (sin wave)\n";
    vector<double> periodic_data;
    for (int i = 0; i < 100; i++) {
        periodic_data.push_back(sin(i * 0.1));
    }
    AutocorrResult result3 = autocorrelation_test(periodic_data, 10);
    display_results(result3);

    // Summary
    cout << "\nSummary:\n";
    cout << "Test 1 (Random): " << result1.independent << "\n";
    cout << "Test 2 (Autocorrelated): " << result2.independent << "\n";
    cout << "Test 3 (Periodic): " << result3.independent << "\n";

    return 0;
}

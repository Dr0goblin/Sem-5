#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <map>

using namespace std;

struct ChiSquareResult {
    int sample_size;
    double chi_square;
    double critical_value;
    int degrees_of_freedom;
    bool reject;
    vector<int> bins;
    double expected_freq;
};

ChiSquareResult chi_square_test(vector<double>& data, int num_bins = 10) {
    int n = data.size();

    // Create bins
    vector<int> bins(num_bins, 0);
    for (double value : data) {
        int bin_idx = (int)(value * num_bins);
        if (bin_idx >= num_bins) bin_idx = num_bins - 1;
        bins[bin_idx]++;
    }

    // Expected frequency
    double expected_freq = (double)n / num_bins;

    // Calculate chi-square
    double chi_square = 0.0;
    for (int observed : bins) {
        chi_square += pow(observed - expected_freq, 2) / expected_freq;
    }

    // Degrees of freedom
    int df = num_bins - 1;

    // Critical value (approximation for df=9, alpha=0.05)
    double critical_value = 16.919;
    if (df == 10) critical_value = 18.307;

    bool reject = chi_square > critical_value;

    return {n, chi_square, critical_value, df, reject, bins, expected_freq};
}

void display_chi_square_results(ChiSquareResult& result) {
    cout << "Sample size: " << result.sample_size << "\n";
    cout << "Chi-Square: " << fixed << setprecision(4) << result.chi_square 
         << ", Critical: " << result.critical_value << "\n";
    if (result.reject) {
        cout << "=> REJECT null (does NOT follow uniform)\n";
    } else {
        cout << "=> FAIL TO REJECT null (follows uniform)\n";
    }
}

int main() {
    srand(time(0));

    // TEST 1: Uniform random numbers
    cout << "TEST 1: Uniform Random Numbers\n";
    vector<double> data1;
    for (int i = 0; i < 1000; i++) {
        data1.push_back((double)rand() / RAND_MAX);
    }
    ChiSquareResult result1 = chi_square_test(data1, 10);
    display_chi_square_results(result1);

    // TEST 2: Biased data (clustered middle)
    cout << "\nTEST 2: Biased Data (Clustered Middle)\n";
    vector<double> data2;
    for (int i = 0; i < 1000; i++) {
        data2.push_back(0.3 + ((double)rand() / RAND_MAX) * 0.4);
    }
    ChiSquareResult result2 = chi_square_test(data2, 10);
    display_chi_square_results(result2);

    // TEST 3: Skewed (high values)
    cout << "\nTEST 3: Skewed Data (High Values)\n";
    vector<double> data3;
    for (int i = 0; i < 1000; i++) {
        double x = (double)rand() / RAND_MAX;
        data3.push_back(sqrt(x));
    }
    ChiSquareResult result3 = chi_square_test(data3, 10);
    display_chi_square_results(result3);

    // TEST 4: Skewed (low values)
    cout << "\nTEST 4: Skewed Data (Low Values)\n";
    vector<double> data4;
    for (int i = 0; i < 1000; i++) {
        double x = (double)rand() / RAND_MAX;
        data4.push_back(x * x);
    }
    ChiSquareResult result4 = chi_square_test(data4, 10);
    display_chi_square_results(result4);

    // Summary
    cout << "\nSummary:\n";
    cout << "Test 1 (Uniform): " << result1.reject << "\n";
    cout << "Test 2 (Clustered): " << result2.reject << "\n";
    cout << "Test 3 (Skewed High): " << result3.reject << "\n";
    cout << "Test 4 (Skewed Low): " << result4.reject << "\n";

    return 0;
}

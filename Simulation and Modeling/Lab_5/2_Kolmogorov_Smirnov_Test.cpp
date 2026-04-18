#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <iomanip>

using namespace std;

double uniform_cdf(double x, double a = 0.0, double b = 1.0) {
    if (x < a) return 0.0;
    if (x > b) return 1.0;
    return (x - a) / (b - a);
}

struct KSResult {
    double d_statistic;
    double d_critical;
    double d_plus;
    double d_minus;
    bool reject;
    int sample_size;
};

KSResult ks_test(vector<double>& data, double (*cdf_func)(double)) {
    int n = data.size();
    vector<double> sorted_data = data;
    sort(sorted_data.begin(), sorted_data.end());

    double d_plus = 0.0;
    double d_minus = 0.0;

    for (int i = 0; i < n; i++) {
        double empirical_cdf = (double)(i + 1) / n;
        double theoretical_cdf = cdf_func(sorted_data[i]);

        d_plus = max(d_plus, empirical_cdf - theoretical_cdf);
        d_minus = max(d_minus, theoretical_cdf - empirical_cdf);
    }

    double d_statistic = max(d_plus, d_minus);
    double critical_value = 1.358 / sqrt(n);
    bool reject = d_statistic > critical_value;

    return {d_statistic, critical_value, d_plus, d_minus, reject, n};
}

void display_results(KSResult& result) {
    cout << "D: " << fixed << setprecision(6) << result.d_statistic 
         << ", Critical: " << result.d_critical << "\n";
    cout << "Reject: " << (result.reject ? "true" : "false") << "\n";
}

int main() {
    srand(time(0));

    // TEST 1: Uniform Distribution
    cout << "TEST 1: Uniform Distribution\n";
    vector<double> data1;
    for (int i = 0; i < 50; i++) {
        data1.push_back((double)rand() / RAND_MAX);
    }
    KSResult result1 = ks_test(data1, uniform_cdf);
    display_results(result1);

    // TEST 2: Normal-like data
    cout << "\nTEST 2: Normal-like data vs Uniform\n";
    vector<double> data2;
    for (int i = 0; i < 50; i++) {
        double x = ((double)rand() / RAND_MAX + (double)rand() / RAND_MAX 
                    + (double)rand() / RAND_MAX) / 3.0;
        data2.push_back(x);
    }
    KSResult result2 = ks_test(data2, uniform_cdf);
    display_results(result2);

    // TEST 3: Linear distribution
    cout << "\nTEST 3: Linear distribution\n";
    vector<double> data3;
    for (int i = 0; i < 50; i++) {
        double x = (double)rand() / RAND_MAX;
        x = sqrt(x);
        data3.push_back(x);
    }
    KSResult result3 = ks_test(data3, uniform_cdf);
    display_results(result3);

    // Summary
    cout << "\nSummary:\n";
    cout << "Test 1 (Uniform): " << result1.reject << "\n";
    cout << "Test 2 (Normal): " << result2.reject << "\n";
    cout << "Test 3 (Linear): " << result3.reject << "\n";

    return 0;
}

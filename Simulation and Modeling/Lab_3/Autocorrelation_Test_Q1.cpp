#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    // Data
    double data[] = {0.08, 0.12, 0.95, 0.34, 0.11, 0.56, 0.77, 0.21, 0.04, 0.66,
                     0.43, 0.19, 0.82, 0.55, 0.27, 0.03, 0.99, 0.41, 0.15, 0.60,
                     0.88, 0.32, 0.14, 0.71, 0.22};
    int N = 25;
    int i = 1, m = 5;
    
    int M = (N - i) / m - 1;
    
    cout << fixed << setprecision(6);
    cout << "Program 1 - Autocorrelation Test (i=" << i << ", m=" << m << ")\n";
    cout << "M = " << M << endl;
    
    if (M <= 0) {
        cout << "Not enough data for autocorrelation test\n";
        return 0;
    }
    
    // Calculate autocorrelation
    double rho = 0;
    for (int k = 0; k <= M; k++) {
        rho += data[i - 1 + k * m] * data[i - 1 + (k + 1) * m];
    }
    rho = rho / (M + 1) - 0.25;
    
    // Calculate standard deviation
    double sigma = sqrt(13 * M + 7) / (12 * (M + 1));
    
    // Calculate test statistic
    double z = rho / sigma;
    
    // Critical value for alpha = 0.05 (two-tailed)
    double z_critical = 1.96;
    
    cout << "ρ = " << rho << endl;
    cout << "σ = " << sigma << endl;
    cout << "Z = " << z << endl;
    cout << "Z-critical = " << z_critical << endl;
    
    if (abs(z) <= z_critical) {
        cout << "Result: Accept independence (autocorrelation not significant)\n";
    } else {
        cout << "Result: Reject independence (autocorrelation significant)\n";
    }
    
    return 0;
}
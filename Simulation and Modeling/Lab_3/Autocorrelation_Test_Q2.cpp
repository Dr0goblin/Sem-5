#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    // Data
    double data[] = {0.50, 0.11, 0.23, 0.76, 0.44, 0.82, 0.19, 0.55, 0.33, 0.91,
                     0.02, 0.67, 0.48, 0.12, 0.59, 0.31, 0.88, 0.05, 0.74, 0.26};
    int N = 20;
    int i = 4, m = 2;
    
    int M = (N - i) / m - 1;
    
    cout << fixed << setprecision(6);
    cout << "\nProgram 2 - Autocorrelation Test (i=" << i << ", m=" << m << ")\n";
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
        cout << "Result: Accept independence\n";
    } else {
        cout << "Result: Reject independence\n";
    }
    
    return 0;
}
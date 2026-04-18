#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    // Observed frequencies
    int observed[] = {1010, 860, 90, 35, 5};
    int total = 0;
    
    // Calculate total
    for (int i = 0; i < 5; i++) {
        total += observed[i];
    }
    
    // Expected probabilities for 4-digit random numbers
    double expected_prob[] = {0.504, 0.432, 0.027, 0.036, 0.001};
    double expected[5];
    
    // Calculate expected frequencies
    for (int i = 0; i < 5; i++) {
        expected[i] = expected_prob[i] * total;
    }
    
    // Categories
    const char* categories[] = {"All different", "Exactly one pair", "Two pairs", 
                                "Three of a kind", "All same"};
    
    cout << fixed << setprecision(1);
    cout << "\nProgram 3 - Poker Test\n";
    cout << "Total numbers: " << total << "\n\n";
    cout << left << setw(20) << "Category" << right << setw(12) << "Observed" 
         << setw(15) << "Expected" << endl;
    cout << "----------------------------------------\n";
    
    for (int i = 0; i < 5; i++) {
        cout << left << setw(20) << categories[i] << right << setw(10) 
             << observed[i] << setw(15) << expected[i] << endl;
    }
    
    // Calculate chi-square statistic
    double chi_square = 0;
    for (int i = 0; i < 5; i++) {
        chi_square += pow(observed[i] - expected[i], 2) / expected[i];
    }
    
    // Critical value
    double critical_value = 9.49;  // chi^2_0.05,4
    
    cout << fixed << setprecision(4);
    cout << "\nChi-square statistic: " << chi_square << endl;
    cout << "Critical value (alpha=0.05, df=4): " << critical_value << endl;
    cout << "----------------------------------------\n";
    
    if (chi_square <= critical_value) {
        cout << "Result: Accept independence (numbers are independent)\n";
    } else {
        cout << "Result: Reject independence (numbers are not independent)\n";
    }
    
    return 0;
}
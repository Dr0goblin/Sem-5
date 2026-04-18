/* Question-2: 'If 2% of the products made in a company are defective. Find the probability that
less than 1 item is defective in the sample of 100 items.' */
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double p_defective = 0.02;
    int n_items = 100;
    
    double prob_zero_defective = pow(1 - p_defective, n_items);
    
    cout << "Probability of less than 1 defective: " << prob_zero_defective << endl;
    
    return 0;
}
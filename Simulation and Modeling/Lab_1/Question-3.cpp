/* Question -3: 'If n=10,k=3 and p=.5 calculate Binomial probability.' */
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n = 10;
    int k = 3;
    double p = 0.5;
    
    double combination = tgamma(n + 1) / (tgamma(k + 1) * tgamma(n - k + 1));
    double binomial_prob = combination * pow(p, k) * pow(1 - p, n - k);
    
    cout << "Binomial probability: " << binomial_prob << endl;
    
    return 0;
}
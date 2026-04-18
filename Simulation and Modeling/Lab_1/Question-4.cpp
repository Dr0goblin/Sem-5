/* Question-4: 'What is the probability of obtaining either 3, 6 or 9 heads if one draws a coin ten
times? The binomial formula is used to find the probability of getting exactly k
successes in n trials.' */
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n = 10;
    double p = 0.5;
    
    double prob_3 = tgamma(n + 1) / (tgamma(3 + 1) * tgamma(n - 3 + 1)) * pow(p, 3) * pow(1 - p, n - 3);
    double prob_6 = tgamma(n + 1) / (tgamma(6 + 1) * tgamma(n - 6 + 1)) * pow(p, 6) * pow(1 - p, n - 6);
    double prob_9 = tgamma(n + 1) / (tgamma(9 + 1) * tgamma(n - 9 + 1)) * pow(p, 9) * pow(1 - p, n - 9);
    
    double total_prob = prob_3 + prob_6 + prob_9;
    
    cout << "Probability of 3, 6, or 9 heads: " << total_prob << endl;
    
    return 0;
}
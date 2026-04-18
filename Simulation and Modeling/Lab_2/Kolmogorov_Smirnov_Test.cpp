#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    cout << "\nQuestion 2: K-S Test for Uniform Distribution\n";
    
    double nums[] = {0.54, 0.73, 0.98, 0.11, 0.68};
    int n = 5;
    double alpha = 0.05;
    double D_critical = 0.565;
    
    // Sort the numbers
    sort(nums, nums + n);
    
    cout << "Sorted numbers: ";
    for(int i = 0; i < n; i++) cout << nums[i] << " ";
    cout << endl;
    
    double D_plus_max = 0, D_minus_max = 0;
    
    cout << "\ni\tR(i)\ti/N\ti/N - R(i)\tR(i) - (i-1)/N\n";
    cout << "-------------------------------------------------\n";
    
    for(int i = 0; i < n; i++) {
        double i_over_n = (double)(i + 1) / n;
        double i_minus1_over_n = (double)i / n;
        
        double D_plus = i_over_n - nums[i];
        double D_minus = nums[i] - i_minus1_over_n;
        
        if(D_plus > D_plus_max) D_plus_max = D_plus;
        if(D_minus > D_minus_max) D_minus_max = D_minus;
        
        cout << i+1 << "\t" << nums[i] << "\t" << i_over_n 
             << "\t" << D_plus << "\t\t" << D_minus << endl;
    }
    
    double D = max(D_plus_max, D_minus_max);
    
    cout << "\nD+ max = " << D_plus_max << endl;
    cout << "D- max = " << D_minus_max << endl;
    cout << "D calculated = " << D << endl;
    cout << "D critical (α=0.05, n=5) = " << D_critical << endl;
    
    if(D <= D_critical) {
        cout << "Result: Cannot reject null hypothesis (Numbers are uniform)\n";
    } else {
        cout << "Result: Reject null hypothesis (Numbers are not uniform)\n";
    }
    
    return 0;
}
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    cout << "\nQuestion 3: K-S Test for Independence\n";
    
    double nums[] = {0.35, 0.77, 0.12, 0.33, 0.88, 0.45, 0.19, 0.25, 0.91, 0.54};
    int n = 10;
    double D_critical = 0.41;
    
    // Sort the numbers
    sort(nums, nums + n);
    
    cout << "Sorted numbers: ";
    for(int i = 0; i < n; i++) cout << nums[i] << " ";
    cout << endl;
    
    double D_plus_max = 0, D_minus_max = 0;
    
    for(int i = 0; i < n; i++) {
        double i_over_n = (double)(i + 1) / n;
        double i_minus1_over_n = (double)i / n;
        
        double D_plus = i_over_n - nums[i];
        double D_minus = nums[i] - i_minus1_over_n;
        
        if(D_plus > D_plus_max) D_plus_max = D_plus;
        if(D_minus > D_minus_max) D_minus_max = D_minus;
    }
    
    double D = max(D_plus_max, D_minus_max);
    
    cout << "\nD+ max = " << D_plus_max << endl;
    cout << "D- max = " << D_minus_max << endl;
    cout << "D calculated = " << D << endl;
    cout << "D critical (α=0.05, n=10) = " << D_critical << endl;
    
    if(D <= D_critical) {
        cout << "Result: Cannot reject null hypothesis (Numbers are independent)\n";
    } else {
        cout << "Result: Reject null hypothesis (Numbers are not independent)\n";
    }
    
    return 0;
}
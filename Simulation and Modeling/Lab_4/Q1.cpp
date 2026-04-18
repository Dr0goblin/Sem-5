#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double rho = -0.1945;
    double sigma = 0.1280;
    
    double Z0 = fabs(rho / sigma);
    double critical = 1.96;
    
    cout << "Z0 = " << Z0 << endl;
    cout << "Critical = " << critical << endl;
    
    if(Z0 < critical)
        cout << "Numbers are independent" << endl;
    else
        cout << "Numbers are NOT independent" << endl;
    
    return 0;
}
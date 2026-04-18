#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double observed[] = {680, 289, 31};
    double expected[] = {720, 270, 10};
    
    double chi = 0;
    for(int i = 0; i < 3; i++) {
        chi += pow(observed[i] - expected[i], 2) / expected[i];
    }
    
    cout << "Chi-square = " << chi << endl;
    cout << "Critical = 5.99" << endl;
    
    if(chi > 5.99)
        cout << "Numbers are NOT random" << endl;
    else
        cout << "Numbers are random" << endl;
    
    return 0;
}
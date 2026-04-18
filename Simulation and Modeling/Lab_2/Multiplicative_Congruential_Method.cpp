#include <iostream>
using namespace std;

int main() {
    cout << "Question 1: Random Number Generation\n";
    int x = 117;  
    int a = 43;   
    int m = 1000;
    
    cout << "X0 = " << x << endl;
    for(int i = 1; i <= 4; i++) {
        x = (a * x) % m;
        double r = (double)x / m;
        cout << "X" << i << " = " << x << ", R" << i << " = " << r << endl;
    }
    return 0;
}
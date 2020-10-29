#include <iostream>
using namespace std;

int gcd(int a, int b){
    return b ? gcd(b, a % b) : a;
}

int main(){
    int n1, n2, gcdVal;
    cin >> n1 >> n2;
    gcdVal = gcd(n1, n2);
    cout << gcdVal << '\n' << (n1 * n2) / gcdVal << '\n';
    
    return 0;
}
#include <iostream>
#include <set>
using namespace std;

int main(){
    int N, num;
    set<int> s;
    cin >> N;
    while(N--){
        cin >> num;
        s.insert(num);
    }
    for(auto i : s){
        cout << i << ' ';
    }
    return 0;
}
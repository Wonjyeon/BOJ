#include <iostream>
#include <deque>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, num;
    deque<int> dq;
    string cmd;
    cin >> N;
    while(N--){
        cin >> cmd;
        if(cmd == "push_front") {
            cin >> num;
            dq.push_front(num);
        }
        else if(cmd == "push_back") {
            cin >> num;
            dq.push_back(num);
        }
        else if(cmd == "pop_front") {
            if(dq.empty()) cout << -1 << '\n';
            else {
                cout << dq.front() << '\n';
                dq.pop_front();
            }
        }
        else if(cmd == "pop_back") {
            if(dq.empty()) cout << -1 << '\n';
            else {
                cout << dq.back() << '\n';
                dq.pop_back();
            }
        }
        else if(cmd == "size") {
            cout << dq.size() << '\n';
        }
        else if(cmd == "empty") {
            if(dq.empty()) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
        else if(cmd == "front") {
            if(dq.empty()) cout << -1 << '\n';
            else cout << dq.front() << '\n';
        }
        else if(cmd == "back") {
            if(dq.empty()) cout << -1 << '\n';
            else cout << dq.back() << '\n';
        }
    }
    return 0;
}
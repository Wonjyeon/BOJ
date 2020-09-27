#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N, op, ans;
vector<int> numArr;
vector<char> opArr;
vector<int> opDfs;

void calculate(vector<int> nArr, vector<char> oArr, bool flag){
    char oType;
    for(int i=0; i<oArr.size(); i++){
        oType = oArr[i];
        if(oType == '+'){
            nArr[i+1] = nArr[i] + nArr[i+1];
        }
        else if(oType == '-'){
            nArr[i+1] = nArr[i] - nArr[i+1];
        }
        else if(oType == '*'){
            nArr[i+1] = nArr[i] * nArr[i+1];
        }
    }
    if(flag)
        ans = max(ans, nArr[nArr.size()-1]);
    else
        ans = nArr[nArr.size()-1];
    return;
}
void calDfs(vector<int> nArr, vector<char> oArr){
    int oIdx = 0;
    char oType;
    for(int i=0; i<opDfs.size(); i++){
        oIdx = opDfs[i];
        oType = opArr[oIdx];
        if(oType == '+'){
            nArr[oIdx] = nArr[oIdx] + nArr[oIdx+1];
        }
        else if(oType == '-'){
            nArr[oIdx] = nArr[oIdx] - nArr[oIdx+1];
        }
        else if(oType == '*'){
            nArr[oIdx] = nArr[oIdx] * nArr[oIdx+1];
        }
    }
    int offset = 0;
    for(int i=0; i<opDfs.size(); i++){
        oIdx = opDfs[i] - offset;
        nArr.erase(nArr.begin() + oIdx + 1);
        oArr.erase(oArr.begin() + oIdx);
        offset++;
    }
    calculate(nArr, oArr, true);
    return;
}
void dfs(int idx, int cnt){
    if(cnt > 0){
        calDfs(numArr, opArr);
    }
    for(int i=idx; i<op; i++){
        opDfs.push_back(i);
        dfs(i+2, cnt+1);
        opDfs.pop_back();
    }
    return;
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string str;
    ans = 0;
    cin>>N>>str;
    for(int i=0; i<str.length(); i++){
        char c = str[i];
        if(c>='0' && c<='9')
            numArr.push_back(c-'0');
        else
            opArr.push_back(c);
    }
    calculate(numArr, opArr, false);
    op = opArr.size();
    dfs(0, 0);
    cout<<ans<<'\n';
    return 0;
}
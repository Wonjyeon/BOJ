#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int ans = 0;
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
char map[12][6];
bool flag = false;

void downBlock(){
    while(1){
        int cnt = 0;
        for(int i=10; i>=0; i--){
            for(int j=0; j<6; j++){
                if(map[i][j] == '.' || map[i+1][j] != '.') continue;
                map[i+1][j] = map[i][j];
                map[i][j] = '.';
                cnt++;
            }
        }
        if(cnt == 0) break;
    }
    return;
}

void playGame(){
    bool visited[12][6];
    memset(visited, false, sizeof(visited));
    for(int i=0; i<12; i++){
        for(int j=0; j<6; j++){
            if(map[i][j]!='.'){
                vector<pair<int,int> > puyoVector;
                queue<pair<int,int> > q;
                q.push(make_pair(i,j));
                visited[i][j] = true;
                puyoVector.push_back(make_pair(i,j));
                while(!q.empty()){
                    int x = q.front().first;
                    int y = q.front().second;
                    char c = map[x][y];
                    q.pop();
                    for(int i=0; i<4; i++){
                        int nx = x+dx[i];
                        int ny = y+dy[i];
                        if(nx<0||nx>=12||ny<0||ny>=6||visited[nx][ny]||map[nx][ny]=='.') continue;
                        char nc = map[nx][ny];
                        if(c==nc){
                            visited[nx][ny] = true;
                            q.push(make_pair(nx,ny));
                            puyoVector.push_back(make_pair(nx,ny));
                        }
                    }
                }
                if(puyoVector.size()>=4){
                    flag = true;
                    for(int i=0; i<puyoVector.size(); i++){
                        map[puyoVector[i].first][puyoVector[i].second] = '.';
                    }
                }
            }
        }
    }
    return;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    for(int i=0; i<12; i++){
        for(int j=0; j<6; j++){
            cin>>map[i][j];
        }
    }
    while(1){
        flag = false;
        playGame();
        if(flag == true) {
            ans++;
            downBlock();
        }
        else break;
    }
    cout<<ans<<'\n';
    return 0;
}

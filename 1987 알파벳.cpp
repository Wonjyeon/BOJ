#include <iostream>
#include <algorithm>
using namespace std;

int R, C, ans, map[20][20];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,1,0,-1};
bool visit[50] = {false,};

void dfs(int x, int y, int dist){
    visit[map[x][y]] = true;
    ans = max(ans, dist);
    for(int i=0; i<4; i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(nx<0 || nx>=R || ny<0 || ny>=C) continue;
        if(visit[map[nx][ny]]) continue;
        dfs(nx, ny, dist+1);
    }
    visit[map[x][y]] = false;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>R>>C;
    char c;
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            cin>>c;
            map[i][j] = c-'0';
        }
    }
    ans = -1;
    dfs(0, 0, 1);
    cout<<ans<<'\n';
    return 0;
}
#include <iostream>
#include <queue>
using namespace std;

int T, N, startX, startY, destX, destY;
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {-1, -2, -2, -1, 1, 2, 2, 1};

int bfs(){
    bool visit[301][301] = {false, };
    visit[startX][startY] = true;
    queue<pair<pair<int, int>, int>> q;
    q.push({{startX, startY}, 0});

    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second;
        q.pop();

        if(x == destX && y == destY) return cnt;
        for(int i = 0; i < 8; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= N || ny >= N || visit[nx][ny]) continue;
            q.push({{nx, ny}, cnt + 1});
            visit[nx][ny] = true;
        }
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> T;
    while(T--){
        cin >> N >> startX >> startY >> destX >> destY;
        cout << bfs() << '\n';
    }
    return 0;
}
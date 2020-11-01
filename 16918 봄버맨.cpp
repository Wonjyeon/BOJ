#include <iostream>
using namespace std;

int R, C, N;
int map[201][201] = {0, };
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void printMap(){
    for(int i=0; i<R; i++){
        for(int j=0; j<C; j++){
            if(map[i][j] != 0) cout<<'O';
            else cout<<'.';
        }
        cout<<'\n';
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> R >> C >> N;
    char cc;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            cin >> cc;
            if(cc == 'O') map[i][j] = 2;
            else map[i][j] = 0;
        }
    }
    N--;
    int type = 1;
    while(N--){
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                if(map[i][j] == 0) continue;
                map[i][j]--;
                if(map[i][j] == 0){
                    for(int k=0; k<4; k++){
                        int nx = i + dx[k];
                        int ny = j + dy[k];
                        if(nx < 0 || ny < 0 || nx >= R || ny >= C) continue;
                        if(map[nx][ny] != 1) map[nx][ny] = 0;
                    }
                }
            }
        }
        if(type == 1){
            for(int i=0; i<R; i++){
                for(int j=0; j<C; j++){
                    if(map[i][j] == 0) map[i][j] = 3;
                }
            }
            type = 2;
        }
        else{
            type = 1;
        }
    }
    printMap();
}
#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

struct Ball {
   int depth, rx, ry, bx, by;
};
int RX, RY, BX, BY, HX, HY, N, M, ans = -1;
char map[10][10];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
bool visit[10][10][10][10];
string str;

void move(int& x, int& y, int d) {
   while (1) {
      x += dx[d]; y += dy[d];
      if (map[x][y] == '#') {
         x -= dx[d]; y -= dy[d];
         break;
      }
      else if (map[x][y] == 'O')
         break;
   }
}

int main() {
   ios::sync_with_stdio(0); cin.tie(0);
   cin >> N >> M;
   for (int i = 0; i < N; i++) {
      cin >> str;
      for (int j = 0; j < M; j++) {
         map[i][j] = str[j];
         if (str[j] == 'O')
            HX = i, HY = j;
         else if (str[j] == 'R')
            RX = i, RY = j;
         else if (str[j] == 'B')
            BX = i, BY = j;
      }
   }

   queue<Ball> q;
   q.push({ 0,RX, RY, BX, BY});
   visit[RX][RY][BX][BY] = true;

   while (!q.empty()) {
      Ball ball = q.front(); q.pop();

      if (ball.depth > 10)
         break;
      if (ball.rx == HX && ball.ry == HY) {
         ans = ball.depth;
         break;
      }

      for (int i = 0; i < 4; ++i) {
         int rx = ball.rx, ry = ball.ry;
         int bx = ball.bx, by = ball.by;
         move(rx, ry, i), move(bx, by, i);

         if (bx == HX && by == HY)
            continue;

         if (rx == bx && ry == by) {
            switch (i) {
            case 0:
               ball.rx < ball.bx ? rx-- : bx--; break;
            case 2:
               ball.rx < ball.bx ? bx++ : rx++; break;
            case 1:
               ball.ry < ball.by ? ry-- : by--; break;
            case 3:
               ball.ry < ball.by ? by++ : ry++; break;
            }
         }

         if (!visit[rx][ry][bx][by]) {
            q.push({ ball.depth + 1, rx, ry, bx, by });
            visit[rx][ry][bx][by] = true;
         }
      }
   }

   printf("%d", ans);

   return 0;
}
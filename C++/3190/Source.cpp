#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> field;
const int dirX[4]={0,1,0,-1};
const int dirY[4]={1,0,-1,0};
int N, K, L;
int progress = 0;
int direction = 1;
int oversecond = -1;
bool isOver = false;
int nowX = 0, nowY = 0;

void advance() {
    int tX = nowX, tY = nowY;
    tX+=dirX[direction];
    tY+=dirY[direction];
    if (tX < 0 || tY < 0 || tX >= N || tY >= N || field[tX][tY] > 0) {
        oversecond=progress;
        isOver=true;
        return;
    }
    int nextVal = field[tX][tY];
    field[tX][tY] = field[nowX][nowY] + 1;
    if (nextVal == 0) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (field[i][j] > 0)field[i][j] -= 1;
            }
        }
    }
    nowX=tX;
    nowY=tY;
    progress++;
}

int main() {
    cin >> N;
    field = vector<vector<int>>(N, vector<int>(N, 0));
    cin >> K;
    for (; K > 0; K--) {
        int tmpX, tmpY;
        cin >> tmpX;
        cin >> tmpY;
        field[tmpY-1][tmpX-1] = -1;
    }
    cin >> L;
    field[0][0] = 1;
    for (; L > 0; L--) {
        int second;
        char tDirection;
        cin >> second;
        cin >> tDirection;
        if (isOver)continue;
        while (progress < second&&!isOver)
            advance();
        direction = (direction+(tDirection=='L'?1:3))%4;
        advance();
    }
    while (!isOver)
        advance();
    cout << oversecond+1;

}

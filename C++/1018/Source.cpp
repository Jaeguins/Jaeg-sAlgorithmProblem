#include <iostream>
#include <vector>
using namespace std;
vector<vector<char>> field;
int M, N;

int getMinimumPaint(int x, int y) {
    int countW = 0, countB = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            char diff = ((i%2==0)^(j%2==0))? 'W' : 'B';
            if (field[x + i][y + j] == diff)
                countB++;
            else
                countW++;
        }
    }
    return countW<countB?countW:countB;
}

int main() {
    cin >> M >> N;
    field = vector<vector<char>>(M, vector<char>(N));
    for (int i = 0; i < M; i++)for (int j = 0; j < N; j++)cin >> field[i][j];
    int ret = INT32_MAX;
    for (int i = 0; i < M - 7; i++) {
        for (int j = 0; j < N - 7; j++) {
            int tmp = getMinimumPaint(i, j);
            ret = tmp < ret ? tmp : ret;
        }
    }
    cout << ret;
}

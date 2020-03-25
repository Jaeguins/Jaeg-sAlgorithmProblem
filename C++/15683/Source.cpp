#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int M, N;
vector<vector<int>> originalField = vector<vector<int>>(8, vector<int>(8, 0));
vector<pair<int, int>> cams;
int XESWN[4] = {1, 0, -1, 0};
int YESWN[4] = {0, -1, 0, 1};

void advance(vector<vector<int>>& field, int nowX, int nowY, int dir, bool trig) {
    for (int j = 0;; j++) {
        int tmpX = nowX + j * XESWN[dir],
            tmpY = nowY + j * YESWN[dir];
        if (tmpX >= M || tmpX < 0)break;
        if (tmpY >= N || tmpY < 0)break;
        if (field[tmpX][tmpY] == 6)break;
        if (field[tmpX][tmpY] == (trig ? 0 : -1))field[tmpX][tmpY] = (trig ? -1 : 0);
    }
}

bool compare(pair<int, int>& x, pair<int, int>& y) {
    return originalField[x.first][x.second] > originalField[y.first][y.second];
}

int calc(vector<vector<int>>& originField, int depth) {
    if (depth >= (int)cams.size()) {
        int c = 0;
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                if (originField[i][j] == 0)c++;
        return c;
    }
    int nowX = cams[depth].first, nowY = cams[depth].second;
    int min = INT32_MAX;
    switch (originField[nowX][nowY]) {
    case 1: {
        for (int j = 0; j < 4; j++) {
            vector<vector<int>> field = vector<vector<int>>(originField);
            advance(field, nowX, nowY, j % 4, true);
            int ret = calc(field, depth + 1);
            min = min > ret ? ret : min;
        }
        return min;
    }
    case 2: {
        for (int j = 0; j < 4; j++) {
            vector<vector<int>> field = vector<vector<int>>(originField);
            for (int i = 0; i < 3; i += 2) {
                advance(field, nowX, nowY, (i + j) % 4, true);
            }
            int ret = calc(field, depth + 1);
            min = min > ret ? ret : min;
        }
        return min;
    }
    case 3: {
        for (int j = 0; j < 4; j++) {
            vector<vector<int>> field = vector<vector<int>>(originField);
            for (int i = 0; i < 2; i++) {
                advance(field, nowX, nowY, (i + j) % 4, true);
            }
            int ret = calc(field, depth + 1);
            min = min > ret ? ret : min;
        }
        return min;
    }
    case 4: {
        for (int j = 0; j < 4; j++) {
            vector<vector<int>> field = vector<vector<int>>(originField);
            for (int i = 0; i < 3; i++) {
                advance(field, nowX, nowY, (i + j) % 4, true);
            }
            int ret = calc(field, depth + 1);
            min = min > ret ? ret : min;
        }
        return min;
    }
    case 5: {
        vector<vector<int>> field = vector<vector<int>>(originField);
        for (int i = 0; i < 4; i++)
            advance(field, nowX, nowY, i, true);
        return calc(field, ++depth);
    }
    }
    return -1;
}

int main() {
    cin >> M;
    cin >> N;
    for (int i = 0; i < M; i++)
        for (int j = 0; j < N; j++) {
            cin >> originalField[i][j];
            if (originalField[i][j] % 6 != 0)
                cams.emplace_back(i, j);
        }
    sort(cams.begin(), cams.end(), compare);
    cout << calc(originalField, 0);
}

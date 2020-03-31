#include<iostream>
#include<vector>
using namespace std;
int R, C;
vector<vector<char>> field;
int RESWN[4] = {1, 0, -1, 0};
int CESWN[4] = {0, 1, 0, -1};

int findStep(int x, int y, vector<char>& footstep, int dir) {
    for (char i : footstep)
        if (field[x][y] == i)
            return 0;
    footstep.push_back(field[x][y]);
    int max = 0;
    for (int i = 0; i < 4; i++) {
        const int tX = x + RESWN[i], tY = y + CESWN[i];
        if (tX < 0 || tY < 0 || tX >= R || tY >= C)continue;
        if (i == dir)continue;
        int tMax = findStep(tX, tY, footstep, (i + 2) % 4);
        max = tMax > max ? tMax : max;
    }
    footstep.pop_back();
    return ++max;
}

int main() {
    cin >> R;
    cin >> C;
    field = vector<vector<char>>(R, vector<char>(C));
    for (int i = 0; i < R; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < C; j++)
            field[i][j] = line[j];
    }
    vector<char> footstep;
    cout << findStep(0, 0, footstep, -1);
}

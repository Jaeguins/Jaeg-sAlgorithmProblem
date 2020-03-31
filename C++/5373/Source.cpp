#include<iostream>
#include<vector>

using namespace std;

pair<int, int> cw(pair<int, int> input) {
    return {-input.second + 4, input.first};
}

pair<int, int> ccw(pair<int, int> input) {
    return {input.second, -input.first + 4};
}

void rotate(vector<vector<vector<char>>>& field, int face, bool clockwise) {

    int i = 0, j = 0, k = 0;
    int *x = 0, *y = 0, *z = 0;
    vector<vector<char>> tmpField = vector<vector<char>>(5, vector<char>(5, ' '));
    switch (face % 3) {
        case 0:
            x = &i;
            y = &k;
            z = &j;
            break;
        case 1:
            x = &j;
            y = &i;
            z = &k;
            break;
        case 2:
            x = &k;
            y = &i;
            z = &j;
            break;
    }
    if (face % 3 == 0 && face < 3)clockwise = !clockwise;
    if (face % 3 == 1 && face < 3)clockwise = !clockwise;
    if (face % 3 == 2 && face >= 3)clockwise = !clockwise;
    for (k = face < 3 ? 0 : 3; k < (face < 3 ? 2 : 5); k++) {
        for (i = 0; i < 5; i++)
            for (j = 0; j < 5; j++) {
                const pair<int, int> tmpRotated = clockwise
                                                      ? cw(pair<int, int>(i, j))
                                                      : ccw(pair<int, int>(i, j));
                tmpField[tmpRotated.first][tmpRotated.second] = field[*x][*y][*z];
            }
        for (i = 0; i < 5; i++)
            for (j = 0; j < 5; j++)
                field[*x][*y][*z] = tmpField[i][j];
    }
}

int main() {
    int K;
    cin >> K;
    for (; K > 0; K--) {
        vector<vector<vector<char>>> field = vector<vector<vector<char>>>(5, vector<vector<char>>(5, vector<char>(5)));
        for (int i = 1; i < 4; i++) {
            for (int j = 1; j < 4; j++) {
                field[i][4][j] = 'y';
                field[i][0][j] = 'w';
                field[0][i][j] = 'g';
                field[4][i][j] = 'b';
                field[i][j][0] = 'r';
                field[i][j][4] = 'o';
            }
        }
        int N;
        cin >> N;
        for (; N > 0; N--) {
            char tFace, tDirection;
            cin >> tFace >> tDirection;
            int face = -1;
            bool direction = tDirection == '+';
            switch (tFace) {
            case 'U':
                face = 0;
                break;
            case 'F':
                face = 1;
                break;
            case 'R':
                face = 5;
                break;
            case 'D':
                face = 3;
                break;
            case 'B':
                face = 4;
                break;
            case 'L':
                face = 2;
                break;
            }
            rotate(field, face, direction);
        }
        for (int i = 3; i > 0; i--) {
            for (int j = 1; j < 4; j++) {
                cout << field[j][0][i];
            }
            cout << '\n';
        }
    }
}

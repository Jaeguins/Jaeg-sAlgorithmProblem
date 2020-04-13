#include <iostream>
#include <vector>
using namespace std;

int field[9][9];

struct blank {
    pair<int, int> coord;
    vector<bool> possibility;
    int possibleCount = 9;
};

vector<blank> empties;

void bake(vector<blank>& input) {
    int beforeSize = 0;
    while (beforeSize != input.size()) {
        beforeSize = input.size();

        auto iter = input.begin();
        while (iter != input.end()) {
            if (iter->possibleCount == 1) {
                int val = 0;
                for (bool t : iter->possibility) {
                    if (t)break;
                    val++;
                }
                field[iter->coord.first][iter->coord.second] = val;
                for (auto& tTarget : input) {
                    if (tTarget.coord.first == iter->coord.first ||
                        tTarget.coord.second == iter->coord.second ||
                        (tTarget.coord.first / 3 == iter->coord.first / 3 && tTarget.coord.second / 3 == iter
                                                                                                         ->coord.second
                            / 3)) {
                        if (tTarget.possibility[val]) {
                            tTarget.possibleCount--;
                            tTarget.possibility[val] = false;
                        }
                    }
                }
                iter = input.erase(iter);
            }
            else
                iter++;
        }
    }
}


bool backtrack(vector<blank>& input,int depth) {
    if (input.size() == 0)return true;
    blank target = *input.begin();
    for (int i = 0; i < target.possibility.size(); i++) {
        if (target.possibility[i]) {
            bool tRet = false;
            vector<blank> tInput(input);
            for (int j = 0; j < tInput.begin()->possibility.size(); j++) {
                if (i == j)continue;
                tInput.begin()->possibility[j] = false;
            }
            tInput.begin()->possibleCount=1;
            bake(tInput);
            tRet = backtrack(tInput,depth+1);
            if (tRet)return true;
        }
    }
    return false;
}

int main() {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> field[i][j];
            field[i][j]--;
            if (field[i][j] == -1)empties.push_back({{i, j}, vector<bool>(9, true)});
        }
    }
    for (int n = 0; n < empties.size(); n++) {
        int x = empties[n].coord.first,
            y = empties[n].coord.second;
        for (int i = 0; i < 9; i++) {
            if (field[x][i] >= 0) {
                if (empties[n].possibility[field[x][i]]) {
                    empties[n].possibleCount--;
                    empties[n].possibility[field[x][i]] = false;
                }
            }
            if (field[i][y] >= 0) {
                if (empties[n].possibility[field[i][y]]) {
                    empties[n].possibleCount--;
                    empties[n].possibility[field[i][y]] = false;
                }
            }
        }
        for (int i = (x / 3) * 3; i < (x / 3 + 1) * 3; i++) {
            for (int j = (y / 3) * 3; j < (y / 3 + 1) * 3; j++) {
                if (field[i][j] >= 0) {
                    if (empties[n].possibility[field[i][j]]) {
                        empties[n].possibleCount--;
                        empties[n].possibility[field[i][j]] = false;
                    }
                }
            }
        }
    }
    bake(empties);
    backtrack(empties,0);
    cout<<'\n';
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cout << field[i][j]+1;
            if (j < 8)cout << ' ';
        }
        cout << '\n';
    }
}

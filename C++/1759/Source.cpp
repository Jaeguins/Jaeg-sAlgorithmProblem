#include<iostream>
#include<vector>
#include<algorithm>
int L, C;
using namespace std;

vector<char> field;
vector<int> isVowel;
char vowels[5] = {'a', 'e', 'i', 'o', 'u'};

void calc(int index, int depth, string now, int consonant, int vowel) {
    if (depth == L) {
        if (consonant >= 2 && vowel >= 1)
            cout << now << '\n';
        return;
    }
    for (int i = index + 1; i < field.size(); i++)
        calc(i, depth + 1, now + field[i], consonant+!isVowel[i], vowel+isVowel[i]);
}
int main() {
    cin >> L >> C;
    field = vector<char>(C);
    isVowel = vector<int>(C);
    while (C--)
        cin >> field[C];
    sort(field.begin(), field.end());
    for (int i = 0; i < field.size(); i++) 
        for (int j = 0; j < 5; j++) {
            if (field[i] == vowels[j]) {
                isVowel[i] = 1;
                break;
            }
        }
    calc(-1, 0, "", 0, 0);
}

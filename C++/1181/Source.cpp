#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool comp(string& a, string& b) {
    if (a.size() == b.size()) {
        return a < b;
    }
    else {
        return a.size() < b.size();
    }
}
int main() {
    int N;
    cin >> N;
    vector<string>field = vector<string>(N);
    while (N--) {
        cin >> field[N];
    }
    sort(field.begin(), field.end(), comp);
    string fore;
    for (string t : field) {
        if (t != fore) {
            fore = t;
            cout << t << '\n';
        }
    }

}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int>> lists;

bool compare(pair<int, int>& front, pair<int, int>& back) {
    if (front.first == back.first)
        return front.second <= back.second;
    return front.first < back.first;
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x;
        cin >> y;

        pair<int, int> tmp = pair<int, int>(x, y);
        lists.push_back(tmp);
    }
    sort(lists.begin(), lists.end(), compare);
    for (auto& ptr : lists)
        cout << ptr.first << ' ' << ptr.second << '\n';
}

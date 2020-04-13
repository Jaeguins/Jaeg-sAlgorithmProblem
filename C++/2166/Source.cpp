#include<iostream>
#include<vector>
#include <cmath>
using namespace std;
int N;
vector<pair<long long, long long>> dots;
int main() {
    cin >> N;
    long long acc = 0;
    dots = vector<pair<long long, long long>>(N + 1);
    cin>>dots[0].first>>dots[0].second;
    dots[N] = dots[0];
    for (int i = 1; i < N; i++) {
        cin >> dots[i].first >> dots[i].second;
        acc += (dots[i-1].first * dots[i].second - dots[i-1].second * dots[i].first);
    }
    acc += (dots[N-1].first * dots[N].second - dots[N-1].second * dots[N].first);
    acc *= 5;
    cout.precision(1);
    cout << fixed << abs(acc / 10) << '.' << acc % 10;
}

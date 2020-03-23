#include <iostream>
#include <vector>
using namespace std;

const long long MAX_LONGLONG = 9223372036854775807;

int main() {

    int N, start, end, M;
    cin >> N;
    vector<long long> city_prices = vector<long long>();
    vector<vector<long long>> D(N, vector<long long>(N, MAX_LONGLONG));
    vector<vector<int>> P(N, vector<int>(N, -1));
    cin >> start;
    cin >> end;
    cin >> M;
    for (int i = 0; i < M; i++) {
        int t_start, t_end;
        long long t_price;
        cin >> t_start;
        cin >> t_end;
        cin >> t_price;
        if (D[t_start][t_end] > t_price)
            D[t_start][t_end] = t_price;
        P[t_start][t_end] = t_start;
    }

    for (int i = 0; i < N; i++) {
        if (D[i][i] == MAX_LONGLONG)
            D[i][i] = 0;
        long long tmp;
        cin >> tmp;
        city_prices.push_back(tmp);
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (P[i][j] == -1)continue;
            D[i][j] -= city_prices[j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                if (D[k][j] > D[k][i] + D[i][j] && (D[k][i] != MAX_LONGLONG && D[i][j] != MAX_LONGLONG)) {
                    D[k][j] = D[k][i] + D[i][j];
                    P[k][j] = P[i][j];
                }
            }
        }
    }
    if (D[start][end] == MAX_LONGLONG) {
        cout << "gg" << endl;
        return 0;
    }
    int pre = end;
    for(int i=0;i<N;i++) {
        if(P[i][i]<0&& D[start][i]!=MAX_LONGLONG&&D[i][end]!=MAX_LONGLONG) {
            cout<<"Gee"<<endl;
            return 0;
        }
    }
    long long ret = city_prices[start] - D[start][end];
    if (start == end && ret < city_prices[start]) { ret = city_prices[start]; }

    cout << ret << endl;
    return 0;
}

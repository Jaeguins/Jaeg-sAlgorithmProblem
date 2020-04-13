#include<iostream>
using namespace std;

int main() {
    int N = 9, max = 0, t, index = -1;
    while (N--) {
        cin >> t;
        if (max < t) {
            max = t;
            index = 9 - N;
        }
    }
    cout<<max<<'\n'<<index;
}
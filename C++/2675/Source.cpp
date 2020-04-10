#include<iostream>
using namespace std;

int main() {
    int N, buf;
    string input;
    cin >> N;
    while (N--) {
        cin >> buf >> input;
        for (char t : input)
            for (int i = 0; i < buf; i++)if (t != '\0')cout << t;
        cout<<'\n';
    }
}
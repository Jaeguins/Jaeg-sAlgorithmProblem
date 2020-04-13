#include <iostream>
#include <unordered_map>
using namespace std;
unordered_map<long, long> memo=unordered_map<long,long>();

long factorial(long input) {
    if(input<=1)return 1;
    if (memo.find(input) != memo.end())
        return memo[input];
    long ret = input * factorial(input - 1);
    memo.insert({input, ret});
    return ret;
}

int main() {
    long N, K;
    cin >> N >> K;
    cout << factorial(N) / (factorial(K) * factorial(N - K));
}

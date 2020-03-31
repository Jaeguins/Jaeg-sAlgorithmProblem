#include <iostream>
#include <vector>
using namespace std;
vector<long long> zeros;
vector<long long> ones;
long long calc(vector<int>& f, int depthRemain) {
    if(f.back()==0&&zeros[depthRemain]!=-1) {
        return zeros[depthRemain];
    }
    if(f.back()==1&&ones[depthRemain]!=-1) {
        return ones[depthRemain];
    }
    if (depthRemain == 0) {
        return 1;
    }
    switch (f.back()) {
    case 0: {
        long long ret = 0;
        f.push_back(0);
        ret += calc(f, depthRemain - 1);
        f.pop_back();
        f.push_back(1);
        ret += calc(f, depthRemain - 1);
        f.pop_back();
        zeros[depthRemain]=ret;
        return ret;
    }
    case 1: {
        long long ret=0;
        f.push_back(0);
        ret+=calc(f,depthRemain-1);
        ones[depthRemain]=ret;
        return ret;
        }
    }
    return -1;
}

int main() {
    int N;
    cin >> N;
    if (N <= 2)cout << 1;
    else {
        vector<int> field = vector<int>(1, 0);
        zeros=vector<long long>(N,-1);
        ones=vector<long long>(N,-1);
        cout << calc(field, N - 2);
    }
}

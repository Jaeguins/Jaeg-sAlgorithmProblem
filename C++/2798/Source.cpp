#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N,M;
    cin>>N>>M;
    vector<int> data = vector<int>(N);
    for(int i=0;i<N;i++)cin>>data[i];
    int tmp;
    int ret=INT32_MIN;
    for(int i=0;i<N;i++) {
        for(int j=i+1;j<N;j++) {
            for(int k=j+1;k<N;k++) {
                tmp=data[i]+data[j]+data[k];
                if(tmp<=M&&tmp>ret)ret=tmp;
            }
        }
    }
    cout<<ret;
}
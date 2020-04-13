#include <iostream>
using namespace std;
int main() {
    int N,i=0;
    cin>>N;
    while(i++<N) {
        for(int j=0;j<i;j++)cout<<'*';
        cout<<'\n';
    }
}
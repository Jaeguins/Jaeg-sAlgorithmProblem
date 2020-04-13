#include <iostream>
using namespace std;
int main() {
    int T;
    cin>>T;
    while(T--) {
        int W,H,N;
        cin>>H>>W>>N;
        N--;
        cout<<100*((N)%H+1)+(N)/H+1<<'\n';
    }
}
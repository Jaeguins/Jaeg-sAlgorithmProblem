#include <iostream>
#include <vector>
using namespace std;
vector<bool> field;

int main() {
    field=vector<bool>(1001,true);
    field[0]=false;
    field[1]=false;
    for(int i=2;i<1001;i++) {
        if(field[i]) {
            int j=1;
            while(++j*i<=1000) {
                field[i*j]=false;
            }
        }
    }
    int N,input,count=0;
    cin>>N;
    while(N--) {
        cin>>input;
        if(field[input])count++;
    }
    cout<<count;
}

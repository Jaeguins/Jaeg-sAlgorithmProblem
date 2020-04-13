#include <iostream>
using namespace std;
int main(){
    int N,ret=0;
    string input;
    cin>>N>>input;
    while(N--){
        ret+=(input[N]-'1'+1);
    }
    cout<<ret;
}
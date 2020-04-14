#include <iostream>
using namespace std;
int gcd(int a,int b){
    return b ? gcd(b, a%b) : a;
}
int main(){
    int A,B;
    cin>>A>>B;
    int gcdV=gcd(A>B?A:B,A>B?B:A);
    cout<<gcdV<<'\n'<<A*B/gcdV;
}
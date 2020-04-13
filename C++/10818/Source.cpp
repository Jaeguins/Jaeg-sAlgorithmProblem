#include <iostream>
using namespace std;
int minVal=INT32_MAX,maxVal=INT32_MIN;

int main() {
    int N,input;
    cin>>N;
    while(N--) {
        cin>>input;
        minVal=input<minVal?input:minVal;
        maxVal=input>maxVal?input:maxVal;
    }
    cout<<minVal<<' '<<maxVal;
}

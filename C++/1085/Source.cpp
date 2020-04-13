#include <iostream>
using namespace std;
int main() {
    int x,y,w,h;
    cin>>x>>y>>w>>h;
    int mini=INT32_MAX;
    mini=x<mini?x:mini;
    mini=y<mini?y:mini;
    mini=(w-x)<mini?(w-x):mini;
    mini=(h-y)<mini?(h-y):mini;
    cout<<mini;
}
#include<iostream>
#include<string>
using namespace std;
string ascending="1 2 3 4 5 6 7 8";
string descending="8 7 6 5 4 3 2 1";
int main() {
    
    string input;
    getline(cin,input);
    cout<<(input==ascending?"ascending":(input==descending?"descending":"mixed"));
}
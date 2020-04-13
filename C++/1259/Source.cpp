#include <iostream>
#include <string>

using namespace std;

int main() {
    while (true) {
        string input;
        cin >> input;
        if(input=="0")break;
        int half=input.size()/2;
        int lastInd=input.size()-1;
        bool ret=true;
        for(int i=0;i<half;i++) {
            if(input[i]!=input[lastInd-i]) {
                ret=false;
                break;
            }
        }
        cout<<(ret?"yes":"no")<<'\n';
    }

}

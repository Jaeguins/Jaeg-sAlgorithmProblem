#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin>>N;
    for(int i=0;i<N;i++) {
        string buff;
        cin>>buff;
        int acc=0;
        int combo=0;
        for (char t : buff) {
            if(t=='O') {
                combo+=1;
                acc+=combo;
            }else if(t=='X') {
                combo=0;
            }
        }
        cout<<acc<<'\n';
    }
}
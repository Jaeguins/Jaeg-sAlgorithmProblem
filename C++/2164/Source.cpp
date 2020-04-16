#include <iostream>
#include <list>
using namespace std;
list<int> field;

int main() {
    int N;
    cin>>N;
    while(N--) {
        field.push_back(N);
    }
    while(field.size()!=1) {
        field.pop_back();
        int flop=field.back();
        field.pop_back();
        field.push_front(flop);
    }
    cout<<*field.begin()+1;
}

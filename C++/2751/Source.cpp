#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct person{
    int age;
    string name;
};
int comp(person a,person b){
    return a.age<b.age;
}

int main(){
    int N,i=-1;
    cin>>N;
    vector<person>field=vector<person>(N);
    while(++i<N){
        cin>>field[i].age>>field[i].name;
    }
    stable_sort(field.begin(),field.end(),comp);
    for(person t:field)cout<<t.age<<' '<<t.name<<'\n';
}
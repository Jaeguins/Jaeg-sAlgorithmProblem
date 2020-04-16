#include<vector>
#include<iostream>
#include <algorithm>

using namespace std;
vector<int> field;
bool binSearch(const vector<int>& field, int input) {
    int low = 0;
    int high = field.size()- 1;
    int mid;

    while(low <= high) {
        mid = (low + high) / 2;

        if (field[mid] == input)
            return true;
        else if (field[mid] > input)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return false;
}

int main() {
    cin.tie(nullptr);
    int N,M;
    int input;
    cin>>N;
    field=vector<int>(N);
    while(N--) {
        cin>>field[N];
    }
    sort(field.begin(),field.end());
    cin>>M;
    while(M--) {
        cin>>input;
        cout<<(binSearch(field,input)?1:0)<<'\n';
    }


}

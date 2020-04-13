#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
//DEBUG 미선언 시 제출용
//#define DEBUG

using namespace std;
int N;
vector<int> stack;
string ret;
int toText(string& output) {
    vector<int>input=vector<int>(stack);
#ifdef DEBUG
    for (int i : input) {
        cout << i << '-';
    }
    cout << "\b " << endl;
#endif
    //앞에서부터 알파벳 부여하며 배치, 문제없어 보임
    vector<char> ret = vector<char>(102, '\0');
    for (int i = 0; i < input.size(); i++) {
        ret[input[i] - 1] = i + 'A';
        input[i]--;
    }
    int ptr = 0;
    for (int k = 0; k < N; k++) {
        if (ret[k] != '\0')continue;
        while (ptr < input.size() && input[ptr] == 0) {
            ptr++;
        }
        if(k<stack[ptr])return -1;
        if (ptr == input.size())break;
        ret[k] = 'A' + ptr;
        input[ptr]--;
    }
    output=string(ret.begin(), ret.begin() + N);
    return 0;
}

int calc(int index,int acc) {
    if(acc>N)return -1;
    if(acc==N) {
        string tmp;
        int result=toText(tmp);
        if(result==0 &&ret.compare(tmp)>0) {
            ret=tmp;
#ifdef DEBUG
            cout<<"refresh to : "<<tmp<<endl;
#endif
        }
        return result;
    }
    int retBuf=-1;
    for(int i=N-acc;i>=index+1;i--) {
        stack.push_back(i);
        if(calc(i,acc+i)==0)
            retBuf=0;
        stack.pop_back();
    }
    return retBuf;
}


int main() {
    cin>>N;
    for(int i=0;i<100;i++)ret+='Z';
    int result=calc(0,0);
    if(result==-1)
        cout<<-1;
    else cout<<ret;
    
}

#include<iostream>
#include <string>
#include<vector>
using namespace std;

int char2int(char input) {
    if (input >= '0' && input <= '9')
        return input - '0';
    if (input >= 'A' && input <= 'F')
        return input - 'A' + 10;
    if (input >= 'a' && input <= 'f')
        return input - 'a' + 10;
    throw std::invalid_argument("Invalid input string");
}

char int2char[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
int bufferCount = 0;

void printChar(char t) {
    if (bufferCount == 80) {
        cout << endl;
        bufferCount = 0;
    }
    cout << t;
    bufferCount++;
}

int main() {
    int P;
    cin >> P;
    for (int i = 0; i < P; i++) {
        int B;
        cin >> B;
        string ret;

        int counter = 0;
        int status = 2;
        int preCount = 0;
        while (counter < B*2) {
            char first,second;
            cin>>first;
            cin>>second;
            int nowFirst = char2int(first),
                nowSecond = char2int(second);
            if (status > 1&&preCount==0) {
                if (nowFirst >= 8)
                    status = 0;
                else
                    status = 1;
            }
            else {
                if (status == 0) { status = 2; }
                else { status = 3; }
            }
            switch (status) {
            case 0:
                preCount = (nowFirst - 8) * 16 + nowSecond + 3;
                break;
            case 1:
                preCount = nowFirst * 16 + nowSecond + 1;
                break;
            case 2:
                for(int i=0;i<preCount;preCount--) {
                    ret+=int2char[nowFirst];
                    ret+=int2char[nowSecond];
                }
                break;
            case 3:
                ret+=int2char[nowFirst];
                ret+=int2char[nowSecond];
                preCount--;
                break;
            }
            counter += 2;
        }
        cout<<ret.size()/2<<endl;
        bufferCount=0;
        for (char element : ret) {
            printChar(element);
        }
        cout<<endl;
    }
}

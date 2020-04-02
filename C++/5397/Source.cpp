#include <iostream>
#include <list>
using namespace std;

int main() {
    int N;
    cin >> N;
    cin.get();
    for (; N-- > 0;) {
        auto output = list<char>(1, '\0');
        auto itCursor = output.begin();
        auto end = (--output.end());
        while (true) {
            char i = (char)cin.get();
            if (i == '\n')break;
            switch (i) {
            case '<':
                if (itCursor != output.begin())(--itCursor);
                break;
            case '>':
                if (itCursor != end)(++itCursor);
                break;
            case '-':
                if (output.size() > 1) {
                    auto tmp = itCursor;
                    if (tmp != output.begin()) {
                        --tmp;
                        output.erase(tmp);
                    }
                }
                break;
            default:
                output.insert(itCursor, i);
                break;
            }
        }
        auto outIt = output.begin();
        for (auto i = 0; i < output.size(); i++) {
            if (*outIt == '\0')break;
            cout << *(outIt++);
        }
        cout << '\n';
    }
}

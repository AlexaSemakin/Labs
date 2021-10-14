#include <iostream>
#include <map>
#include <string>
using namespace std;
int globalLogIndex = 1;
void genetatrcharTabel(map<char, int>& charTabel, string pstr) {
    for (int i = 0; i < pstr.size() - 1; i++) {
        if (charTabel[pstr[i]] == 0)
            charTabel[pstr[i]] = pstr.size() - 1 - i;
    }
}
bool check(string& str, string& pstr, int index) {
    cout <<  "check log: " << index << endl;
    if (index < 0) {
        return false;
    }
    for (int i = index; i < index + pstr.size(); i++) {
        if (str[i] != pstr[i - index]) {
            return false;
        }
    }
    return true;
}
int find(string str, string pstr) {
    map<char, int> charTabel;
    genetatrcharTabel(charTabel, pstr);
    int i = 0, tmpSizePstr = 0;
    while (i < str.size()) {
        cout << globalLogIndex++ << ") log: " << i << " " << str[i] << endl;
        if (str[i] == pstr[pstr.size() - 1]) {
            if (check(str, pstr, i - pstr.size() + 1)) {
                return i - pstr.size() + 1;
            }
            else {
                i++;
            }
        }
        else if (charTabel[str[i]]) {
            i++;
        }
        else {
            i += charTabel[str[i]] == 0 ? pstr.size() : charTabel[str[i]];
        }
    }
    return -1;
}

int main() {
    string str, pstr;
    getline(cin, str);
    getline(cin, pstr);
    cout << "ans:" << find(str, pstr);
}
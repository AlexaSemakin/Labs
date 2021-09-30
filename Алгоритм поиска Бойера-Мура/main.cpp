#include <iostream>
#include <map>
#include <string>
using namespace std;
void genetatrcharTabel(map<char,int> &charTabel, string pstr){
    for(int i = 0; i < pstr.size()-1; i++){
        if (charTabel[pstr[i]] == 0)
            charTabel[pstr[i]] = pstr.size()-1-i; 
    }
}
bool check(string &str, string &pstr, int index){
    cout << "log: " <<"-check "<< index << " " << str[index] <<  endl;
    for(int i=index; i < index+pstr.size(); i++){
        if (str[i] != pstr[i-index]){
            cout << str[i] << "-"<< pstr[i-index] << endl;
            return false;
        }
    }
    return true;
}
int main(){
    string str, pstr;
    getline(cin, str);
    getline(cin, pstr);
    map<char,int> charTabel;
    genetatrcharTabel(charTabel, pstr);
    int i=0, tmpSizePstr = 0;
    while (i < str.size()){
        cout << "log: " << i << " " << str[i] << endl;
        if (str[i] == pstr[pstr.size()-1]){
            if (check(str, pstr, i-pstr.size())){
                cout << i-pstr.size(); 
                return 0;
            }
            else {
                i++;
            }
        }
        else {
            i+= charTabel[str[i]] == 0 ? pstr.size() : charTabel[str[i]];
        }
    }
    cout << "NO ANS  " << "log: " << str.find(pstr);
}
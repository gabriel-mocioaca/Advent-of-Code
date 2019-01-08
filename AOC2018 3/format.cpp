#include <bits/stdc++.h>
using namespace std;

int main(){
    ifstream in("input.txt");
    ofstream out("3.txt");
    string s;
    while(!in.eof()){
        in >> s;
        in >> s;
        in >> s;
        for (int i = 0; i < s.size(); ++i){
            if(s[i] >= '0' && s[i] <= '9')
                out << s[i];
            else
                out << ' ';
        }
        in >> s;
        for (int i = 0; i < s.size(); ++i){
            if(s[i] >= '0' && s[i] <= '9')
                out << s[i];
            else
                out << ' ';
        }
        out << endl;
    }
}

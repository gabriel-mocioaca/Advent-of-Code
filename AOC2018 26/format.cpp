#include <bits/stdc++.h>
using namespace std;

ifstream in("input.txt");
ofstream out("26.txt");

int main(){
    string s;
    in >> s;
    for(int i = 0; i < s.size(); ++i){
        if(s[i] <= '9' && s[i] >= '0')
            out << s[i];
        else
            out << ' ';
    }
}

#include <bits/stdc++.h>
using namespace std;

ifstream in("input.txt");
ofstream out("17.txt");

int main(){
    string s;
    while(!in.eof()){
        getline(in, s);
        out << s[0] << ' ';
        for(int i = 2; i < s.size(); ++i){
            if(s[i] >= '0' && s[i] <= '9')
                out << s[i];
            else
                out << ' ';
        }
        out << endl;
    }
}

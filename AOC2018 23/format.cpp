#include <bits/stdc++.h>
using namespace std;

ifstream in("input.txt");
ofstream out("23.txt");

int main(){
    string s;
    while(!in.eof()){
        getline(in, s);
        for(int i = 0; i < s.size(); ++i){
            if((s[i] >= '0' && s[i] <= '9') || s[i] == '-'){
                out << s[i];
            }
            else{
                out << ' ';
            }
        }
        out << endl;
    }
}

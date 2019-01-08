#include <bits/stdc++.h>
using namespace std;

int main(){
    ifstream in("input1.txt");
    ofstream out("16-1.txt");

    string s;
    while(!in.eof()){
        getline(in, s);
        for (int i = 0; i < s.size(); ++i){
            if(s[i] >= '0' && s[i] <= '9')
                out << s[i];
            else
                out << ' ';
        }
        out << endl;
    }
}

#include <bits/stdc++.h>
using namespace std;

int main(){
    ifstream in("input.txt");
    ofstream out("4.txt");

    set<string> input;
    string s;
    while(!in.eof()){
        getline(in, s);
        input.insert(s);
    }
    for(auto it : input){
        out << it << endl;
    }
}

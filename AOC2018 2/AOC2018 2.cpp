#include <bits/stdc++.h>

using namespace std;

ifstream in("2.txt");
ofstream out("out.txt");

int compare(string a, string b){
    int cnt = 0;
    for(int i = 0; i < a.size(); ++i){
        if (a[i] != b[i])
            cnt++;
    }
    return cnt;
}

void print(string a, string b){
    for(int i = 0; i < a.size(); ++i){
        if (a[i] == b[i])
            out << a[i];
    }
}

int main(){


    vector<string> v;
    string s;

    while(in>>s){
        v.push_back(s);
    }

    bool found = false;
    for(int i = 0; i < v.size(); ++i){
        for(int j = 0; j < v.size(); ++j){
            if(compare(v[i],v[j]) == 1){
                print(v[i],v[j]);
                found = true;
                break;
            }
        }
        if(found) break;
    }
}

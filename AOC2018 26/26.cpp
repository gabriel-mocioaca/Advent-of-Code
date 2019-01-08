#include <bits/stdc++.h>
using namespace std;

ifstream in("26.txt");

int main(){
    vector<int> v;
    int x, m = INT_MAX;

    while(!in.eof()){
        in >> x;
        v.push_back(x);
        m = min(m, x);
    }
    for(auto it : v){
        cout << char(it - m + 32);
    }
}

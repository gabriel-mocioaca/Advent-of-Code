#include <bits/stdc++.h>

using namespace std;

ifstream in("8.txt");
ofstream out("out.txt");

int x = 0;

int read(){
    int sum = 0;
    vector<int> v;

    int child, meta, x;

    in >> child >> meta;

    for(int i = 0; i < child; ++i){
        v.push_back(read());
    }
    if(child == 0){
        for(int i = 0; i < meta; ++i){
            in >> x;
            sum += x;
        }
    }
    else{
        for(int i = 0; i < meta; ++i){
            in >> x;
            sum += (x - 1 < v.size() ? v[x-1] : 0);
        }
    }
    return sum;
}

int main(){
    out << read();
}

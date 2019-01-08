#include <bits/stdc++.h>

using namespace std;

void addr(vector<int> &rez, int a, int b, int c){
    rez[c] = rez[a] + rez[b];
}

void addi(vector<int> &rez, int a, int b, int c){
    rez[c] = rez[a] + b;
}

void mulr(vector<int> &rez, int a, int b, int c){
    rez[c] = rez[a] * rez[b];
}

void muli(vector<int> &rez, int a, int b, int c){
    rez[c] = rez[a] * b;
}

void banr(vector<int> &rez, int a, int b, int c){
    rez[c] = rez[a] & rez[b];
}

void bani(vector<int> &rez, int a, int b, int c){
    rez[c] = rez[a] & b;
}

void borr(vector<int> &rez, int a, int b, int c){
    rez[c] = rez[a] | rez[b];
}

void bori(vector<int> &rez, int a, int b, int c){
    rez[c] = rez[a] | b;
}

void setr(vector<int> &rez, int a, int b, int c){
    rez[c] = rez[a];
}

void seti(vector<int> &rez, int a, int b, int c){
    rez[c] = a;
}

void gtir(vector<int> &rez, int a, int b, int c){
    rez[c] = (a > rez[b] ? 1 : 0);
}

void gtri(vector<int> &rez, int a, int b, int c){
    rez[c] = (rez[a] > b ? 1 : 0);
}

void gtrr(vector<int> &rez, int a, int b, int c){
    rez[c] = (rez[a] > rez[b] ? 1 : 0);
}

void eqir(vector<int> &rez, int a, int b, int c){
    rez[c] = (a == rez[b] ? 1 : 0);
}

void eqri(vector<int> &rez, int a, int b, int c){
    rez[c] = (rez[a] == b ? 1 : 0);
}

void eqrr(vector<int> &rez, int a, int b, int c){
    rez[c] = (rez[a] == rez[b] ? 1 : 0);
}

ifstream in("16-2.txt");

int main(){
    vector<int> x (4, 0);
    int op, a, b, c;
    while(!in.eof()){
        in>> op >> a >> b >> c;
        if(op == 13) addr(x, a, b, c);
        if(op == 15) addi(x, a, b, c);
        if(op == 10) mulr(x, a, b, c);
        if(op == 8) muli(x, a, b, c);
        if(op == 7) banr(x, a, b, c);
        if(op == 0) bani(x, a, b, c);
        if(op == 5) borr(x, a, b, c);
        if(op == 6) bori(x, a, b, c);
        if(op == 12) setr(x, a, b, c);
        if(op == 2) seti(x, a, b, c);
        if(op == 14) gtir(x, a, b, c);
        if(op == 1) gtri(x, a, b, c);
        if(op == 11) gtrr(x, a, b, c);
        if(op == 3) eqir(x, a, b, c);
        if(op == 9) eqri(x, a, b, c);
        if(op == 4) eqrr(x, a, b, c);
        cout << x[0] << ' ' << x[1] << ' ' << x[2] << ' ' << x[3] << endl;
    }
    cout << x[0];
}

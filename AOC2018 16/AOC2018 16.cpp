#include <bits/stdc++.h>

using namespace std;

ifstream in("16-1.txt");

vector<int> addr(vector<int> reg, int a, int b, int c){
    vector<int> rez(4);
    rez = reg;
    rez[c] = rez[a] + rez[b];

    return rez;
}

vector<int> addi(vector<int> reg, int a, int b, int c){
    vector<int> rez(4);
    rez = reg;
    rez[c] = reg[a] + b;

    return rez;
}

vector<int> mulr(vector<int> reg, int a, int b, int c){
    vector<int> rez(4);
    rez = reg;
    rez[c] = rez[a] * rez[b];

    return rez;
}

vector<int> muli(vector<int> reg, int a, int b, int c){
    vector<int> rez(4);
    rez = reg;
    rez[c] = rez[a] * b;

    return rez;
}

vector<int> banr(vector<int> reg, int a, int b, int c){
    vector<int> rez(4);
    rez = reg;
    rez[c] = rez[a] & rez[b];

    return rez;
}

vector<int> bani(vector<int> reg, int a, int b, int c){
    vector<int> rez(4);
    rez = reg;
    rez[c] = rez[a] & b;

    return rez;
}

vector<int> borr(vector<int> reg, int a, int b, int c){
    vector<int> rez(4);
    rez = reg;
    rez[c] = rez[a] | rez[b];

    return rez;
}

vector<int> bori(vector<int> reg, int a, int b, int c){
    vector<int> rez(4);
    rez = reg;
    rez[c] = rez[a] | b;

    return rez;
}

vector<int> setr(vector<int> reg, int a, int b, int c){
    vector<int> rez(4);
    rez = reg;
    rez[c] = rez[a];

    return rez;
}

vector<int> seti(vector<int> reg, int a, int b, int c){
    vector<int> rez(4);
    rez = reg;
    rez[c] = a;

    return rez;
}

vector<int> gtir(vector<int> reg, int a, int b, int c){
    vector<int> rez(4);
    rez = reg;
    rez[c] = (a > rez[b] ? 1 : 0);

    return rez;
}

vector<int> gtri(vector<int> reg, int a, int b, int c){
    vector<int> rez(4);
    rez = reg;
    rez[c] = (rez[a] > b ? 1 : 0);

    return rez;
}

vector<int> gtrr(vector<int> reg, int a, int b, int c){
    vector<int> rez(4);
    rez = reg;
    rez[c] = (rez[a] > rez[b] ? 1 : 0);

    return rez;
}

vector<int> eqir(vector<int> reg, int a, int b, int c){
    vector<int> rez(4);
    rez = reg;
    rez[c] = (a == rez[b] ? 1 : 0);

    return rez;
}

vector<int> eqri(vector<int> reg, int a, int b, int c){
    vector<int> rez(4);
    rez = reg;
    rez[c] = (rez[a] == b ? 1 : 0);

    return rez;
}

vector<int> eqrr(vector<int> reg, int a, int b, int c){
    vector<int> rez(4);
    rez = reg;
    rez[c] = (rez[a] == rez[b] ? 1 : 0);

    return rez;
}

bool is_equal(vector<int> a, vector<int> b){
    return ((a[0] == b[0]) && (a[1] == b[1]) && (a[2] == b[2]) && (a[3] == b[3]));
}
void pr(vector<int> a){
    cout << a[0] << ' ' << a[1] << ' ' << a[2] << ' ' << a[3] << '\n'
;}


void test(vector<int> init, vector<vector<int>> &op, int z, int a, int b, int c, vector<int> rez){
    if(is_equal(rez, addr(init,a,b,c))) op[0][z] = 1;
    if(is_equal(rez, addi(init,a,b,c))) op[1][z] = 1;
    if(is_equal(rez, mulr(init,a,b,c))) op[2][z] = 1;
    if(is_equal(rez, muli(init,a,b,c))) op[3][z] = 1;
    if(is_equal(rez, banr(init,a,b,c))) op[4][z] = 1;
    if(is_equal(rez, bani(init,a,b,c))) op[5][z] = 1;
    if(is_equal(rez, borr(init,a,b,c))) op[6][z] = 1;
    if(is_equal(rez, bori(init,a,b,c))) op[7][z] = 1;
    if(is_equal(rez, setr(init,a,b,c))) op[8][z] = 1;
    if(is_equal(rez, seti(init,a,b,c))) op[9][z] = 1;
    if(is_equal(rez, gtir(init,a,b,c))) op[10][z]= 1;
    if(is_equal(rez, gtri(init,a,b,c))) op[11][z]= 1;
    if(is_equal(rez, gtrr(init,a,b,c))) op[12][z]= 1;
    if(is_equal(rez, eqir(init,a,b,c))) op[13][z]= 1;
    if(is_equal(rez, eqri(init,a,b,c))) op[14][z]= 1;
    if(is_equal(rez, eqrr(init,a,b,c))) op[15][z]= 1;

}


bool has_val(vector<set<int>> us){
    for(auto it: us)
        if(it.size() > 0)
            return true;
    return false;
}

int main(){
    vector<int> x(4);
    vector<int> y(4);
    vector<vector<int>> op(16);
    for(int i = 0; i < 16; ++i)
        op[i].resize(16, 0);

    int z, a, b, c;

    while(!in.eof()){
        in >> x[0] >> x[1] >> x[2] >> x[3];
        in >> z >> a >> b >> c;
        in >> y[0] >> y[1] >> y[2] >> y[3];
        test(x, op, z, a, b, c, y);
    }
    int s[16] = {0};
    for(int i = 0; i < 16; ++i){
        for(int j = 0; j < 16; ++j){
            if (op[i][j]) s[i]++;
            cout << op[i][j] << ' ';
        }
        cout << " -- " << s[i] << endl;
    }

    int op_list[16];
    vector<set<int>> us(16);
    for(int i = 0; i < 16; ++i)
        for(int j = 0; j < 16; ++j)
            if (op[i][j])us[i].insert(j);

    while(has_val(us)){
        int val;
        for(int i = 0; i < 16; ++i){
            if(us[i].size() == 1){
                val = *us[i].begin();
                op_list[i] = val;
                break;
            }
        }
        for(int i = 0; i < 16; ++i)
            us[i].erase(val);
    }

    for(int i = 0; i < 16; ++i){
        cout << i << ' ' << op_list[i] << endl;
    }
}


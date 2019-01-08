#include <bits/stdc++.h>
using namespace std;

ifstream in("17.txt");
ofstream out("out.txt");

#define N 2000

char a[N][N];
int mini = INT_MAX, maxi = INT_MIN, minj = INT_MAX, maxj = INT_MIN;

void prep();
void read();
void print();
void spread(int i, int j);
void spring(int i, int j);

int main(){
    read();
    spring(0, 500);
    print();

    int cnt = 0;
    for(int i = mini; i <= maxi; ++i){
        for(int j = minj; j <= maxj; ++j){
            if (a[i][j] == '~')
                cnt++;
        }
    }
    cout << cnt;
}

void spread(int i, int j){
    int l = j, r = j;
    while (a[i + 1][l] != '.' && a[i][l] != '#')
        l--;
    while (a[i + 1][r] != '.' && a[i][r] != '#')
        r++;

    char fil = '~';
    if (a[i][l] != '#' || a[i][r] != '#')
        fil = '|';
    for (int k = l + 1; k < r; ++k)
        if (a[i][k] != '#')
            a[i][k] = fil;
    if (a[i][l] != '#')
        spring(i, l);
    if (a[i][r] != '#')
        spring(i, r);

}

void spring(int i, int j){
    if (i + 1 <= maxi  && i >= 0){
        if(a[i + 1][j] == '|'){
            a[i][j] = '|';
        }
        else{
            if (a[i + 1][j] == '.'){
                a[i][j] = '|';
                spring(i + 1, j);
            }
            else{
                if (a[i + 1][j] == '#')
                    spread(i, j);
            }
            if (a[i + 1][j] == '~')
                spread(i, j);

        }
    }
    else{
        a[i][j] = '|';
    }
}

void prep(){
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            a[i][j] = '.';
        }
    }
}
void read(){
    prep();
    while(!in.eof()){
        char dir;
        in >> dir;
        if (dir == 'x'){
            int x, ys, yf;
            in >> x >> ys >> yf;

            mini = min(mini, ys);
            maxi = max(maxi, yf);
            minj = min(minj, x);
            maxj = max(maxj, x);

            for(int i = ys; i <= yf; ++i){
                a[i][x] = '#';
            }
        }
        else{
            int y, xs, xf;
            in >> y >> xs >> xf;

            mini = min(mini, y);
            maxi = max(maxi, y);
            minj = min(minj, xs);
            maxj = max(maxj, xf);

            for(int j = xs; j <= xf; ++j){
                a[y][j] = '#';
            }
        }
    }
}
void print(){
    for(int i = 0; i < N; ++i){
        for(int j = minj - 1; j < maxj + 1; ++j){
            out << a[i][j];
        }
        out << endl;
    }
}

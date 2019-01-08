#include <bits/stdc++.h>

using namespace std;

bool is_safe(int x , int y, int s){
    return (x + s - 1 <= 300 && y + s - 1 <= 300);
}

int SN = 9995;
long long a[301][301] = {0};

int main(){
    int id, pl;

    for(int y = 1; y <= 300; ++y){
        for(int x = 1; x <= 300; ++x){
            id = x + 10;
            pl = id * y;
            pl += SN;
            pl *= id;
            pl = pl %1000 / 100;
            pl -= 5;
            a[x][y] = pl * 1L;
        }
    }
    long long m = LLONG_MIN;
    int mx, my, ms;
    for(int s = 1; s <= 50; ++s){
        for(int y = 1; y <= 300; ++y){
            for(int x = 1; x <= 300; ++x){
                long long sum = 0;
                if (is_safe(x, y, s)){
                    for(int i = 0; i < s; ++i)
                        for(int j = 0; j < s; ++j)
                            sum += a[x + i][y + j];
                    if (sum > m){
                        m = sum;
                        mx = x;
                        my = y;
                        ms = s;
                    }
                }
            }
        }
    }
    cout << mx << ' ' << my << ' ' << ms << ' ' << m;
}

#include <bits/stdc++.h>

using namespace std;

int a[10000][10000] = {0};

int main(){
    ifstream in("3.txt");
    ofstream out("out.txt");

    int x, y, n, m;
    while(!in.eof()){
        in >> x >> y >> n >> m;
        for(int i = y; i < y + m; ++i)
            for(int j = x; j < x + n; ++j)
                a[i][j]++;
    }

    int cnt = 1;
    in.close();

    in.open("3.txt");

    while(!in.eof()){
        in >> x >> y >> n >> m;
        bool found = true;
        for(int i = y; i < y + m; ++i)
            for(int j = x; j < x + n; ++j)
                if(a[i][j] != 1)
                    found = false;
        if(found){
            out << cnt;
            break;
            }
        cnt++;
    }
}

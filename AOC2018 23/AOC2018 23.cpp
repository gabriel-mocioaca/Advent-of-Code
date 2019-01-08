#include <bits/stdc++.h>
using namespace std;

ifstream in("23.txt");

struct point{
    long long x, y, z, r;
};

int main(){
    vector<point> p;
    point maxp;
    long long maxr = LLONG_MIN;

    while(!in.eof()){
        point cur;
        in >> cur.x >> cur.y >> cur.z >> cur.r;

        if (cur.r > maxr){
            maxr = cur.r;
            maxp = cur;
        }
        p.push_back(cur);
    }

    int cnt = 0;
    for (auto it : p){
        long long d = 0;

        d += abs(it.x - maxp.x);
        d += abs(it.y - maxp.y);
        d += abs(it.z - maxp.z);
        if(d <= maxp.r)
            cnt++;
    }

    cout << cnt;
}


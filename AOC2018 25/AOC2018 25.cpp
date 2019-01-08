#include <bits/stdc++.h>
using namespace std;

ifstream in("25.txt");
ofstream out("out.txt");

struct point{
    int x, y, z, w;
    point(int x, int y, int z, int w){
        this->x = x;
        this->y = y;
        this->z = z;
        this->w = w;
    }
};

int dist(point a, point b){
    //cout << abs(a.x - b.x) + abs(a.y - b.y) + abs(a.z - b.z) + abs(a.w - b.w) << '\n';
    return abs(a.x - b.x) + abs(a.y - b.y) + abs(a.z - b.z) + abs(a.w - b.w);
}

vector<point> v;
vector<vector<int>> g(1010);
vector<bool> visited(2000, false);

int dfs(int node) {
    int visCount = 1;
    visited[node] = true;
    for (auto neighbour: g[node]) {
        if (!visited[neighbour]) {
            visCount += dfs(neighbour);
        }
    }
    return visCount;
}


int main(){
    int x, y, z, w;
    while(!in.eof()){
        in >> x >> y >> z >> w;
        v.push_back(point(x,y,z,w));
    }

    for(int i = 0; i < v.size();++i){
        for(int j = 0; j < v.size(); ++j){
            if((i != j) && (dist(v[i],v[j]) <= 3)){
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }
    int sum = 0, cnt = 0;
    for(int i = 0; i < v.size(); ++i){
        cout << i << ':';
        for(auto it : g[i])
            cout << it << ' ';
        cout << endl;
    }
    for(int i = 0; i < v.size(); ++i){
        if(!visited[i]){
            cout << dfs(i) << '\n';
            cnt++;
        }
    }
    cout << cnt;
}

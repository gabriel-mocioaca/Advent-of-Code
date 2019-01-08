#include <bits/stdc++.h>

using namespace std;

ifstream in("in.txt");
ofstream out("out.txt");

int depth = 3879;
int tx = 713, ty = 8;
int m = 20183;
int fx = 999, fy = 999;
long long a[1000][1000];

struct node{
    int x, y;
    int item;
    // 0 = can't be used in rocks
    // 1 = can't be used in wet
    // 2 =  can't be used in narrow
    int dist;
};

struct comp{
    bool operator () (node a, node b){
        return a.dist > b.dist;
    }
};

int dp[1000][1000][3];
bool vis[1000][1000][3];

int row[] = {0, 1, 0, -1};
int col[] = {-1, 0, 1, 0};

int main(){
    for (int i = 0; i <= fx; ++i){
        for (int j = 0; j <= fy; ++j){
            a[j][i] = 0;
        }
    }
    for (int i = 0; i <= fx; ++i){
        for (int j = 0; j <= fy; ++j){
            long long val = 0;
            if ((j == 0 && i == 0) || (i == tx && j == ty)){
                a[i][j] = (0 + depth) % m;
            }
            else{
                if(j == 0){
                    val = ((48271 * i) + depth) % m;
                    a[i][j] = val;
                }
                else{
                    if(i == 0){
                        val = ((16807 * j) + depth) % m;
                        a[i][j] = val;
                    }
                    else{
                        val = ((a[i - 1][j] * a[i][j-1]) + depth) % m;
                        a[i][j] = val;
                    }
                }
            }
        }
    }
    for (int i = 0; i <= fx; ++i){
        for (int j = 0; j <= fy; ++j){
            if(a[i][j] % 3 == 0)
                a[i][j] = 0;
            else{
                if(a[i][j] % 3 == 1)
                    a[i][j] = 1;
                else{
                    if(a[i][j] % 3 == 2)
                        a[i][j] = 2;
                }
            }
        }
    }
    int sum = 0;
    for (int i = 0; i <= tx; ++i)
        for (int j = 0; j <= ty; ++j)
            sum += a[i][j];
    cout << sum << "\n\n";

    node start;
    start.x = 0;
    start.y = 0;
    start.item = 1;
    start.dist = 0;

    priority_queue<node, vector<node>, comp> pq;

    pq.push(start);

    while(!pq.empty() && !vis[tx][ty][1]){
        node nod = pq.top();
        pq.pop();

        if(vis[nod.x][nod.y][nod.item]){
            continue;
        }
        vis[nod.x][nod.y][nod.item] = true;
        dp[nod.x][nod.y][nod.item] = nod.dist;

        for (int k = 0; k < 4; ++k){
            node next;
            next.x = nod.x + row[k];
            next.y = nod.y + col[k];
            next.item = nod.item;
            next.dist = nod.dist + 1;
            if (next.x >= 0 && next.y >= 0 && next.x < 1000 && next.y < 1000 && a[next.x][next.y] != next.item && !vis[next.x][next.y][next.item]){
                pq.push(next);
            }
        }

        for (int k = 0; k < 3; ++k){
            node next;
            next.x = nod.x;
            next.y = nod.y;
            next.item = k;
            next.dist = nod.dist + 7;
            if (a[next.x][next.y] != next.item && !vis[next.x][next.y][next.item]){
                pq.push(next);
            }
        }
    }
    cout << dp[tx][ty][1];
}

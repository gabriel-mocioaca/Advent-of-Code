#include <bits/stdc++.h>

using namespace std;

ifstream in("6.txt");
ofstream out("out.txt");

int a[400][400];

int main(){
    vector<pair<int,int>> points;
    string s;
    int x, y;

    int min_x = 1000, max_x = -1, min_y = 1000, max_y = -1;

    while(!in.eof()){
        in >> y >> x;
        min_x = min(min_x, x);
        max_x = max(max_x, x);
        min_y = min(min_y, y);
        max_y = max(max_y, y);
        points.push_back({x, y});
    }

    int dist;
    int cnt = 0;
    int n = points.size();
    for(int i = min_x; i <= max_x; ++i){
        for(int j = min_y; j <= max_y; ++j){
            int sum = 0;
            for(int it = 0; it < n; ++it){
                dist = abs(i - points[it].first) + abs(j - points[it].second);
                sum += dist;
            }
            if(sum < 10000)
                cnt++;
        }
    }

    out << cnt;

}

#include <bits/stdc++.h>

using namespace std;

ifstream in("10.txt");
ofstream out("out.txt");

int seconds = 10105;

class Point{
public:
    int x, y;
    int vel_x, vel_y;

    void mov(int time){
        this->x += this->vel_x * time;
        this->y += this->vel_y * time;
    }
    Point(int x, int y, int vel_x, int vel_y){
        this->x = x;
        this->y = y;
        this->vel_x = vel_x;
        this->vel_y = vel_y;
    }
};

int minx = INT_MAX, miny = INT_MAX, maxx = INT_MIN, maxy = INT_MIN;
vector<Point> v;

void up(int time){
    for(auto it = v.begin(); it != v.end(); ++it){
        (*it).mov(time);
        minx = min(minx, (*it).y);
        miny = min(miny, (*it).x);
        maxx = max(maxx, (*it).y);
        maxy = max(maxy, (*it).x);
    }
}

void afis(){
    for(int i = minx; i <= maxx; ++i){
        for(int j = miny; j <= maxy; ++j){
            bool okey = false;
            for(auto it : v){
                if(it.x == j && it.y == i){
                    okey = true;
                    break;
                }
            }
            if(okey)
                out<< '#';
            else
                out << ' ';
        }
        out << "\n\n";
    }
}

int main(){
    int x, y, vel_x, vel_y;
    while(!in.eof()){
        in >> x >> y >> vel_x >> vel_y;
        v.push_back(Point(x, y, vel_x, vel_y));
    }


    up(seconds);

    int p = 0;
    for(auto it : v){
        cout << ++p << ' ' << it.x << ' ' << it.y << '\n';
    }
    cout << v.size();
    afis();
}

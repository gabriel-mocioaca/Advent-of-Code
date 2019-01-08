#include <bits/stdc++.h>

using namespace std;

ifstream in("13.txt");
ofstream out("out.txt");

vector<string> a(150);
vector<string> b(150);

class cart{
public:
    int x, y;
    int dir;
    int sw;
    bool ig;

    cart(int x, int y, int dir){
        this->x = x;
        this->y = y;
        this->dir = dir;
        this->sw = 0;
        this->ig = false;
    }

    void mov(){
        if(dir == 1){
            y = y + 1;
        }
        if(dir == 2){
            x = x + 1;
        }
        if(dir == 3){
            y = y - 1;
        }
        if(dir == 4){
            x = x - 1;
        }

        if(a[x][y] == '/'){
            if (dir == 1){
                dir = 4;
            }else
                if (dir == 2){
                    dir = 3;
                }else
                    if (dir == 3){
                        dir = 2;
                    }else
                        if (dir == 4)
                            dir = 1;
        }
        else{
            if(a[x][y] == '\\'){
                if (dir == 1) dir = 2;
                else if (dir == 2) dir = 1;
                     else if (dir == 3) dir = 4;
                          else if (dir == 4) dir = 3;
            }
            else{
                if(a[x][y] == '+'){
                    if(dir == 1){
                        if(sw == 0) dir = 4;
                        if(sw == 2) dir = 2;
                    }
                    else{
                        if(dir == 2){
                            if(sw == 0) dir = 1;
                            if(sw == 2) dir = 3;
                        }
                        else{
                            if(dir == 3){
                                if(sw == 0) dir = 2;
                                if(sw == 2) dir = 4;
                            }
                            else
                                if(dir == 4){
                                    if(sw == 0) dir = 3;
                                    if(sw == 2) dir = 1;
                                }
                        }
                    }
                    sw = (sw + 1) % 3;
                }
            }
        }
    }
    bool const operator< (cart a){
        if(this->x < a.x)
            return true;
        else{
            if(this->x == a.x)
                return this->y < a.y;
        }
        return false;
    }
};

vector<cart> v;

void crash(){
    int n = v.size();
    for(int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i != j && !v[i].ig && !v[j].ig && v[i].x == v[j].x && v[i].y == v[j].y){
                v[i].ig = true;
                v[j].ig = true;
                cout << "crash " << v[i].x << ' ' << v[i].y << '\n';
            }
        }
    }
}

int ignored(){
    int cnt = 0;
    for(auto it : v)
        if (it.ig) cnt++;
    return cnt;
}

int main(){
    string s;
    int r = 0;
    while(!in.eof()){
        getline(in, s);
        a[r++] = s;
    }

    for(int i = 0; i < 150; ++i){
        for(int j = 0; j < 150; ++j){
            if(a[i][j] == '>') v.push_back(cart(i,j,1));
            if(a[i][j] == 'v') v.push_back(cart(i,j,2));
            if(a[i][j] == '<') v.push_back(cart(i,j,3));
            if(a[i][j] == '^') v.push_back(cart(i,j,4));
        }
    }

    for(auto it : v)
            out << it.x << ' ' << it.y << ' ' << it.dir << ' ' << it.sw << '\n';
        out << '\n';

    while(v.size() - ignored() != 1){

        for (auto it = v.begin(); it != v.end(); ++it){
            (*it).mov();
            crash();
        }
        crash();
        for(auto it : v)
            if(!it.ig)
                out << it.x << ' ' << it.y << ' ' << it.dir << ' ' << it.sw << '\n';
        out << '\n';
        sort(v.begin(), v.end());
    }

    for(auto it : v)
        if(!it.ig)
            cout << it.x << ' ' << it.y;
}

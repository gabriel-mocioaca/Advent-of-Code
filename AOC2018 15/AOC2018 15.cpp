#include <bits/stdc++.h>

using namespace std;

ifstream in("in.txt");
ofstream out("out.txt");

#define N 32
int elfdmg = 17;

class unit{
public:
    int x, y;
    int type;
    int hp;

    unit(int x, int y, int type){
        this->x = x;
        this->y = y;
        this->type = type;
        this->hp = 200;
    }

    bool const operator< (unit a){
        if(this->x < a.x)
            return true;
        else{
            if(this->x == a.x && this->y < a.y)
                return true;
        }
        return false;
    }
};

vector<unit> all_units;
vector<string> h;

int no_goblin = 0;
int no_elf = 0;

int row[] = {-1,0,1,0};
int col[] = {0,1,0,-1};

struct node{
    int x, y, dist;
};

bool get_target(unit a, int &tar_x, int &tar_y){
    bool vis[N][N];
    int dis[N][N];
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            dis[i][j] = INT_MAX;
        }
    }
    memset(vis, false, sizeof vis);

    queue<node>q;

    vis[a.x][a.y] = true;
    q.push({a.x,a.y,0});


    while(!q.empty()){
        node nod = q.front();
        q.pop();
        int i = nod.x, j = nod.y, dist = nod.dist;
        dis[i][j] = dist;

        for(int k = 0; k < 4; k++){
            if((h[i + row[k]][j + col[k]] == '.') && !vis[i + row[k]][j + col[k]]){
                vis[i + row[k]][j + col[k]] = true;
                q.push({i + row[k], j + col[k], dist + 1});

            }
        }
    }

    int mindis = INT_MAX;

    bool found = false;

    for(auto it : all_units){
        if(a.type != it.type && it.hp > 0){
            for(int k = 0; k < 4; k++){
                if(h[it.x + row[k]][it.y + col[k]] == '.' && dis[it.x + row[k]][it.y + col[k]] != INT_MAX){
                    found = true;
                    if (dis[it.x + row[k]][it.y + col[k]] < mindis){
                        mindis = dis[it.x + row[k]][it.y + col[k]];
                        tar_x = it.x + row[k];
                        tar_y = it.y + col[k];
                    }
                    else{
                        if (dis[it.x + row[k]][it.y + col[k]] == mindis){
                            if(it.x + row[k] < tar_x){
                                tar_x = it.x + row[k];
                                tar_y = it.y + col[k];
                            }
                            if(it.x + row[k] == tar_x && it.y + col[k] < tar_y){
                                tar_x = it.x + row[k];
                                tar_y = it.y + col[k];
                            }
                        }
                    }
                }
            }
        }
    }
    /*for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++ j){
            if(h[i][j] != '.')
                if(i == a.x && j == a.y)
                    cout << "S ";
                else
                    cout << "  ";
            else
                cout << dis[i][j] << " ";
        }
        cout << endl;
    }*/

    return found;
}

void get_move(int x, int y, unit beg, int &move_x, int &move_y){
    bool vis[N][N];
    int dis[N][N];
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            dis[i][j] = INT_MAX;
        }
    }
    memset(vis, false, sizeof vis);

    queue<node>q;

    vis[x][y] = true;
    q.push({x,y,0});


    while(!q.empty()){
        node nod = q.front();
        q.pop();
        int i = nod.x, j = nod.y, dist = nod.dist;

        dis[i][j] = dist;

        for(int k = 0; k < 4; k++){
            if((h[i + row[k]][j + col[k]] == '.') && !vis[i + row[k]][j + col[k]]){
                vis[i + row[k]][j + col[k]] = true;
                q.push({i + row[k], j + col[k], dist + 1});
            }
        }
    }
    /*for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++ j){
            if(h[i][j] != '.')
                if(i == beg.x && j == beg.y)
                    cout << "S ";
                else
                    cout << "  ";
            else
                cout << dis[i][j] << " ";
        }
        cout << endl;
    }*/

    int mindis = INT_MAX;
    for(int k = 0; k < 4; k++){
        if(h[beg.x + row[k]][beg.y + col[k]] == '.' && dis[beg.x + row[k]][beg.y + col[k]] < mindis){
            mindis = dis[beg.x + row[k]][beg.y + col[k]];
            move_x = beg.x + row[k];
            move_y = beg.y + col[k];
        }
        else{
            if (dis[beg.x + row[k]][beg.y + col[k]] == mindis){
                if(beg.x + row[k] < move_x){
                    move_x = beg.x + row[k];
                    move_y = beg.y + col[k];
                }
                if(beg.x + row[k] == move_x && beg.y + col[k] < move_y){
                    move_x = beg.x + row[k];
                    move_y = beg.y + col[k];
                }
            }
        }
    }

}

unit get_unit(int x, int y){
    for (auto it : all_units)
        if(it.x == x && it.y == y && it.hp > 0)
            return it;
}

bool get_attack(unit a, int &attack_x, int &attack_y){
    bool found = false;
    int min_hp = INT_MAX;
    for(int k = 0; k < 4; ++k){
        if(h[a.x][a.y] != h[a.x + row[k]][a.y + col[k]] && h[a.x + row[k]][a.y + col[k]] != '.' && h[a.x + row[k]][a.y + col[k]] != '#'){
            found = true;
            int u_hp = get_unit(a.x + row[k], a.y + col[k]).hp;
            if (u_hp < min_hp){
                min_hp = u_hp;
                attack_x = a.x + row[k];
                attack_y = a.y + col[k];
            }
            else{
                if (u_hp == min_hp){
                    if(a.x + row[k] < attack_x){
                        attack_x = a.x + row[k];
                        attack_y = a.y + col[k];
                    }
                    if(a.x + row[k] == attack_x && a.y + col[k] < attack_y){
                        attack_x = a.x + row[k];
                        attack_y = a.y + col[k];
                    }
                }
            }
        }
    }
    return found;
}

void damage(int x, int y, int damage){
    cout << "damage " << x << ' ' << y << ' ';
    for(auto it = all_units.begin(); it != all_units.end(); ++it){
        if((*it).x == x && (*it).y == y && (*it).hp > 0){
            (*it).hp -= damage;
            if((*it).hp <= 0){
                cout << "kill ";
                h[x][y] = '.';
                if((*it).type == 1)
                    --no_goblin;
                else
                    --no_elf;
            }
            break;
        }
    }
}

void move_unit(unit &a, int move_x, int move_y){
    cout << "move " << move_x << ' ' << move_y << ' ';
    h[move_x][move_y] = h[a.x][a.y];
    h[a.x][a.y] = '.';
    a.x = move_x;
    a.y = move_y;
}

void action(unit &a){
    cout << "action "<< a.x << ' ' << a.y << ' ';
    int tar_x, tar_y;
    int move_x, move_y;
    int attack_x, attack_y;
    if(get_attack(a, attack_x, attack_y)){
        damage(attack_x, attack_y, a.type == 1 ? 3 : elfdmg);
    }
    else{
        if(get_target(a,tar_x, tar_y)){
            get_move(tar_x, tar_y, a, move_x, move_y);
            move_unit(a, move_x, move_y);
            if(get_attack(a, attack_x, attack_y)){
                damage(attack_x, attack_y, a.type == 1 ? 3 : elfdmg);
            }
        }
    }
    cout << "UNITS "<< no_elf << ' ' << no_goblin <<'\n';
}


int main(){
    string s;
    while(!in.eof()){
        in >> s;
        h.push_back(s);
    }

    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            if(h[i][j] == 'G'){
                all_units.push_back(unit(i,j,1));
                no_goblin++;
            }
            if(h[i][j] == 'E'){
                all_units.push_back(unit(i,j,2));
                no_elf++;
            }
        }
    }
    bool stop = false;

    int rounds  = 0;
    while(no_elf > 0 && no_goblin > 0){
        cout << endl;
        for(auto it = all_units.begin(); it != all_units.end(); ++it){
            if (no_elf == 0 || no_goblin == 0){
                stop = true;
                break;
            }
            if((*it).hp <= 0)
                continue;
            action(*it);
        }
        if(stop)
            break;
        sort(all_units.begin(), all_units.end());
        rounds++;

        cout << rounds << '\n';
        for(auto it : all_units){
            if(it.hp > 0)
                cout << it.hp << ' ';
        }
        cout << endl;
        for(int i = 0; i < N; ++i){
            for(auto j = 0; j < N; ++j){
                cout << h[i][j];
            }
            cout << endl;
        }

    }
    int sum_life = 0;
    for(auto it = all_units.begin(); it != all_units.end(); ++it){
        if((*it).hp > 0){
            cout << (*it).hp << ' ';
            sum_life += (*it).hp;
        }
    }
    cout << "\n\n" << rounds << ' ' << sum_life ;
    cout << " MESAJ " << rounds * sum_life;
}

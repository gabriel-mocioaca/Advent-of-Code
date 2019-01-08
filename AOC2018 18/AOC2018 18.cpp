#include <bits/stdc++.h>

using namespace std;

ifstream in("18.txt");
ofstream out("out.txt");

vector<string> curr;
vector<string> pre;

int col[] = {-1,0,1,-1,1,-1,0,1};
int row[] = {-1,-1,-1,0,0,1,1,1};

bool is_safe(int x, int y){
    return ((x >= 0) && (x < 50) && (y >= 0) && (y < 50));
}

int open = 0;
int lumber = 0;
int tree = 0;

void update(){
    for(int i = 0; i < 50; ++i){
        for(int j = 0; j < 50; ++j){
            if(pre[i][j] == '.'){
                int cnt = 0;
                for(int k = 0; k < 8; k++){
                    if(is_safe(i + row[k], j + col[k]))
                        if(pre[i + row[k]][j + col[k]] == '|')
                            cnt++;
                }
                if(cnt >= 3){
                    curr[i][j] = '|';
                    open -= 1;
                    tree += 1;
                }
                else{
                    curr[i][j] = '.';
                }
            }
            if(pre[i][j] == '|'){
                int cnt = 0;
                for(int k = 0; k < 8; k++){
                    if(is_safe(i + row[k], j + col[k]))
                        if (pre[i + row[k]][j + col[k]] == '#')
                            cnt++;
                }
                if(cnt >= 3){
                    curr[i][j] = '#';
                    tree -=1;
                    lumber +=1;
                }
                else{
                    curr[i][j] = '|';
                }
            }
            if(pre[i][j] == '#'){
                int l = 0;
                int t = 0;
                for(int k = 0; k < 8; k++){
                    if(is_safe(i + row[k], j + col[k]))
                        if(pre[i + row[k]][j + col[k]] == '#')
                            l++;
                    if(is_safe(i + row[k], j + col[k]))
                        if (pre[i + row[k]][j + col[k]] == '|')
                            t++;
                }

                if((l >= 1)  && (t >= 1)){
                    curr[i][j] = '#';
                }
                else{
                    curr[i][j] = '.';
                    lumber -=1;
                    open +=1;
                }

            }
        }
    }
    for(int i = 0; i < 50; ++i)
        for(int j = 0; j < 50; ++j)
            pre[i][j] = curr[i][j];
}

void afis(){
    for(int i = 0; i < 50; ++i){
        for(int j = 0; j < 50; ++j)
            cout << pre[i][j];
        cout << endl;
    }
}

int main(){
    curr.resize(50);
    pre.resize(50);
    for(int i = 0; i < 50; ++i)
        curr[i].resize(50);

    for(int i = 0; i < 50; ++i){
        in >> pre[i];
    }

    for(int i = 0; i < 50; ++i){
        for(int j = 0; j < 50; ++j){
            if(pre[i][j] == '.')
                open++;
            if(pre[i][j] == '|')
                tree++;
            if(pre[i][j] == '#')
                lumber++;
        }
    }

    for (int up = 0; up < 10000; ++up){
        update();
        out << open << ' ' << tree << ' ' << lumber << ' ' << tree * lumber << '\n';
    }

}

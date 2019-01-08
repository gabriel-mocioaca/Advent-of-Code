#include <string>
#include <iostream>
#include <fstream>
using namespace std;

ifstream in("20.txt");
ofstream out("out.txt");
#define N 1000

int minx = N/2, maxx = N/2, miny = N/2, maxy = N/2;

int a[N][N];

int row[] = {-1, 0 , 1, 0};
int col[] = {0, 1 , 0, -1};

void update(int &x, int &y, char d){
    int k, nx, ny;
    if (d == 'N') k = 0;
    if (d == 'E') k = 1;
    if (d == 'S') k = 2;
    if (d == 'W') k = 3;

    nx = x + row[k];
    ny = y + col[k];

    a[nx][ny] = min(a[nx][ny], a[x][y] + 1);

    x = nx;
    y = ny;

    minx = min(x, minx);
    maxx = max(x, maxx);
    miny = min(y, miny);
    maxy = max(y, maxy);
}

void break_in_smaller(string s, int x, int y) {
    int i, j, k, cnt;

    for (i = 0; i < s.size(); ++i){
        if (s[i] == '(')
            break;
        update(x, y, s[i]);
    }
    if (i == s.size())
        return;

    cnt = 1;
    for (j = i + 1; j < s.size(); ++j){
        if(cnt == 0)
            break;
        if (s[j] == '(') cnt++;
        else if (s[j] == ')') cnt--;
    }
    j--;

    string sub = s.substr(i + 1, j - i - 1);

    while (1){
        cnt = 0;
        for(k = 0 ; k < sub.size(); ++k){
            if(sub[k] == '(')
                cnt++;
            else
                if(sub[k] == ')')
                    cnt--;
                else
                    if (sub[k] == '|' && cnt == 0)
                        break;
        }
        break_in_smaller(sub.substr(0, k), x, y);
        if (k == sub.size())
            break;
        else
            sub = sub.substr(k + 1);
    }
    if (j < s.size()){
        break_in_smaller(s.substr(j + 1), x, y);
    }
}

void init(){
    for(int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            a[i][j] = 9999;
}

int main() {
	string s;
	in >> s;
    s = s.substr(1, s.size() - 2);
    init();
    a[N/2][N/2] = 0;

	break_in_smaller(s, N/2, N/2);

    int cnt = 0;

    for(int i = minx; i <= maxx; ++i){
        for(int j = miny; j <= maxy; ++j){
            if(a[i][j] >= 1000)
                cnt++;
        }
    }
    cout << cnt;

	return 0;
}

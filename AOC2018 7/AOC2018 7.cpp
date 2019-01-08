#include <bits/stdc++.h>
using namespace std;

ifstream in("17.txt");

vector<vector<int>> g(26);
vector<int> in_dg(26, 0);
map<char,set<char>> before;

void read(){
    string s;
    int x, y;
    while(!in.eof()){
        getline(in, s);
        x = (int)(s[5] - 'A');
        y = (int)(s[36] - 'A');
        g[x].push_back(y);
        in_dg[y]++;
        before[s[36]].insert(s[5]);
    }
}

string top_sort(){
    string s;
    vector<bool> checked(26, false);
    while(s.size() < 26){
        for(int i = 0; i < 26; ++i){
            if(!checked[i] && in_dg[i] == 0){
                checked[i] = true;
                s.push_back('A' + i);
                for(auto neigh : g[i])
                    in_dg[neigh]--;
                break;
            }
        }
    }
    return s;
}

struct strung{
    vector<int> times;
    vector<char> ac;

    strung(){
        this->times.resize(5, 0);
        this->ac.resize(5, ' ');
    }

    int free_space(){
        int cnt = 0;
        for(int i = 0; i < 5; ++i){
            if(times[i] == 0)
                cnt++;
        }
        return cnt;
    }

    bool add(char x){
        if((free_space() >= 1) && (before[x].size() == 0)){
            int i;
            for(i = 0; i < 5; ++i){
                if(times[i] == 0)
                    break;
            }
            times[i] = 61 + x - 'A';
            ac[i] = x;
            return true;
        }
        return false;
    }
    int del(){
        int min_val = INT_MAX;
        for(int i = 0; i < 5; ++i){
            if(times[i] < min_val && times[i] > 0){
                min_val = times[i];
            }
        }
        for(int i = 0; i < 5; ++i){
            if(times[i])
                times[i] -= min_val;
            if (times[i] == 0 && ac[i] != ' '){
                for(auto it = before.begin(); it != before.end(); ++it){
                    ((*it).second).erase(ac[i]);
                }
                ac[i] = ' ';
            }
        }
        return (min_val == INT_MAX ? 0 : min_val);
    }
};

int main(){
    read();
    string s;

    s = top_sort();
    cout << s << endl;

    strung st;
    int cnt = 0;
    vector<bool> vis(26, false);
    while(1){
        bool ok = false;
        for(int i = 0; i < 26; ++i){
            if(!vis[i]){
                ok = true;
                if(st.add(s[i])){
                    vis[i] = true;
                }
            }
        }
        int x = st.del();
        cnt += x;;

        if(!ok)
            break;
    }

    cout << cnt;
}

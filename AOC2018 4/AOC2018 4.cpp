#include <bits/stdc++.h>
#include <fstream>
using namespace std;

map<int,vector<int>> m;
map<int, int> slept;
ifstream in("4.txt");
ofstream out("out.txt");

int main(){
    string s;
    int id;
    bool f = false, w = false;
    while(!in.eof()){
        getline(in, s);
        int sleep_time;
        int wake_time;
        if(s[19] == 'G'){
            id = stoi(s.substr(26, 3 + (s[29] != ' ')));
            m[id].resize(70);
        }
        if(s[19] == 'f'){
            sleep_time = stoi(s.substr(15, 2));
            f = true;
        }
        if(s[19] == 'w'){
            wake_time = stoi(s.substr(15, 2));
            w = true;
        }
        if(f && w){
            for(int i = sleep_time; i < wake_time; ++i)
                m[id][i]++;
            slept[id] += wake_time - sleep_time;
            f = w = false;
        }
    }

    int max_s = -1;
    int max_id;

    max_s = -1;
    int minute;

    for(auto it: m){
        for(int i = 0; i < 60; ++i){
            if(it.second[i] > max_s){
                max_id = it.first;
                minute = i;
                max_s = it.second[i];
            }
        }
    }
    out << max_id * minute;
}

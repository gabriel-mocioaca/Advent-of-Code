#include <bits/stdc++.h>

using namespace std;

ifstream in("5.txt");

int main(){
    string x;
    string s;

    in >> x;

    bool found = true;
    int m = 2000000;
    for(char pol = 'A'; pol <= 'Z'; ++pol){
        s = x;
        found = true;
        while(found){
            found = false;
            for(int i = 0; i < s.size(); ++i){
                if (s[i] == pol || s[i] == pol + 32){
                    s.erase(i,1);
                    found = true;
                }
            }
        }

        found = true;
        while(found){
            found = false;
            for(int i = 0; i < s.size() - 1; ++i){
                if(s[i] == s[i+1] + 32 || s[i] == s[i+1] - 32){
                    s.erase(i,2);
                    found = true;
                }
            }
        }
        m = (m < s.size() ? m : s.size());
    }
    cout << m;
}

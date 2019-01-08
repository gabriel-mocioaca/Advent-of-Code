#include <fstream>
#include <unordered_map>
#include <vector>

using namespace std;

fstream in("1.txt");
ofstream out("out.txt");

int main(){
    vector<int> v;
    unordered_map<int,bool> m;

    long long sum = 0;
    int x;
    m[0] = true;
    bool found = false;
    while(in>>x){
        v.push_back(x);
        sum += x;
        if(m[sum]==true){
            found = true;
            break;
        }
        else
            m[sum] = true;
    }
    while(!found)
        for(auto it : v){
            sum += it;
            if(m[sum]==true){
                found = true;
                break;
            }
            else
                m[sum] = true;
        }

    out << sum;
}

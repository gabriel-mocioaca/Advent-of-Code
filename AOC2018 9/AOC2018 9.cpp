#include <bits/stdc++.h>

using namespace std;

ofstream out("out.txt");

int n = 419;
int x = 7216400;

vector<long long> sum(420, 0);
list<int> ord;

std::list<int>::iterator prev(std::list<int>::iterator it){
    if(it == ord.begin())
        return ord.end();
    return --it;
}

std::list<int>::iterator next(std::list<int>::iterator it){
    if(it == ord.end())
        return ord.begin();
    return ++it;
}

int main(){
    std::list<int>::iterator curr = ord.begin();
    for (int i = 1; i < x; ++i) {
            if (i % 23 == 0) {
                curr = prev(prev(prev(prev(prev(prev(prev(curr)))))));
                sum [i % n] += i + *curr;
            curr = ord.erase(curr);
            } else {
            curr = ord.insert(next(next(curr)), i);
            }
        }
    out << *max_element(sum.begin(), sum.end());
}

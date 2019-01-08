#include <bits/stdc++.h>

using namespace std;

int n = 880751;
list<int> l;
list<int> check;

std::list<int>::iterator next(std::list<int>::iterator it){
    if(it == --l.end())
        return l.begin();
    return ++it;
}

std::list<int>::iterator next_pos(std::list<int>::iterator it, int pos){
    for(int i = 0; i < pos; ++i)
        it = next(it);

    return it;
}

void add_to_check(int x){

    if (check.size() < 6)
        check.push_back(x);
    else{
        check.pop_front();
        check.push_back(x);
    }
}

bool check_vals(){
    int val = 0;
    for(auto it : check){
        val = val * 10 + it;
    }
    if (val == n)
        return true;

    return false;
}

int main(){
    l.push_back(3);
    l.push_back(7);
    add_to_check(3);
    add_to_check(7);
    std::list<int>::iterator rec1 = (l.begin());
    std::list<int>::iterator rec2 = (++l.begin());


    for(int i = 0; i < 25000000; ++i){
        int sum = *rec1 + *rec2;
        if(sum >= 10){
            l.push_back(sum/10);
            add_to_check(sum/10);
            if(check_vals())
                break;

            l.push_back(sum%10);
            add_to_check(sum%10);
            if(check_vals())
                break;
        }
        else{
            l.push_back(sum);
            add_to_check(sum);
            if(check_vals())
                break;
        }

        rec1 = next_pos(rec1, (*rec1 + 1) % l.size());
        rec2 = next_pos(rec2, (*rec2 + 1) % l.size());

    }

    cout << l.size() - 6;

}

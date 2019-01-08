#include <iostream>
using namespace std;

int main(){
    int a = 0;
    int b = 10551300;
    for(int i = 1; i <= b; ++i){
        if(b % i == 0)
            a += b / i;
    }

    cout << a;
}

#include <iostream>
using namespace std;

string tiangan[] = {"geng","xin","ren","gui","jia","yi","bing","ding","wu","ji"};
string dizhi[] = {"zi","chou","yin","mao","chen","si","wu","wei","shen","you","xu","hai"};

int main(){
    int n;
    cin >> n;
    if(n >= 40){
        n -= 40;
        n %= 60;
        int x = n % 10;
        int y = n % 12;
        cout << tiangan[x] << dizhi[y];
    }
    else{
        n += 20;
        int x = n % 10;
        int y = n % 12;
        cout << tiangan[x] << dizhi[y];
    }
    return 0;
}
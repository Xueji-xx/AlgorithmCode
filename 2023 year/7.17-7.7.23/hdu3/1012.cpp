#include <iostream>
using namespace std;

void dfs(int a,int b){
    cout << a << ' ' << b << endl;
    if(a > b)dfs(a - b,b);
    if(b > a)dfs(a,b - a);
}


int main(){
    int a,b;
    cin >> a >> b;
    dfs(a,b);
    return 0;
}
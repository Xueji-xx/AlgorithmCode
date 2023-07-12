#include <iostream>
using namespace std;

int ary[13];
bool check(int n){
    if(!(n % 400) || (!(n % 4) && ( n % 100)))return true;
    return false;
}

int main(){
    for(int i = 1;i <= 12;i ++)ary[i] = 30;
    for(auto i : {1,3,5,7,8,10,12})ary[i] = 31;
    ary[2] = 28;
    int y,m,d;
    cin>>y>>m>>d;
    m = -m;
    d = -d;
    //cout<<y<<m<<d;
    if(check(y)){
        cout<<366<<' ';
        ary[2]++;
    }
    else cout<<365<<' ';
    cout<<ary[m]<<' ';
    int sum = 0;
    for(int i = 1;i < m;i ++)sum += ary[i];
    for(int i = 1;i < d;i ++)sum ++;
    cout<<sum+1<<' ';
    for(int i = 1;i < y;i ++){
        sum += 365 + check(i);
        sum %= 7;
    }
    cout<<sum+1<<endl;
    return 0;
}

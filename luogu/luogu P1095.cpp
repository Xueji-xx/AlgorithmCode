#include<iostream>
using namespace std;
const int N = 1e8+50;
int f[N];

int main(){
    int m,s,t;
    cin>>m>>s>>t;
    //v = 17,value = 10, m初始魔法值,
    f[0] = 0;
    for(int i = 1;i <= t;i ++){
        if(m >= 10){
            f[i] = f[i-1] + 60;
            m -= 10;
        }
        else{
            f[i] = f[i-1];
            m += 4;
        }
    }
    for(int i = 1;i <= t;i ++){
        if(f[i] < f[i-1] + 17)f[i] = f[i-1] + 17;
        if(f[i] >= s){
            cout<<"Yes"<<endl;
            cout<<i<<endl;
            system("pause");
            return 0;
        }
    }
    cout<<"No"<<endl;
    cout<<f[t]<<endl;
    system("pause");
    return 0;
}
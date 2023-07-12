#include<iostream>
#define endl '\n'
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n,m;
    cin>>n>>m;
    if(!(n & 1) && !(m & 1))cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;
        if(n & 1){
            int x = 1;
            while(x <= n){
                if(x & 1){
                    for(int i = 1;i <= m;i ++){
                        if(i == 1 && x == 1)continue;
                        if(i == m && x == n)continue;
                        cout<<x<<' '<<i<<endl;
                    }
                }
                else{
                    for(int i = m;i >= 1;i --)cout<<x<<' '<<i<<endl;
                }
                x++;
            }
        }
        else{
            int x = 1;
            while(x <= m){
                if(x & 1){
                    for(int i = 1;i <= n;i ++){
                        if(i == 1 && x == 1)continue;
                        if(i == n && x == m)continue;
                        cout<<i<<' '<<x<<endl;
                    }
                }
                else{
                    for(int i = n;i >= 1;i --)cout<<i<<' '<<x<<endl;
                }
                x++;
            }
        }
    }
    system("pause");
    return 0;
}
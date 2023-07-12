#include<iostream>
using namespace std;

void solve(){
        int n,b,x,y;
        int k = n;
        cin>>n>>b>>x>>y;
        long long sum = 0;
        int a = 0;
        for(int i = 0;i <= n;i ++){
            sum += a;
            if(a + x > b){
                a -= y;
            }
            else a += x;
        }
        cout<<sum<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
    system("pause");
    return 0;
}
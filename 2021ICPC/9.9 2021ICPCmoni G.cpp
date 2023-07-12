#include<iostream>
using namespace std;
int cnt[] = {0,1,3};
#define int long long

signed main(){
    int n;
    cin>>n;
    if(n <= 3)cout<<n*2+1<<endl;
    else{
        int x = (n-4)%3;
        int y = (n-4)/3;
        int sum = 8 + 4*y;  
        cout<<sum + cnt[x]<<endl;
    }
    system("pause");
    return 0;
}
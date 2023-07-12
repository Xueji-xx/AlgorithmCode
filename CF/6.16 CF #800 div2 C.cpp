#include<iostream>
using namespace std;
#define inf 0x3f3f3f3f
#define ll long long
#define M 1000005
int T,n;
int a[M];
string solve(){
    ll sum=0;
    for(int i = 1;i <= n;i ++){
        sum+=a[i];
        if(sum<1&&i!=n) return "NO";
    }
    if(sum==0) return "YES";
    return "NO";
}
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        for(int i = 1;i <= n;i ++)cin>>a[i];
        while(a[n]==0) n--;
        cout<<solve()<<endl;
    }
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
const int mod=1e9+7;
const int N=1e5+5;
int t,n,k;
int fact[N],infact[N];

int pmod(int a,int b){
	int res=1;
	while(b){
		if(b&1) res=res*a%mod;
		b>>=1;
		a=a*a%mod;
	}
	return res;
}

void init(){
	fact[0]=infact[0]=1;
	for(int i=1;i<=N-3;i++){
		fact[i]=fact[i-1]*i%mod;
		infact[i]=infact[i-1]*pmod(i,mod-2)%mod;
	}
}

int C(int n,int x){
    return fact[n]*infact[n-x]%mod*infact[x]%mod;
}

signed main(){
    cin>>n>>k;
    init();
    long long ans = 0;
    for(int i = 0;i <= min(n,k);i ++){
        ans = (ans + C(n,i))%mod;
    }
    cout<<ans<<endl;
    system("pause");
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e6+10;
ll a[N];
void solve()
{
	int n;
	scanf("%d",&n);
	int flg=0,vis=0;
	ll ans=0,minn=1e18+1;
	if(n==1)
	{
		scanf("%lld",&a[0]);
		printf("%lld\n",a[0]);
		return ;
	}
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
		ans+=abs(a[i]);
		minn=min(minn,abs(a[i])); 
		if(a[i]>0) flg=1;
		if(a[i]<0) vis=1;
	}
	if(vis+flg==2)
	{
	printf("%lld\n",ans);
	return ;	
	}	
	ans-=2*minn;
	printf("%lld\n",ans);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		solve();
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool f[105][200005];
int a[105];
int main()
{
	int n,m=0;
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i],m+=a[i];
	f[0][m]=1;
	//1.负数可能发生的越界，允许出现暂时的负数 
	int lit=2*m;
	for(int i=1;i<=n;i++)
		for(int j=0;j<=lit;j++)
		{
			f[i][j]=f[i-1][j];
			if(f[i][j]) continue;
			if(j-a[i]>=0) f[i][j]|=f[i-1][j-a[i]];
			if(j+a[i]<=lit) f[i][j]|=f[i-1][j+a[i]];
		}
	int ans=0;
	//2.组合出的数必须是正数 
	for(int i=m+1;i<=lit;i++) ans+=f[n][i];
	cout<<ans;
    return 0;
}


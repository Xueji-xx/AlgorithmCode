#include<bits/stdc++.h>
#define endl '\n'
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N = 1e5 + 10;

void solve()
{
	int n;
	int s = 0;
	cin >> n;
	vector<int>a(n);
	for(auto &x : a)
	{
		cin >> x;
		s ^= x;
	}
	if(!s)
	{
		cout << 0 << endl;
		return;
	}
	
	int pos = 0;
	for(int i = 20; i >= 0; i --)
	{
		if(s >> i & 1)
		{
			pos = i;
			break;
		}
	}
	int k = 0;
	for(int i = 0; i < n; i ++ )
		if(a[i] >> pos & 1)
			k ++;
	
	if(k == 1)
	{
		cout << 1 << endl;
		return;
	}

	if((n - k) % 2)
	{
		cout << -1 << endl;
	}

	else
	{
		cout << 1 << endl;
	}
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while(t--)
	solve();
}


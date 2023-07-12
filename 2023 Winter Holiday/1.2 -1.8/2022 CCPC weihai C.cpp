#include <iostream>
using namespace std;
#define int long long
const int N=25010;
int a[N],b[N];
#define endl '\n'

bool check(int x1,int y1,int x2,int y2,int x3,int y3,int x4,int y4,int x5,int y5){
	if((x2-x1)*(y3-y1)!=(x3-x1)*(y2-y1)) return false;//其中两个斜率不同，肯定就不全共线了
	if((x2-x1)*(y4-y1)!=(x4-x1)*(y2-y1)) return false;
	if((x2-x1)*(y5-y1)!=(x5-x1)*(y2-y1)) return false;
	return true;
}

bool on(int x1,int y1,int x2,int y2,int x3,int y3){
    int maxx,minx,maxy,miny;
    maxx = max(x1,x2);
    minx =  min(x1,x2);
    maxy = max(y1,y2);
    miny = min(y1,y2);
    if(!(x3>=minx&&x3<=maxx&&y3>=miny&&y3<=maxy)) return false;//超出线段范围肯定就不在线段上了 
    if((x3-x1)*(y2-y1)==(x2-x1)*(y3-y1)) return true; 
    return false;
}


void solve()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
	if(n<5){
		cout<<"NO"<<endl;
		return;
	}
	int x1=a[1],y1=b[1];
	int x2=a[2],y2=b[2];
	int x3=a[3],y3=b[3];
	int x4=a[4],y4=b[4];
	for(int i=5;i<=n;i++){
		int x5=a[i],y5=b[i];
		if(!check(x1,y1,x2,y2,x3,y3,x4,y4,x5,y5)){
			cout<<"YES"<<endl;
			int x[8]={x1,x2,x3,x4,x5};
			int y[8]={y1,y2,y3,y4,y5};
			for(int j=0;j<5;j++){
				int f=1;//标记这个点是否能是中心点 
				for(int z=0;z<5;z++){
					if(z==j) continue;
					for(int p=0;p<5;p++){
						if(p==z||p==j) continue;
						if(on(x[j],y[j],x[z],y[z],x[p],y[p])){
							f=0;
							break;
						}
					}
					if(!f) break;
				}
					if(f){
						cout<<x[j]<<' '<<y[j]<<endl;
						for(int p=0;p<5;p++){
							if(p!=j) cout<<x[p]<<' '<<y[p]<<endl;
						}
						return;
					}
			}
		}
	}
	cout<<"NO"<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}
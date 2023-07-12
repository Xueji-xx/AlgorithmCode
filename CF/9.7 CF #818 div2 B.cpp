#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505;
int t,n,k,r,c;
char s[N][N];
    
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n>>k>>r>>c;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                s[i][j]='.';
            }
        }
        for(int i=0;i+r<=n;i++){
            int x=i+r,y=c-i;
            for(int j=y;j<=n;j+=k){
                if(j>=1) s[x][j]='X';
            }
            for(int j=y;j>=1;j-=k){
                if(j<=n) s[x][j]='X';
            }
        }
        for(int i=1;r-i>=1;i++){
            int x=r-i,y=c+i;
            for(int j=y;j<=n;j+=k){
                if(j>=1) s[x][j]='X';
            }
            for(int j=y;j>=1;j-=k){
                if(j<=n) s[x][j]='X';
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cout<<s[i][j];
            }
            cout<<endl;
        }
    }
    system("pause");
    return 0;
}
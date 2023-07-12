#include<iostream>
using namespace std;
const int N = 110;
int fr[N],fl[N],a[N],n;

void solve(){
    cin>>n;
    for(int i = 1;i <= n;i ++)cin>>a[i];
    for(int i = 0;i < N;i ++)fr[i] = 1,fl[i] = 1;
    for(int i = 2;i <= n;i ++){
        for(int j = 1;j < i;j ++){
            if(a[j] < a[i]){
                fr[i] = max(fr[i],fr[j]+1);
            }
        }
    }
    for(int i = 2;i <= n;i ++){
        for(int j = n;j > i;j --){
            if(a[j] < a[i]){
                fl[i] = max(fl[i],fl[j]+1);
            }
        }
    }
    int maxm = -1;
    for(int i = 1;i <= n;i ++)maxm = max(maxm,max(fr[i],fl[i]));
    cout<<maxm<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}
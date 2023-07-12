#include <iostream>
#include <map>
using namespace std;

void solve(){
    int n,m,d;
    cin>>n>>m>>d;
    map<int,int> p;
    for(int i = 1;i <= n;i ++){
        int x;
        cin>>x;
        p[x] = i;
    }
    int a[m+10];
    for(int i = 1;i <= m;i ++){
        cin>>a[i];
    }
    bool flag = false;
    int minn = 99999999;
    for(int i = 1;i < m;i ++){
        if(p[a[i]] < p[a[i+1]] && p[a[i+1]] <= p[a[i]] + d){
            //cout<<p[a[i+1]]<<' '<<p[a[i]]<<endl;
            
            minn = min(p[a[i+1]] - p[a[i]],minn);
            //cout<<minn<<endl;
            int x = p[a[i]] + d - p[a[i+1]] + 1;
            if(p[a[i]] - 1 + n - p[a[i+1]] >= x){
                minn = min(x,minn);
            }
        }
        else{
            flag = true;
            break;
        }
    }
    if(flag){
        cout<<0<<endl;
    }
    else{
        cout<<minn<<endl;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}
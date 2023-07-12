#include <iostream>
#include <map>
using namespace std;
string a,b;
int n,k;
int ans = 0;
map<char,int> vis;

int cal(int x){
    int sum = 0;
    while(x){
        sum += x--;
    }
    return sum;
}

void dfs(int p,int t,int len,int res){
    //cout<<2<<endl;
    if(p == n+1){
        //cout<<len<<endl;
        int x = cal(len);
        //cout<<x<<endl;
        x += res;
        ans = max(ans,x);
        return;
    }
    if(a[p] == b[p]){
        dfs(p+1,t,len+1,res);
    }
    if(a[p] != b[p]){
        if(t && !vis[a[p]]){
            vis[a[p]]++;
            dfs(p+1,t-1,len+1,res);
            vis[a[p]]--;
        }
        else if(t){
            dfs(p+1,t,len+1,res);
        }
        else{
            //cout<<1<<endl;
            int x = cal(len);
            dfs(p+1,t,0,x);
        }
    }
}

void solve(){
    cin>>n>>k;
    cin>>a>>b;
    vis.clear();
    a = '1' + a;
    b = '1' + b;
    if(a == b){
        cout<<cal(n)<<endl;
        return;
    }
    dfs(1,k,0,0);
    cout<<ans<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}
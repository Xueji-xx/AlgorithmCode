#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;

const int N = 1e5+50;
vector<int> a;
typedef struct{
    int x;
    int l;
    int r;
}Node;
Node b[N];
bool vis[N];

void solve(){
    a.clear();
    memset(vis,0,sizeof vis);
    int n,m;
    cin >> n >> m;
    int l = 0,r = 0;
    for(int i = 1;i <= n;i ++){
        int x;
        cin >> x;
        if(x == -1)l ++;
        else if(x == -2) r++;
        else{
            if(!vis[x]){
                a.push_back(x);
                //cout << x << endl;
                vis[x] = true;
            }
        }
    }
    if(a.empty()){
        cout << max(l,r) << endl;
    }
    else{
        for(int i = 0;i < a.size();i ++){
            b[i].x = a[i];
            b[i].l = i;
            b[i].r = a.size() - i - 1;
            //cout << a[i] << endl;
        }
        int len = a.size();
        int ans = 0;
        sort(a.begin(),a.end());
        /*for(auto i : a){
            cout << i << ' ';
        }
        cout << endl;*/
        for(int i = 0;i < len;i ++){
            int maxm = 0;
            int lt = b[i].x - 1;
            int rt = m - b[i].x;
            if(l == 0){
                if(rt >= r + b[i].r){
                    maxm += r + b[i].r;
                }
                else{
                    maxm += rt;
                    if(lt >= r + b[i].r - rt){
                        maxm += r + b[i].r - rt;
                    }
                    else{
                        maxm += lt;
                    }
                }
            }
            else if(r == 0){
                if(lt >= l + b[i].l){
                    maxm += l + b[i].l;
                }
                else{
                    maxm += lt;
                    if(rt >= l + b[i].l - lt){
                        maxm += l + b[i].l - lt;
                    }
                    else{
                        maxm += rt;
                    }
                }
            }
            else{
                if(rt >= r + b[i].r && lt >= l + b[i].l){
                    maxm += r + b[i].r + l + b[i].l;
                }
                else{
                    maxm += max(r + b[i].r , l + b[i].l);
                }
            }
            maxm ++;
            ans = max(maxm,ans);
        }
        cout <<ans << endl;
    }
}

int main(){
    int t;
    cin >> t;
    while(t --){
        solve();
    }
    return 0;
}
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

void solve(){
    priority_queue<int> ap,bp;
    int n;
    cin>>n;
    int ans = 0;
    vector<int> a(n),b(n);
    for(int i = 0;i < n;i ++)cin>>a[i];
    for(int i = 0;i < n;i ++)cin>>b[i];
    for(int x : a)ap.push(x);
    for(int x : b)bp.push(x);
    while(!ap.empty()){
        if(ap.top() == bp.top()){
            ap.pop();
            bp.pop();
        }
        else if(ap.top() > bp.top()){
            int x = ap.top();
            ap.pop();
            int cnt = 0;
            while(x){
                x /= 10;
                cnt++;
            }
            ap.push(cnt);
            ans++;
        }
        else{
            int x = bp.top();
            bp.pop();
            int cnt = 0;
            while(x){
                x /= 10;
                cnt++;
            }
            bp.push(cnt);
            ans++;
        }
    }
    cout<<ans<<endl;
}


int main(){
    int t;
    cin>>t;
    while(t--)solve();
    system("pause");
    return 0;
}
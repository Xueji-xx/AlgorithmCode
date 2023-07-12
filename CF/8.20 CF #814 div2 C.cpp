#include<iostream>
#include<vector>
using namespace std;
typedef pair<int,int>PII;

void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> a(n+5);
    int maxm;
    for(int i = 1;i <= n;i ++){
        cin>>a[i];
        if(a[i] == n)maxm = i;
    }
    vector<PII> b(n+10);
    int x = a[1];
    int pos = 1,cnt = 1;
    for(int i = 2;i <= n;i ++){
        if(a[i] < x){
            if(b[pos].second == 0){
                b[pos].first = cnt;
            }
            b[pos].second = cnt;
        }
        else{
            x = a[i];
            pos = i;
            b[pos].second = cnt;
            b[pos].first = cnt;
        }
        cnt++;
    }
    while(q--){
        int i,k;
        cin>>i>>k;
        if(i > maxm || i > k + 1 || b[i].first > k || b[i].first == 0)cout<<0<<endl;
        else if(i == maxm)cout<<k - b[i].first + 1 <<endl;
        else{
            if(k >= b[i].second)cout<<b[i].second - b[i].first + 1<<endl;
            else cout<<k - b[i].first + 1<<endl;
        }
    }
}


int main(){
    int t;
    cin>>t;
    while(t--)solve();
    system("pause");
    return 0;
}
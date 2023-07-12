#include<iostream>
#include<algorithm>
using namespace std;
typedef pair<int,int> PII;
void solve(){
    int n,k;
    cin>>n>>k;
    PII a[n];
    for(int i = 0;i < n;i ++){
        cin>>a[i].first;
    }
    for(int i = 0;i < n;i ++){
        cin>>a[i].second;
    }
    sort(a,a+n);
    for(int i = 0;i < n;i ++){
        if(a[i].first > k){
            cout<<k<<endl;
            return;
        }
        else{
            k += a[i].second;
        }
    }
    cout<<k<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
    system("pause");
    return 0;
}
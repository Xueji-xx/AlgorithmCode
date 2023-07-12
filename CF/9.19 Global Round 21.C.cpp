#include<iostream>
using namespace std;
const int N = 5e4+50;
int cnta[N],cntb[N];
#define int long long


void solve(){
    int n,m;
    cin>>n>>m;
    int a[n+5];
    for(int i = 0;i < n;i ++){
        cin>>a[i];
        cnta[i] = 1;
        while(a[i]){
            if(a[i] % m != 0)break;
            a[i] /= m;
            cnta[i] *= m;
        }
    }
    int k;
    cin>>k;
    int b[k+5];
    for(int i = 0;i < k;i ++){
        cin>>b[i];
        cntb[i] = 1;
        while(b[i]){
            if(b[i] % m != 0)break;
            b[i] /= m;
            cntb[i] *= m;
        }
    }
    int l = 0,r = 0;
    while(l < n && r < k){
        if(a[l] != b[r]){
            cout<<"NO"<<endl;
            return;
        }
        else{
            if(cnta[l] > cntb[r]){
                cnta[l] -= cntb[r];
                r++;
            }
            else if(cnta[l] < cntb[r]){
                cntb[r] -= cnta[l];
                l++;
            }
            else l++,r++;
        }
    }
    if(l != n  || r != k )cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}

signed main(){
    int t;
    cin>>t;
    while(t--)solve();
    system("pause");
    return 0;
}
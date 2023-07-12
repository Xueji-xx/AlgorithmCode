#include<iostream>
using namespace std;

void solve(){
    int e,l,r,b;
    cin>>e>>l>>r>>b;
    int n = e + l + r + b;
    int minn = min(l,r);
    if(max(l,r) > 0)minn += b;
    else minn += max(0,b-1);
    minn = n - minn;
    int maxm = max(b - e - 1,0);
    maxm = n - maxm;
    cout<<minn<<' '<<maxm<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
    system("pause");
    return 0;
}
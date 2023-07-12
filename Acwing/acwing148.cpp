#include<bits/stdc++.h>
using namespace std;

priority_queue<int,vector<int>,greater<int>> q;

int main(){
    int n;
    cin>>n;
    for(int i = 1;i <= n;i ++){
        int x;
        cin>>x;
        q.push(x);
    }
    for(int i = 1;i <= n;i ++){
        int a = q.top(),q.pop();
        int b = q.top(),q.pop();
        ans += a + b;
        q.push(a+b);
    }
    cout<<ans<<endl;
    return 0;
}
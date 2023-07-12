#include <iostream>
#include <queue>
using namespace std;

void solve(){
    priority_queue<int> a;
    priority_queue<int> b;
    int n;
    cin>>n;
    for(int i = 1;i <= n;i ++){
        int x;
        cin>>x;
        while(!(x % 2)){
            x /= 2;
        }
        a.push(x);
    }
    for(int i = 1;i <= n;i ++){
        int x;
        cin>>x;
        b.push(x);
    }
    while(b.size()){
        int t = b.top();
        b.pop();
        int w = a.top();
        if(t == w){
            a.pop();
        }
        if(t > w){
            b.push(t/2);
        }
        if(w > t){
            cout<<"NO"<<endl;
            return;
        }
    }
    if(a.empty()){
        cout<<"YES"<<endl;
        return;
    }
    cout<<"NO"<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}
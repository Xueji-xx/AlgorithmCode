#include <iostream>
#include <queue>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int b[n+10] = {0};
    int ans[n+10] = {0};
    bool flag = true;
    for(int i = 2;i <= n;i += 2){
        cin>>ans[i];
        b[ans[i]] = i;
    }
    priority_queue<int> q;
    for(int i = n;i > 0;i --){
        if(b[i]){
            q.push(b[i]);
        }
        else{
            if(q.empty()){
                flag = false;
                break;
            }
            ans[q.top() - 1] = i;
            q.pop();
        }
    }
    if(flag){
        for(int i = 1;i <= n;i ++)cout<<ans[i]<<' ';
        cout<<endl;
    }
    else cout<<-1<<endl;
}


int main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}

/*
0 6 0 4 0 2
5 6
*/
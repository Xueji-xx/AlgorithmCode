#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define int long long


signed main(){
    int n;
    cin>>n;
    int a[n+10];
    for(int i = 1;i <= n;i ++)cin>>a[i];
    priority_queue<int,vector<int>,greater<int>> q;
    int cnt = 0;
    int sum = 0;
    for(int i = 1;i <= n;i ++){
        sum += a[i];
        q.push(a[i]);
        if(sum < 0){
            cnt --;
            sum -= q.top();
            q.pop();
        }
        cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}
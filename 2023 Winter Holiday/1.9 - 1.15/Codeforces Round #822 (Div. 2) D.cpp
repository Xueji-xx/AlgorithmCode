#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
using namespace std;
#define int long long
const int N = 2e5+50;
int a[N];
int n,k;

bool solve(){
    int sum = 0,minn = 0;
    vector<int> next;
    vector<int> need;
    for(int i = k + 1;i <= n;i ++){
        sum += a[i];
        minn = min(minn,sum);
        if(sum > 0){
            next.push_back(sum);
            need.push_back(minn);
            sum = minn = 0;
        }
    }
    int x = a[k];
    for(int i = k,j = -1;i;i --){
        while(j + 1 < next.size() && x + need[j+1] >= 0){
            j ++;
            x += next[j];
        }
        if(x + a[i-1] < 0)return false;
        x += a[i-1];
    }
    return true;
}

signed main(){
    int t;
    cin>>t;
    while(t--){
        cin>>n>>k;
        for(int i = 1;i <= n;i ++)cin>>a[i];
        if(solve()){
            cout<<"YES"<<endl;
            continue;
        }
        reverse(a + 1,a + n + 1);
        k = n - k + 1;
        if(solve()){
            cout<<"YES"<<endl;
            continue;
        }
        cout<<"NO"<<endl;
    }
    return 0;
}
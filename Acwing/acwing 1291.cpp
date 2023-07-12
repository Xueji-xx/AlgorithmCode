#include<iostream>
using namespace std;
const int N = 1e6+50;


int main(){
    int n;
    cin>>n;
    int a[n+5];
    int ans[N];
    int cnt[N];
    for(int i = 1;i <= n;i ++){
        cin>>a[i];
        cnt[a[i]]++;
    }
    for(int i = 1;i <= N;i ++){
        if(cnt[i]){
            for(int j = i;j <= N;j += i){
                ans[j] += cnt[i];
            }
        }
    }
    for(int i = 1;i <= n;i ++){
        cout<<ans[a[i]]<<endl;
    }
    return 0;
}
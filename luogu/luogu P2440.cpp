#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e7+60;
int n,k;
int a[N];
#define int long long

bool judge(int mid){
    int ans = 0;
    for(int i = 0;i < n;i ++){
        ans += a[i]/mid;
    }
    return ans >= k;
}


signed main(){ 
    cin>>n>>k;
    int sum = 0;
    for(int i = 0;i < n;i ++){
        cin>>a[i];
        sum += a[i];
    }
    if(sum < k)cout<<0<<endl;
    else{
        int l = 0,r = *max_element(a,a+n);
        int mid;
        while(l + 1 <= r){
            mid = l + r >> 1;
            if(judge(mid))l = mid; 
            else r = mid;
        }
        cout<<l<<endl;
    }
    system("pause");
    return 0;
}
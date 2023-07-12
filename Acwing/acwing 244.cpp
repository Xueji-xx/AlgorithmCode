#include<iostream>
using namespace std;

const int N = 1e5+10;
int n;
int tr[N],a[N];
int res[N];

int lowbit(int x){
    return x & -x;
}

void add(int x,int k){  
    for(int i = x;i <= n;i += lowbit(i)){
        tr[i] += k;
    }
}

int query(int x){
    int res = 0;
    for(int i = x;i;i -= lowbit(i)){
        res += tr[i];
    }
    return res;
}

int main(){
    cin>>n;
    for(int i = 2;i <= n;i ++)cin>>a[i];
    for(int i = 1;i <= n;i ++)tr[i]++;
    for(int x = 1;x <= n;x ++){
        for(int i = x - 1;i >= x - lowbit(x)+1;i -= lowbit(i)){
            tr[x] += tr[i];
        }
    }
    for(int i = n;i;i--){
        int k = a[i] + 1;
        int l = 1,r = n;
        while(l < r){
            int mid = l + r >> 1;
            if(query(mid) >= k) r = mid;
            else l = mid + 1;
        }
        res[i] = l;
        add(l,-1);
    }
    for(int i = 1;i <= n;i ++)cout<<res[i]<<endl;
    return 0;
}
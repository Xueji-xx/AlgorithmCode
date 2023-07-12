#include<iostream>
using namespace std;
const int N = 1e6+10;
int n,k,a[N],q[N];

int main(){
    cin>>n>>k;
    int h = 0,t = -1;
    for(int i = 0;i < n;i ++)cin>>a[i];
    for(int i = 0;i < n;i ++){
        if(h <= t && i - k + 1 > q[h])h++;
        while(h <= t && a[q[t]] >= a[i])t--;
        q[++t] = i;
        if(i >= k - 1)cout<<a[q[h]]<<' ';
    }
    cout<<endl;
    h = 0,t = -1;
    for(int i = 0;i < n;i ++){
        if(h <= t && i - k + 1 > q[h])h++;
        while(h <= t && a[q[t]] <= a[i])t--;
        q[++t] = i;
        if(i >= k-1)cout<<a[q[h]]<<' ';
    }
    system("pause");
    return 0;
}
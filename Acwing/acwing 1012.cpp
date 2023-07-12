#include<iostream>
#include<algorithm>
using namespace std;

const int N = 5050;
typedef pair<int,int> PII;

int f[N];
int main(){
    int n;
    cin>>n;
    PII a[N];
    for(int i = 1;i <= n;i ++)cin>>a[i].first >>a[i].second;
    sort(a+1,a+n+1);
    for(int i = 1;i <= n;i ++){
        for(int j = 0;j < i;j ++){
            if(a[i].second > a[j].second)f[i] = max(f[i],f[j]+1);
        }
    }
    int res = 0;
    for(int i = 1;i <= n;i ++)res = max(res,f[i]);
    cout<<res<<endl;
    return 0;
}
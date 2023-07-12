#include<iostream>
#include<algorithm>
using namespace std;
typedef pair<int,int> PII;
#define x first
#define y second




int main(){
    int n;
    cin>>n;
    PII a[n+5];
    for(int i = 1;i <= n;i ++){
        cin>>a[i].l>>a[i].r;
    }
    sort(a,a+n);
    return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 2e5 + 7, M = 1e6 + 10;
int a[M];

int main(){
    int n;
    cin>>n;
    for(int i = 1;i <= n;i ++){
        int x;
        cin>>x;
        a[x] = 1;
    }
    int ans = 0;
    for(int i = 1;i <= M;i ++){
        int d = 0;
        for(int j = i;j < M;j += i){
            if(a[j])d = __gcd(d,j / i);
        }
        if(d == 1 && !a[i])ans++;
    }
    cout<<ans<<endl;
    return 0;
}
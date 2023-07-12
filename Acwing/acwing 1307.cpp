#include<iostream>
using namespace std;

const int N = 1e5 + 10, mod = 5000011;
int f[N] = {0},s[N] = {0};

int main(){
    int n,k;
    cin>>n>>k;
    f[0] = 1;
    s[0] = 1;
    for(int i = 1;i <= n;i ++){
        f[i] = s[max((i - k - 1),0)];
        s[i] = (s[i-1] + f[i])% mod;
    }
    cout<<s[n]<<endl;
    return 0;
}
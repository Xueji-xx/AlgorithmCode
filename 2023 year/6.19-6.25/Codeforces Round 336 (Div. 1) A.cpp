#include <iostream>
using namespace std;

const int N = 1e6+50;
int a[N];
int dp[N];

int main(){
    int n;
    cin >> n;
    for(int i = 1;i <= n;i ++){
        int pos,r;
        cin >> pos >> r;
        a[pos] = r;
    }
    bool flag = false;
    int last;
    for(int i = 0;i <= N;i ++){
        if(a[i] == 0)dp[i] = dp[i-1];
        else{
            if(!flag)dp[i] = 1,flag = true,last = i;
            else if(i - last <= a[i])dp[i] = 1;
            else dp[i] = dp[i - a[i] - 1] + 1;
        }
    }
    int maxm = 0;
    for(int i = 0;i <= N;i ++){
        maxm = max(maxm,dp[i]);
    }
    cout << n - maxm << endl;
    return 0;
}
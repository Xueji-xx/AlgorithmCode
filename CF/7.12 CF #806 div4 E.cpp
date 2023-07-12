#include<iostream>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int map[120][120];
    for(int i = 1;i <= n;i ++){
        string s;
        cin>>s;
        s = '*'+s;
        for(int j = 1;j < s.length();j ++){
            map[i][j] = s[j] - '0';
        }
    }
    int ans = 0;
    /*for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= n;j ++){
            cout<<map[i][j]<<" ";
        }
        cout<<endl;
    }*/
    if(n >= 2){
        
    }
    for(int i = 1;i <= n/2;i ++){
        for(int j = 1;j <= i;j ++){
            if(i == j){
                int cnt0 = 0,cnt1 = 0;
                if(map[i][j] == 1)cnt1++;
                else cnt0++;
                if(map[n-i+1][j] == 1)cnt1++;
                else cnt0++;
                if(map[n-i+1][n-j+1] == 1)cnt1++;
                else cnt0++;
                if(map[i][n-j+1] == 1)cnt1++;
                else cnt0++;
                ans += min(cnt1,cnt0);
            }
            else{
                int cnt0 = 0,cnt1 = 0;
                if(map[i][j] == 1)cnt1++;
                else cnt0++;
                if(map[j][i] == 1 && i )cnt1++;
                else cnt0++;
                if(map[n-i+1][j] == 1)cnt1++;
                else cnt0++;
                if(map[j][n-i+1] == 1)cnt1++;
                else cnt0++;
                if(map[i][n-j+1] == 1)cnt1++;
                else cnt0++;
                if(map[n-j+1][i] == 1)cnt1++;
                else cnt0++;
                if(map[n-i+1][n-j+1] == 1)cnt1++;
                else cnt0++;
                if(map[n-j+1][n-i+1] == 1)cnt1++;
                else cnt0++;
                ans += min(cnt0,cnt1);
            }
        }
    }
    if((n & 1) && n != 1){
        for(int i = 1;i <= n/2;i ++){
            int cnt0 = 0,cnt1 = 0;
            if(map[i][(n+1)/2] == 1)cnt1++;
            else cnt0++;
            if(map[n-i+1][(n+1)/2] == 1)cnt1++;
            else cnt0++;
            if(map[(n+1)/2][i] == 1)cnt1++;
            else cnt0++;
            if(map[(n+1)/2][n-i+1] == 1)cnt1++;
            else cnt0++;
            ans += min(cnt1,cnt0);
        }
    }
    cout<<ans<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        solve();
    }
    system("pause");
    return 0;
}
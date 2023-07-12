#include <iostream>
#include <string.h>
using namespace std;
#define int long long

int n;
char s[1000010];
bool check(char a, char b) {
    if (a == b)return false;
    if (a == 'S')return  b == 'P';
    if (a == 'P')return b == 'R';
    if (a == 'R')return b == 'S';
}

signed main(){
    cin>>n;
    while(n --){
        scanf("%s",s+1);
        int ans = 0,maxm = -1;
        int pos = 1;
        int len = strlen(s+1);
        for(int i = 2;i <= len;i ++){
            if(s[i] == s[i-1])continue;
            if(check(s[i],s[i-1]))ans++;
            else ans --;
            if(ans > maxm){
                pos = i;
                maxm = ans;
            }
        }
        if(maxm == -1)pos = 1;
        cout<<s[pos]<<endl;
    }
    return 0;
}
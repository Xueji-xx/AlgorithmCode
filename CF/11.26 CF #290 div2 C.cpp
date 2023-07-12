#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
const int N = 100;

char s[N][N];
int ma[30][30],du[30];
vector<int> ans;

bool topsort(){
    for(int k = 1;k <= 26;k ++){
        int pos = -1;
        for(int i = 0;i <= 26;i ++){
            if(du[i] == 0){
                pos = i;
                break;
            }
        }
        if(pos == -1)return false;
        ans.push_back(pos);
        du[pos] = -1;
        for(int i = 0;i < 26;i ++)if(ma[pos][i])du[i]--;
    }
    return true;
}

int main(){
    int n;
    cin>>n;
    for(int i = 1;i <= n;i ++)cin>>s[i]+1;
    bool flag = true;
    for(int i = 2;i <= n;i ++){
        int len1 = strlen(s[i-1]+1);
        int len2 = strlen(s[i]+1);
        int j = 1;
        for(;j <= min(len1,len2);j ++){
            if(s[i][j] != s[i-1][j])
            {
                int x2 = s[i][j] - 'a';
                int x1 = s[i-1][j] - 'a';
                if(ma[x1][x2] == 0){
                    ma[x1][x2] = 1;
                    du[x2]++;
                }
                break;
            }
        }
        if(j == min(len1,len2)+1 && len1 > len2){
            flag = false;
            break;
        }
    }
    if(!flag){
        cout<<"Impossible"<<endl;
        return 0;
    }
    if(topsort()){
        for(int i = 0;i < ans.size();i ++)printf("%c",ans[i]+'a');
    }
    else cout<<"Impossible"<<endl;
    return 0;
}
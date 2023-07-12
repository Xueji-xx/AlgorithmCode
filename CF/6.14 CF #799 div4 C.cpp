#include<iostream>
using namespace std;

void solve(){
    char map[9][9];
    int cnt[9] = {0};
    for(int i = 1;i <= 8;i ++){
        for(int j = 1;j <= 8;j ++){
            cin>>map[i][j];
            if(map[i][j] == '#')cnt[i]++;
        }
    }
    for(int i = 2;i <= 7;i ++){
        if(cnt[i] == 1 && cnt[i-1] == 2 && cnt[i+1] == 2){
            for(int j = 1;j <= 8;j ++){
                if(map[i][j] == '#'){
                    cout<<i<<' '<<j<<endl;
                    return;
                }
            }
        }
    }
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
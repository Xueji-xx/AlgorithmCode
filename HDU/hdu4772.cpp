#include<iostream>
using namespace std;
int map[310][310];
int c[110][110];
int tmp[110][110];
int n;
void fanzhuan(){
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= n;j ++){
            tmp[i][j] = map[n-j+1][i];
        }
    }
    for(int i = 1;i <= n;i ++){
        for(int j = 1;j <= n;j ++){
            map[i][j] = tmp[i][j];
        }
    }
}


int main(){
    while(~scanf("%d",&n)){
        for(int i = 1;i <= n;i ++){
            for(int j = 1;j <= n;j ++){
                cin>>map[i][j];
            }
        }
        for(int i = 1;i <= n;i ++){
            for(int j = 1;j <= n;j ++){
                cin>>c[i][j];
            }
        }
        int ans = 0;
        for(int t = 0;t < 4;t ++){
            int res = 0;
            for(int i = 1;i <= n;i ++){
                for(int j = 1;j <= n;j ++){
                    if(map[i][j] == c[i][j])res++;
                }
            }
            ans = max(ans,res);
            /*for(int i = 1;i <= n;i ++){
                for(int j = 1;j <= n;j ++){
                    cout<<map[i][j]<<' ';
                }
                cout<<endl;
            }*/
            fanzhuan();
        }
        cout<<ans<<endl;
    }
    system("pause");
    return 0;
}
/*
2
10 20
30 13
90 10
13 21
*/
#include<iostream>
using namespace std;
int map[1010][1010];
int main(){
    int r;
    cin>>r;
    for(int i = 0;i < r;i ++){
        for(int j = 0;j <= i;j ++){
            cin>>map[i][j];
        }
    }
    for(int i = r-2;i >= 0;i --){
        for(int j = 0;j <= i;j ++){
            map[i][j] = map[i][j] + max(map[i+1][j],map[i+1][j+1]);
        }
    }
    cout<<map[0][0]<<endl;
    system("pause");
    return 0;
}
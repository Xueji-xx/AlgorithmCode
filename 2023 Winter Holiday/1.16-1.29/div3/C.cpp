#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int map[150][150];

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i = 1;i <= n;i ++){
            for(int j = 1;j <= n-1;j ++){
                cin>>map[i][j];
            }
        }
        vector<int>ans;
        int num[150] = {0};
        for(int j = 1;j <= n-1;j ++){
            memset(num,0,sizeof num);
            for(int i = 1;i <= n;i ++){
                num[map[i][j]]++;
            }
            int maxm = 0;
            int minn = 99999999;
            int max_poi = 0;
            int min_poi = 0;
            for(int i = 1;i <= n;i ++){
                if(num[i] > maxm){
                    maxm = num[i];
                    max_poi = i;
                }
                if(num[i] != 0 && num[i] <= minn){
                    minn = num[i];
                    min_poi = i;
                }
            }
            int x;
            int y;
            if(n & 1){
                if(j != n/2){
                    ans.push_back(max_poi);
                }
                else{
                    ans.push_back(max_poi);
                    ans.push_back(min_poi);
                }
            }
            else{
                if(j == n/2 - 1){
                    x = min_poi;
                    ans.push_back(max_poi);
                    continue;
                }
                if(j == n/2 + 1){
                    ans.push_back(min_poi);
                    ans.push_back(max_poi);
                    continue;
                }
                if(j != n/2){
                    ans.push_back(max_poi);
                }
                else{
                    ans.push_back(x);
                }
            }
        }
        for(auto i : ans)cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
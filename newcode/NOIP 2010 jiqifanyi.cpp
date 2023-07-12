#include <iostream>
using namespace std;

const int N = 1050;
int q[N];
bool vis[N];

int main(){
    int m,n;
    cin>>m>>n;
    int end = 1,front = 1;
    int ans = 0;
    for(int i = 1;i <= n;i ++){
        int x;
        cin>>x;
        if(vis[x])continue;
        else{
            if(end - front < m){
                vis[x] = true;
                q[end++] = x;
                ans ++;
            }
            else{
                vis[q[front++]] = false;
                vis[x] = true;
                q[end++] = x;
                ans ++;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
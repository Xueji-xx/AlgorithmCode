#include<iostream>
using namespace std;
const int N = 1e6+50;

int pri[N],cnt,n;
bool vis[N];


void get_prime(int n){
    vis[1] = true;
    for(int i = 2;i <= n;i ++){
        if(!vis[i])pri[cnt++] = i;
        for(int j = 0;pri[j] <= n / i;j ++){
            vis[pri[j] * i] = true;
            if(i % pri[j] == 0)break;
        }
    }
}


int main(){
    get_prime(N);
    while(cin>>n&&n){
        int i = 1;
        while(i){
            if(!vis[n - pri[i]]){
                cout<<n<<" = "<<pri[i]<<" + "<<n-pri[i]<<endl;
                break;
            }
            i++;
        }
    }
    return 0;
}
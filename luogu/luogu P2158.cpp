    #include<iostream>
    using namespace std;
    const int N = 4e4+50;
    int pri[N],phi[N],ans,vis[N],cnt;

    int solve(int n){
        if(n == 1)return 0;
        phi[1] = 1;
        for(int i = 2;i <= n-1;i ++){ 
            if(!vis[i]){
                pri[++cnt] = i;
                vis[i] = i;
                phi[i] = i - 1; 
            }
            for(int j = 1;j <= cnt;j ++){
                if(pri[j] * i > n || pri[j] > vis[i])break;
                else{
                    vis[pri[j]*i] = pri[j];
                    if(pri[j] < vis[i])phi[i * pri[j]] = phi[i] * (pri[j] - 1);
                    else phi[i * pri[j]] = phi[i] * pri[j];
                }
            }
            phi[i] += phi[i-1];
        }
        return (phi[n-1] << 1 | 1);
    }



    int main(){
        int n;
        cin>>n;
        cout<<solve(n)<<endl;
        system("pause");
        return 0;
    }



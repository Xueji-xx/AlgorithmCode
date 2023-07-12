    #include<iostream>
    using namespace std;

    int pri[100] = {2,3,5,7,11,13,17,19,23};
    int res = INT_MAX;
    int ans,n;

    void dfs(int u,int s,int p,int pre){
        if(pre > ans || (pre == ans && p < res)){
            res = p;
            ans = pre;
        }
        if(u == 9)return;
        for(int i = 1;i <= s;i ++){
            if(p * pri[u] > n)break;
            p *= pri[u];
            dfs(u+1,i,p,pre*(i+1));
        }
    }

    int main(){
        cin>>n;
        dfs(0,30,1,1);
        return 0;
    }
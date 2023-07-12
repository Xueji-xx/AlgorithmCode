#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
unordered_map<int,vector<int> >map;
unordered_map<int,int>s;
typedef pair<int,int>PII;
unordered_map<int,PII>ans;


int dfs(int x,int y){//计算节点个数
    if(x == 0)return 0;
    int res = 0,left = 1;
    for(auto i:map[x]){
        if(i != y){
            if(left == 1){
                left = 2;
                ans[x].first = i;
                res += dfs(i,x);
            }
            else{
                ans[x].second = i;
                res += dfs(i,x);
            }
        }
    }
    s[x] = res;
    return res + 1;
}

int dfs2(int x){//统计两种情况的最大值
    if(x == 0)return 0;
    int res = 0;
    res = max(res,s[ans[x].first] + dfs2(ans[x].second));
    res = max(res,s[ans[x].second] + dfs2(ans[x].first));
    return res;
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        map.clear();
        s.clear();
        ans.clear();
        for(int i = 1;i <= n-1;i ++){
            int u,v;
            cin>>u>>v;
            map[u].push_back(v);
            map[v].push_back(u);
        }
        dfs(1,0);
        cout<<dfs2(1)<<endl;
    }
    system("pause");
    return 0; 
}

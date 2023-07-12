    #include<iostream>
    #include<string.h>
    using namespace std;

    #define int long long
    #define endl '\n'
    const int N = 1e5+50;

    int a[N],tr[N],n;
    bool vis[N];

    int lowbit(int x){
        return x & -x;
    }

    void add(int x,int k){
        for(int i = x;i <= n;i += lowbit(i)){
            tr[i] += k; 
        }
    }

    int get(int x){
        int ans = 0;
        for(int i = x;i;i -= lowbit(i)){
            ans += tr[i];
        }
        return ans;
    }


    void solve(){
        cin>>n;

        memset(tr,0,sizeof tr);
        memset(vis,false,sizeof vis); 
        int maxm = 0;

        for(int i = 1;i <= n;i ++)cin>>a[i];
        int sum = 0;
        cout<<0;

        add(a[1],1);
        maxm = a[1];
        vis[a[1]] = true;

        int cnt = 0;
        bool flag = false;
        for(int i = 2;i <= n;i ++){
            if(a[i] == maxm){
                flag = 1;
                cnt += flag;
            }
            else if(a[i] < maxm){
                sum += get(maxm) - get(a[i]);
                cnt += flag;
            }
            else{
                sum += 2 + cnt;
                maxm = a[i];
                cnt = 0;
                flag = false;
            }
            cout<<' '<<sum;
            if(!vis[a[i]]){
                vis[a[i]] = true;
                add(a[i],1);
            }
        }
        cout<<endl;
    }

    signed main(){
        ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        int t;
        cin>>t;
        while(t--)solve();
        return 0;
    }
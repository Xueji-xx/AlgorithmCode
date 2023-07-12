#include <iostream>
#include <string.h>
using namespace std;
#define int long long

void solve(){
    int n;
    cin>>n;
    int a[n+10];
    int cnt[n+10];
    memset(a,0,sizeof a);
    memset(cnt,0,sizeof cnt);
    for(int i = 1;i <= n;i ++){
        cin>>a[i];
        cnt[a[i]]++;
    }
    for(int i = 1;i <= n;i ++){
        if(cnt[i] > 2){
            cout<<"NO"<<endl;
            return;
        }
    }
    if(!cnt[n]){//从大到小必须有
        cout<<"NO"<<endl;
        return;
    }
    else if(cnt[n] == 1){
        int j = n;
        while(cnt[j]){
            j --;
            if(j <= 0)break;
            if(cnt[j] == 0){
                cout<<"NO"<<endl;
                return;
            }
            if(cnt[j] == 2){
                break;
            }
        }
    }
    if(cnt[1] == 2){//从小到大必须无
        cout<<"NO"<<endl;
        return;
    }
    else if(cnt[1] == 1){
        int i = 1;
        while(cnt[i]){
            i ++;
            if(i > n)break;
            if(cnt[i] == 2){
                cout<<"NO"<<endl;
                return;
            }
            if(cnt[i] == 0){
                break;
            }
        }
    }
    int p[n+10],q[n+10];
    bool visp[n+10],visq[n+10];//q，p两个数组
    memset(p,0,sizeof p);
    memset(q,0,sizeof q);
    memset(visq,false,sizeof visq);
    memset(visp,false,sizeof visp);
    for(int i = 1;i <= n;i ++){//把a数组赋给p
        if(!visp[a[i]]){
            p[i] = a[i];
            visp[a[i]] = 1;
        }
        else{
            q[i] = a[i];
            visq[a[i]] = 1;
        }
    }
    for(int i = 1;i <= n;i ++){//完善p数组的剩余部分
        if(!p[i]){
            if(!q[i]){
                for(int j = n;j >= 1;j --){
                    if(!visp[j]){
                        p[i] = j;
                        visp[j] = 1; 
                        break;
                    }
                }
            }
            else{
                for(int j = q[i];j >= 1;j --){
                    if(!visp[j]){
                        p[i] = j;
                        visp[j] = 1;
                        break;
                    }
                }
            }
        }
    }
    for(int i = 1;i <= n;i ++){//完善q数组的剩余部分
        if(!q[i]){
            for(int j = p[i];j >= 1;j --){
                if(!visq[j]){
                    visq[j] = 1;
                    q[i] = j;
                    break;
                }
            }
        }
    }
    cout<<"YES"<<endl;
    for(int i = 1;i <= n;i ++){
        cout<<p[i]<<' ';
    }
    cout<<endl;
    for(int i = 1;i <= n;i ++){
        cout<<q[i]<<' ';
    }
    cout<<endl;
}

signed main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}

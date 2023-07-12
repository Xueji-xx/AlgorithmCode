#include <iostream>
using namespace std;
#define int long long
const int N = 2e5+50;
int p[N],q[N];
int posp[N],posq[N];
int pa,pb,qa,qb;

signed main(){
    int n;
    cin>>n;
    for(int i = 1;i <= n;i ++){
        cin>>p[i];
        posp[p[i]] = i;
    }
    for(int i = 1;i <= n;i ++){
        cin>>q[i];
        posq[q[i]] = i;
    }
    int la = n,ra = 1;
    int lb = n,rb = 1;
    int ans = 0;
    ans += (min(posp[1],posq[1])-1)*(min(posp[1],posq[1]))/2;
    ans += (n - max(posp[1],posq[1])+1)*(n - max(posp[1],posq[1]))/2;
    ans += (max(posp[1],posq[1]) - min(posp[1],posq[1]) - 1) * (max(posp[1] , posq[1]) - min(posp[1],posq[1]))/2;
    for(int i = 1;i < n;i ++){
        la = min(la,posp[i]);
        lb = min(lb,posq[i]);
        ra = max(ra,posp[i]);
        rb = max(rb,posq[i]);   
        if(posp[i+1] < la){
            pa = posp[i+1] + 1;
            qa = n; 
        }
        if(posp[i+1] >= la && posp[i+1] <= ra)continue;
        if(posp[i+1] > ra){
            pa = 1;
            qa = posp[i+1] - 1;
        }
        if(posq[i+1] < lb){
            pb = posq[i+1] + 1;
            qb = n;
        }
        if(posq[i+1] >= lb && posq[i+1] <= rb)continue;
        if(posq[i+1] > rb){
            pb = 1;
            qb = posq[i+1] - 1;
        }
        //cout<<ans<<endl;
        ans += (max(0ll,min(la,lb) - max(pa,pb) + 1)) * (max(0ll,min(qa,qb) - max(ra,rb)+1));
    }
    ans++;
    cout<<ans<<endl;
    return 0;
}
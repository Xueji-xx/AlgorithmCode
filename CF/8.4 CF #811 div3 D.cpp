#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

void solve(){
    string t;
    cin>>t;
    int n;
    cin>>n;
    vector<string> s(n);
    for(int i = 0;i < n;i ++)cin>>s[i];
    int len = (int)t.size();
    vector<int> rig(len+10,-1);
    vector<int> id(len+10,-1);
    for(int i = 0;i < n;i ++){
        string a = s[i];
        for(int j = 0;j <= (int)t.size() - (int)a.size();j ++){
            if(t.substr(j,(int)a.length()) == a){
                if(j + (int)a.size() > rig[j]){
                    rig[j] = j + (int)a.size();
                    id[j] = i;
                }
            }
        }
    }
    int ans = 0;
    int poi = 0;
    vector<pair<int,int>> res;
    while(poi < len){
        int pos = (int)(max_element(rig.begin(),rig.begin()+poi+1) - rig.begin());
        int nex = rig[pos];
        if(nex <= poi){
            ans = -1;
            break;
        }
        res.push_back({id[pos],pos});
        ans += 1;
        poi = nex;
    }
    cout<<ans<<endl;
    if(ans != -1){
        for(auto i:res){
            cout<<i.first+1<<' '<<i.second+1<<endl;
        }
    }
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
    system("pause");
    return 0;
}
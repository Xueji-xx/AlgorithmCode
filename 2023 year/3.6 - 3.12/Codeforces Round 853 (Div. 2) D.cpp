#include <iostream>
#include <vector>
using namespace std;

void solve(){
    int n;
    cin>>n;
    string a1,b1;
    cin>>a1>>b1;
    vector<int> a(n+1),b(n+1);
    int cnt_a = 0,cnt_b = 0;
    for(int i = 1;i <= n;i ++){
        a[i] = a1[i-1] - '0';
        if(a[i] == 1)cnt_a++;
    }
    for(int i = 1;i <= n;i ++){
        b[i] = b1[i-1] - '0';
        if(b[i] == 1)cnt_b++;
    }
    if((cnt_a && !cnt_b) || (!cnt_a && cnt_b)){
        cout<<-1<<endl;
        return;
    }
    int pos = 0;
    for(int i = 1;i <= n;i ++){
        if(b[i] == 1){
            pos = i;
            break;
        }
    }
    vector<int> v;
    auto change = [&](int len){
        v.push_back(len);
        if(len > 0){
            for(int i = 0;i + len <= n;i ++)a[i] ^= a[i+len];
        }
        else{
            len = -1 * len;
            for(int i = n;i >= len+1;i --){
                a[i] ^= a[i - len];
            }
        }
    };
    for(int i = pos;i >= 1;i --){
        if(a[i] == b[i])continue;
        for(int j = n;j >= 1;j --){
            if(a[j] == 1){
                change(j - i);
                break;
            }
        }
    }
    for(int i = pos + 1;i <= n;i ++){
        if(a[i] == b[i])continue;
        change(pos - i);
    }
    cout<<v.size()<<endl;
    if(v.size()){
        for(auto i : v){
            cout<<i<<' ';
        }
        cout<<endl;
    }
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
    return 0;
}
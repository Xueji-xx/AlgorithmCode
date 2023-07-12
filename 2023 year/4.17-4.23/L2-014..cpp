#include <iostream>
#include <stack>
#include <vector>
#include <queue>
using namespace std;

stack <int> st;
vector <int> ans;
queue <int> a;

int main(){
    int n,m,k;
    cin >> n >> m >> k;
    for(int i = 1;i <= n;i ++){
        int x;
        cin >> x;
        a.push(x);
    }
    while(1){
        ans.clear();
        bool flag = false;
        while(1){
            if(ans.empty()){
                if(!st.empty()){
                    ans.push_back(st.top());
                    st.pop();
                }
                else if(!a.empty()){
                    ans.push_back(a.front());
                    a.pop();
                }
                else break;
            }
            else{
                if(!st.empty() && st.top() <= ans.back()){
                    ans.push_back(st.top());
                    st.pop();
                }
                else{
                    while(!a.empty() && st.size() <= m){
                        auto t = a.front();
                        if(t <= ans.back()){
                            a.pop();
                            ans.push_back(t);
                            break;
                        }
                        else{
                            if(st.size() == m){
                                flag = true;
                                break;
                            }
                            else{
                                st.push(t);
                                a.pop();
                            }
                        }
                    }
                    if(a.empty() && (st.empty() || st.top() >= ans.back())){
                        break;
                    }
                }
            }
            if(flag || ans.size() == k){
                break;
            }
        }
        for(int i = 0;i < ans.size();i ++){
            if(i != ans.size() - 1){
                cout << ans[i] << ' ';
            }
            else cout << ans[i] << endl;
        }
        if(st.empty() && a.empty()){
            break;
        }
    }
    return 0;
}
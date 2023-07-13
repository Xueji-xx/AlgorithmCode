    #include <iostream>
    using namespace std;
     
     
     
     
    int main(){
        int t;
        cin >> t;
        while(t --){
            int n;
            cin >> n;
            int cnt[150] = {0};
            int maxm = 0;
            for(int i = 1;i <= n;i ++){
                int x;
                cin >> x;
                maxm = max(maxm,x);
                cnt[x] ++;
            }
            bool flag = true;
            for(int i = 0;i <= maxm;i ++){
                if(cnt[i] < cnt[i+1]){
                    flag = false;
                    break;
                }
            }
            for(int i = 0;i <= maxm;i ++){
                if(cnt[i] == 0){
                    flag = false;
                    break;
                }
            }
            if(flag)cout << "YES" << endl;
            else cout << "NO" << endl;
        }
        return 0;
    }
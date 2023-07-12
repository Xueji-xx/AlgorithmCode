#include <iostream>
#include <stack>
using namespace std;


int main(){
    int t;
    cin>>t;
    while(t--){
        int n,s,r;
        cin>>n>>s>>r;
        int x = s - r;
        if(n * x == s){
            for(int i = 1;i <= n;i ++){
                cout<<x<<' ';
            }
            cout<<endl;
        }
        else{
            int d = n * x - s;
            for(int i = 1;i <= n;i ++){
                if(d >= x -1){
                    cout<<1<<' ';
                    d -= (x-1);
                }
                else{
                    cout<<x - d<<' ';
                    d = 0;
                }
            }
            cout<<endl;
        }
    }
    return 0;
}
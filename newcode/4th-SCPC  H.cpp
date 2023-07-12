#include<iostream>
using namespace std;
const int N = 2e6+50;
char stk[N];
char trans(int x){
    if(x < 10)return (char)(x + '0');
    else return (char)(x - 10 + 'A');
}

int main(){
    int n,s;
    cin>>n>>s;
    bool flag1 = false;
    for(int i = 2;i <= n;i ++){
        int x = s;
        bool flag = true;
        int top = 0;
        while(x){
            stk[++top] = trans(x % i);
            x /= i;
        }
        for(int j = 1;j <= (top+1)/2;j ++){
            if(stk[j] != stk[top - j + 1]){
                flag = false;
                break;  
            }
        }
        for(int j = 1;j < (top+1)/2;j ++){
            if(stk[j] >= stk[j+1]){
                flag = false;
                break;
            }
        }
        if(flag){
            cout<<i<<' ';
            for(int j = 1;j <= top;j ++){
                cout<<stk[j];
            }
            flag1 = false;
            cout<<endl;
        }
    }
    if(flag1)cout<<"guomienasai"<<endl;
    return 0;
}
#include<iostream>
using namespace std;

int stk[10000];


int main(){
    int n,m;
    cin>>n>>m;
    string a,b;
    cin>>a>>b;
    int cnt = 0,top = 0;
    bool flag = false;
    for(int i = 0;i < b.length();i ++){
        if(b[i] == stk[top]){
            top--;
        }
        else{
            while(cnt < n && top <= m && b[i] != a[cnt]){
                stk[++top] = a[cnt++];
            }
            if(cnt == n || top > m){
                flag = true;
                break;
            }
            cnt++;
        }
    }
    if(flag || n != b.length())cout<<"That's not Funny at all!"<<endl;
    else cout<<"Don't you think that's Funny?"<<endl;
    return 0;
}
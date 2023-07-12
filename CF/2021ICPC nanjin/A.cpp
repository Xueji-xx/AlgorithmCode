#include<iostream>
using namespace std;



int main(){
    int n,a,b;
    cin>>n>>a>>b;
    int mid = n / 2;
    int x = 0,y = 0;
    bool mark1 = false;
    bool mark2 = false;
    if(a <= mid){
        x = a - 1;
        mark1 = true;
        for(int i = 1;i < n;i ++)cout<<'U';
    }
    else{
        x = n - a;
        mark1 = false;
        for(int i = 1;i < n;i ++)cout<<'D';
    }
    if(b <= mid){
        y = b - 1;
        mark2 = true;
        for(int i = 1;i < n;i ++)cout<<'L';
    }
    else {
        y = n - b;
        mark2 = false;
        for(int i = 1;i < n;i ++)cout<<'R';
    }
    if(mark1)
        for(int i=1;i <= x;i++)
        {
            printf("D");
        }
    else
        for(int i=1;i <= x;i++)
        {
            printf("U");
        }
    if(mark2)
        for(int i=1;i<=y;i++)
        {
            printf("R");
        }
    else
        for(int i=1;i<=y;i++)
        {
            printf("L");
        }
    return 0;
}
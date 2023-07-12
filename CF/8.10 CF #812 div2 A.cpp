#include<iostream>
using namespace std;

void solve(){
    int n;
    cin>>n;
    int maxx,maxy,minx,miny;
    int x,y;
    maxx = maxy = minx = miny = 0;
    for(int i = 0;i < n;i ++){
        cin>>x>>y;
        maxx = max(maxx,x);
        minx = min(minx,x);
        maxy = max(maxy,y);
        miny = min(miny,y);
    }
    cout<<2*(maxx + maxy - minx - miny)<<endl;
}

int main(){
    int t;
    cin>>t;
    while(t--)solve();
    system("pause");
    return 0;
}
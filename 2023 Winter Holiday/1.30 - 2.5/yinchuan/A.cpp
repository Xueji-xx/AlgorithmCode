#include <iostream>
using namespace std;

int X,Y,Z;
int a[500][500],b[500][500],c[500][500];

int main(){
    int n;
    cin>>n;
    for(int i = 0;i < n;i ++){
        int x,y,z;
        cin>>x>>y>>z;
        a[x+100][y+100]++;  
        if(a[x+100][y+100] == 1)Z++;

        b[x+100][z+100]++;
        if(b[x+100][z+100] == 1)Y++;

        c[y+100][z+100]++;
        if(c[y+100][z+100] == 1)X++;
    }
    int maxm = max(Z,max(X,Y));
    if(maxm == X)cout<<"X"<<endl;
    else if(maxm == Y)cout<<"Y"<<endl;
    else cout<<"Z"<<endl;
    return 0;
}
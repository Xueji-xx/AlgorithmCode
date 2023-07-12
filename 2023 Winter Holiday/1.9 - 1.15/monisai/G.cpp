#include <iostream>
#include <vector>
using namespace std;
#define int long long

signed main(){
    int n;
    cin>>n;
    vector<int> a;vector<int> b;
    for(int i = 1;i <= n;i ++){
        int x;
        cin>>x;
        b.push_back(x);
    }
    
    int cnt = 0;
    while (true) {
        if (b.size() <= 1)break;
        for (int x : b)a.push_back(x);
        b.clear();
        for (int i = 0; i < a.size(); i++)
            if (!i && a[i] > a[i + 1])b.push_back(a[i]);
            else if (i == a.size() - 1 && a[i - 1] < a[i])b.push_back(a[i]);
            else if (a[i - 1]<a[i] && a[i]>a[i + 1])b.push_back(a[i]);
        a.clear();
        cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}
#include <iostream>
using namespace std;

const int N = 3e6+50;
char b[N];
int a[N];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0;i < 2 * n + 2;i ++)cin >> a[i];
    char ch = 'a';
    for(int i = 0,r = 0;i < 2 * n + 2;i ++){
        while(i + a[i] - 1 > r)r ++,b[r] = b[2 * i - r];
        if(i == 0)b[i] = '&';
        else if(i & 1)b[i] = '|';
        else if(b[i] == 0)b[i] = ch,ch = (ch == 'a' ? 'b' : 'a');
    }
    for(int i = 2;i <= 2*n + 1;i += 2)cout << b[i];
    return 0;
}
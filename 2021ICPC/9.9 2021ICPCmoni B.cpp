#include <bits/stdc++.h>
#define endl '\n'
using namespace std ; 
const int N = 1e5 +10 ; 
int a[N] ; 
int ans ; 
int main()
{
    int n , k ; 
    cin >> n  >> k  ; 
    int sum = n ; 
    for(int i = 0 ; i< n ;i++)
    cin >> a[i] ; 
    
    sort(a , a +n  ) ; 
    
    reverse(a , a + n );
    
    for(int i = 0 ; i< n ;i++)
    {
        int tot =  (k + a[i]  )/ a[i] ; 
        sum -= tot ; 
        if(sum < 0) break ; 
        ans++ ; 
    }
    cout << ans ;
    return 0 ; 
}

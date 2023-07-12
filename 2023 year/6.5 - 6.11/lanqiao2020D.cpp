#include <iostream>
using namespace std;
#define int long long
int dp[300];

signed main(){
	string s="tocyjkdzcieoiodfpbgcncsrjbhmugdnojjddhllnofawllbhfiadgdcdjstemphmnjihecoapdjjrprrqnhgccevdarufmliqijgihhfgdcmxvicfauachlifhafpdccfseflcdgjncadfclvfmadvrnaaahahndsikzssoywakgnfjjaihtniptwoulxbaeqkqhfwl";
	for(int i = 0;i < 200;i ++)dp[i] = 1;
	for(int i = 1;i < 200;i ++){
		for(int j = 0;j < i;j ++){
			if(s[i] > s[j]){
				dp[i] += dp[j];
			}
			else if(s[i] == s[j]){
				dp[i] -= dp[j];
			}
		}
	}
	int ans = 0;
	for(int i = 0;i < 200;i ++){
		ans += dp[i];
	}
	cout << ans << endl;
	return 0;
}

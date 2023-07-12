#include <bits/stdc++.h>
using namespace std;

char ans[500];
int i;

void fun(char ans[],int num,int n){
	char result = num % n + '0' - 0;
	if(num/n > 0)
	fun(ans,num/n,n);
	ans[i++] = result;
}

int main(){
	string a;
	string b;
	cin >> a >> b;
	int x = stoi(a,nullptr,2);
	int y = stoi(b,nullptr,3);
	int sum = x + y;
	fun(ans,sum,5);
	cout << ans << endl;
	return 0;
}

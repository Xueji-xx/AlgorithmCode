#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
#include<algorithm>
using namespace std;


int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		int sum = 0;
		for(int i = 0;i < n;i ++){
			cin>>a[i];
			sum += a[i];
		}
		bool flag = true;
		for(int i = 0;i < n;i ++){
			if(a[i] == floor(sum - a[i])/(n-1)){
				flag = false;
				break;
			}
		}
		if(flag)cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	
	return 0;
}

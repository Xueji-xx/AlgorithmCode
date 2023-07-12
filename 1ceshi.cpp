#include<iostream>
using namespace std;

bool isPrime(int num)
{
	if (num == 2 || num == 3)
	{
		return true;
	}
	if (num % 6 != 1 && num % 6 != 5)
	{
		return false;
	}
	for (int i = 5; i*i <= num; i += 6)
	{
		if (num % i == 0 || num % (i+2) == 0)
		{
			return false;
		}
	}
	return true;
}

int main(){
	int n;
	cin>>n;
	for(int i = 1;i <= n;i ++){
		if(isPrime(i)){
			cout<<i<<' '<<"Y"<<endl;
		}
		else cout<<i<<endl;
	}
	return 0;
} 

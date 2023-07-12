#include <iostream>
using namespace std;
int cnt;
int n;
char c[200];
int stp;

void print(){
	cout<<"Step "<<cnt<<':';
	for(int i = 1;i <= 2*n+2;i ++){
		cout<<c[i];
	}
	cout<<endl;
	cnt++;
}

void move(int k){
	for(int j = 0;j < 2;j ++){
		c[stp + j] = c[k + j];
		c[k + j] = '0';
	}
	stp = k;
	print();
}

void mv(int n){
	if(n == 4){
		move(4),move(8);
		move(2),move(7),move(1);
	}
	else{
		move(n);
		move(2*n-1),mv(n-1);
	}
}

int main(){
	cin>>n;
	cnt = 0;
	stp = 2 * n + 1;
	for(int i = 1;i <= n;i ++){
		c[i] = '1';
	}
	for(int i = n+1;i <= 2*n;i ++){
		c[i] = '2';
	}
	c[2*n+1] = '0',c[2*n+2] = '0';
	print();
	mv(n);
	cout<<cnt-1<<endl;
	return 0;
} 

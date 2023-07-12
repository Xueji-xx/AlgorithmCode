/*
植树节，采用顺序表存储结构记录志愿者的姓名和植树的数量，设计程序要求实现：
（1）采用希尔排序排成一个非递减有序表后输出显示，并应用折半查找方法在有序表中查找给定的树的数量，并显示数据在表中位置。
（2）采用堆排序方法实现输出植树最多的前三名志愿者的姓名和植树数量。
2111310110 创新2102 53-贾少晨 
*/

#include <iostream>
using namespace std;

typedef struct{
	string name;//学生姓名 
	int num;//学生植树数量 
}STU;

////////////////////////////希尔排序////////////////////////////////
void Shellsort(STU s[],int n){
	for(int gap = n >> 1;gap > 0;gap >>= 1){//设置步长 
		for(int i = gap;i < n;i ++){
			STU tmp = s[i];
			int j = i - gap;
			while(j >= 0 && s[j].num > tmp.num){//排序 
				s[j + gap] = s[j];
				j -= gap;
			}
			s[j + gap] = tmp;
		}
	}
}

////////////////////////////折半查找////////////////////////////////
void Search(STU s[],int treenum,int n){
	int l = 0,r = n;
	while(l < r){
		int mid = l + r >> 1;
		if(s[mid].num > treenum)r = mid;//如果当前中点值 > 查找值，缩小右端点。 
		else l = mid + 1;//反之增大左端点 
	}
	if(s[l-1].num == treenum){
		cout<<"您查找的学生为:"<<s[l-1].name<<endl;
		cout<<"在当前表中的位置为第"<<l<<"位"<<endl; 
	}
	else cout<<"当前没有学生种植了您想要查询的树的数量"<<endl;
}

////////////////////////////堆排序//////////////////////////////////

void down(STU arr[],int i,int n){//大根堆转移 
	int par = i;//记录父节点的下标 
	int cld = 2 * i + 1;//记录子节点下标 
	while(cld < n){
		if(cld + 1 < n && arr[cld].num < arr[cld + 1].num){//判断最大的子节点 
			cld++;
		}
		if(arr[par].num < arr[cld].num){//是否交换子父节点 
			swap(arr[par],arr[cld]);
			par = cld;
		}
		cld = cld * 2 + 1;//比较之后的子父节点 
	}
}

void display(STU arr[], int n){//打印函数 
    for(int i = 0; i < n; i++){
        cout<<arr[i].name<<' '<<arr[i].num<<endl;
    }
    cout<<endl;
}

void buildheap(STU arr[],int n){
	for(int i = n / 2 - 1;i >= 0;i --){//从下往上创建大根堆 
		down(arr,i,n);
	}
}

void Heapsort(STU arr[],int n){
	buildheap(arr,n);
	for(int i = n - 1;i >= 0;i --){
		swap(arr[0],arr[i]);//交换顶点与第 i 个节点 
		down(arr,0,i);//将该节点替入堆中 
	}
	cout<<"堆排序后的顺序："<<endl;
	display(arr,n);
}

int main(){
	cout<<"请输入将要输入的学生数量:";
	int n;
	cin>>n;
	STU s[n+10];
	STU pre[n+10];
	for(int i = 0;i < n;i ++){
		cout<<"请输入学生姓名:";
		cin>>s[i].name;
		pre[i].name = s[i].name;
		cout<<"请输入学生植树的数量:";
		cin>>s[i].num;
		pre[i].num = s[i].num;
	}
	cout<<endl;
	cout<<"希尔排序前的顺序："<<endl;
	for(int i = 0;i < n;i ++){
		cout<<s[i].name<<' '<<s[i].num<<endl;
	}
	Shellsort(s,n);
	cout<<endl;
	cout<<"希尔排序后的顺序："<<endl;
	for(int i = 0;i < n;i ++){
		cout<<s[i].name<<' '<<s[i].num<<endl;
	}
	cout<<"请输入你所要查询的次数：";
	int t;
	cin>>t;
	while(t--){
		cout<<"请输入你所需要查询的种植树的数量：";
		int treenum;
		cin>>treenum;
		Search(s,treenum,n);
		cout<<endl;
	}
	cout<<"堆排序前的顺序："<<endl;
	for(int i = 0;i < n;i ++){
		cout<<pre[i].name<<' '<<pre[i].num<<endl;
	}
	cout<<endl;
	Heapsort(pre,n);
	cout<<endl;
	cout<<"种树最多的前三位同学是："<<endl;
	for(int i = n-1;i >= n-3;i --){
		cout<<pre[i].name<<' '<<pre[i].num<<endl;
	}
	return 0;
} 

/*
测试数据 
10
a 10
b 7
c 9
d 5
e 13
f 100
g 97
h 7
i 13
j 15
5
7
9
18
13
17
*/

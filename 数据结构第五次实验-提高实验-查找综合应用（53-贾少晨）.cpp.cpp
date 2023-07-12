/*
ֲ���ڣ�����˳���洢�ṹ��¼־Ը�ߵ�������ֲ������������Ƴ���Ҫ��ʵ�֣�
��1������ϣ�������ų�һ���ǵݼ������������ʾ����Ӧ���۰���ҷ�����������в��Ҹ�������������������ʾ�����ڱ���λ�á�
��2�����ö����򷽷�ʵ�����ֲ������ǰ����־Ը�ߵ�������ֲ��������
2111310110 ����2102 53-���ٳ� 
*/

#include <iostream>
using namespace std;

typedef struct{
	string name;//ѧ������ 
	int num;//ѧ��ֲ������ 
}STU;

////////////////////////////ϣ������////////////////////////////////
void Shellsort(STU s[],int n){
	for(int gap = n >> 1;gap > 0;gap >>= 1){//���ò��� 
		for(int i = gap;i < n;i ++){
			STU tmp = s[i];
			int j = i - gap;
			while(j >= 0 && s[j].num > tmp.num){//���� 
				s[j + gap] = s[j];
				j -= gap;
			}
			s[j + gap] = tmp;
		}
	}
}

////////////////////////////�۰����////////////////////////////////
void Search(STU s[],int treenum,int n){
	int l = 0,r = n;
	while(l < r){
		int mid = l + r >> 1;
		if(s[mid].num > treenum)r = mid;//�����ǰ�е�ֵ > ����ֵ����С�Ҷ˵㡣 
		else l = mid + 1;//��֮������˵� 
	}
	if(s[l-1].num == treenum){
		cout<<"�����ҵ�ѧ��Ϊ:"<<s[l-1].name<<endl;
		cout<<"�ڵ�ǰ���е�λ��Ϊ��"<<l<<"λ"<<endl; 
	}
	else cout<<"��ǰû��ѧ����ֲ������Ҫ��ѯ����������"<<endl;
}

////////////////////////////������//////////////////////////////////

void down(STU arr[],int i,int n){//�����ת�� 
	int par = i;//��¼���ڵ���±� 
	int cld = 2 * i + 1;//��¼�ӽڵ��±� 
	while(cld < n){
		if(cld + 1 < n && arr[cld].num < arr[cld + 1].num){//�ж������ӽڵ� 
			cld++;
		}
		if(arr[par].num < arr[cld].num){//�Ƿ񽻻��Ӹ��ڵ� 
			swap(arr[par],arr[cld]);
			par = cld;
		}
		cld = cld * 2 + 1;//�Ƚ�֮����Ӹ��ڵ� 
	}
}

void display(STU arr[], int n){//��ӡ���� 
    for(int i = 0; i < n; i++){
        cout<<arr[i].name<<' '<<arr[i].num<<endl;
    }
    cout<<endl;
}

void buildheap(STU arr[],int n){
	for(int i = n / 2 - 1;i >= 0;i --){//�������ϴ�������� 
		down(arr,i,n);
	}
}

void Heapsort(STU arr[],int n){
	buildheap(arr,n);
	for(int i = n - 1;i >= 0;i --){
		swap(arr[0],arr[i]);//����������� i ���ڵ� 
		down(arr,0,i);//���ýڵ�������� 
	}
	cout<<"��������˳��"<<endl;
	display(arr,n);
}

int main(){
	cout<<"�����뽫Ҫ�����ѧ������:";
	int n;
	cin>>n;
	STU s[n+10];
	STU pre[n+10];
	for(int i = 0;i < n;i ++){
		cout<<"������ѧ������:";
		cin>>s[i].name;
		pre[i].name = s[i].name;
		cout<<"������ѧ��ֲ��������:";
		cin>>s[i].num;
		pre[i].num = s[i].num;
	}
	cout<<endl;
	cout<<"ϣ������ǰ��˳��"<<endl;
	for(int i = 0;i < n;i ++){
		cout<<s[i].name<<' '<<s[i].num<<endl;
	}
	Shellsort(s,n);
	cout<<endl;
	cout<<"ϣ��������˳��"<<endl;
	for(int i = 0;i < n;i ++){
		cout<<s[i].name<<' '<<s[i].num<<endl;
	}
	cout<<"����������Ҫ��ѯ�Ĵ�����";
	int t;
	cin>>t;
	while(t--){
		cout<<"������������Ҫ��ѯ����ֲ����������";
		int treenum;
		cin>>treenum;
		Search(s,treenum,n);
		cout<<endl;
	}
	cout<<"������ǰ��˳��"<<endl;
	for(int i = 0;i < n;i ++){
		cout<<pre[i].name<<' '<<pre[i].num<<endl;
	}
	cout<<endl;
	Heapsort(pre,n);
	cout<<endl;
	cout<<"��������ǰ��λͬѧ�ǣ�"<<endl;
	for(int i = n-1;i >= n-3;i --){
		cout<<pre[i].name<<' '<<pre[i].num<<endl;
	}
	return 0;
} 

/*
�������� 
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

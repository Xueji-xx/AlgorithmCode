/*
��̽�������ͼ���ڽӾ���洢�ṹ��ʵ��ͼ�Ĺ�����������㷨��
(1)�����ڽӾ���洢�ṹ����һ������ͼ��
(2)ͼ�Ĺ�����������㷨��ʵ�֡�
2111310110 53 ���ٳ� 
*/

#include <iostream>
using namespace std;

#define MAXM 100
#define INF 0x3f
typedef char VerType;
typedef int EdgeType;

typedef struct {
	VerType v[MAXM];//���㼯�� 
	EdgeType e[MAXM][MAXM];//�߼���
	int vernum,arcnum;//������������ 
}Graph;

bool vis[MAXM];

void print(Graph g,int i){
	cout<<g.v[i]<<' ';//������� 
}

int Firstnei(Graph g,int v){
	for(int i = 0;i < g.vernum;i ++){//�ҵ� v ����ĵ�һ�����ڽڵ� 
		if(g.e[v][i] == 1)return i;
	}
	return -1;//�����ڶ��� 
}

int Nextnei(Graph g,int v,int w){
	for(int i = w + 1;i < g.vernum;i ++){
		if(g.e[v][i] == 1)return i;
	}
	return -1;
}

void BFS(Graph g, int v){
    int Queue[g.vernum];
    int front = -1, rear = -1;//����һ�����������������
    int w;
    print(g ,v);
    vis[v] = 1; //��¼v�Ŷ����Ѿ�������
    Queue[++rear] = v;//����ǰ�������
    while(front != rear){
        v = Queue[++front]; //����Ԫ�س���
        for(w = Firstnei(g, v); w >= 0; w = Nextnei(g, v, w)){
            if(vis[w] == 0){
                print(g, w);
                vis[w] = 1;
                Queue[++rear] = w;
            }
        }
    }
}

void BFSTraverse(Graph g){
    for(int i = 0; i < g.vernum; i++){//��ʼ���������飬0������δ�����ʣ�1�����Ѿ�����
        vis[i] = false;
    }
    for(int i = 0; i < g.vernum; i++){//���Ƿ���ͨͼ���������ͨ���������ܴ���1
        if(!vis[i]){
            BFS(g, i);
        }
    }
}

int main(){
	Graph g;
	//��������ͼ
	g.vernum = 7;
	g.arcnum = 8; 
	char ver[7] = {'1', '2', '3', '4', '5', '6', '7'};
    for(int i = 0; i < g.vernum; i++){
        g.v[i] = ver[i];
    }
    int edge[7][7] = {
            0,INF,1,1,INF,1,INF,
            INF,0,INF,INF,1,INF,1,
            1,INF,0,INF,1,INF,INF,
            1,INF,INF,0,1,INF,INF,
            INF,1,1,1,0,INF,INF,
            1,INF,INF,INF,INF,0,1,
            INF,1,INF,INF,INF,1,0
    };
	for(int i = 0; i < g.vernum; i++){
        for(int j = 0; j < g.vernum; j++){
            g.e[i][j] = edge[i][j];
        }
    }
    /*cout<<"������ڵ�����";
	cin>>g.vernum;
	cout<<"�����������";
	cin>>g.arcnum;
	cout<<"������ߣ�"; 
	for(int i = 0; i < g.vernum; i++){
        g.v[i] = (char)i;
    }
	for(int i = 0; i < g.vernum; i++){
        for(int j = 0; j < g.vernum; j++){
            g.e[i][j] = INF;
        }
    }
    for(int i = 0;i < g.arcnum;i ++){
    	int a,b;
    	cin>>a>>b;
    	g.e[a][b] = g.e[b][a] = 1;
	}*/
    BFSTraverse(g);
	return 0;
}

/*
编程建立无向图的邻接矩阵存储结构，实现图的广度优先搜索算法。
(1)采用邻接矩阵存储结构创建一个无向图。
(2)图的广度优先搜索算法的实现。
2111310110 53 贾少晨 
*/

#include <iostream>
using namespace std;

#define MAXM 100
#define INF 0x3f
typedef char VerType;
typedef int EdgeType;

typedef struct {
	VerType v[MAXM];//顶点集合 
	EdgeType e[MAXM][MAXM];//边集合
	int vernum,arcnum;//顶点数、弧数 
}Graph;

bool vis[MAXM];

void print(Graph g,int i){
	cout<<g.v[i]<<' ';//输出顶点 
}

int Firstnei(Graph g,int v){
	for(int i = 0;i < g.vernum;i ++){//找到 v 顶点的第一个相邻节点 
		if(g.e[v][i] == 1)return i;
	}
	return -1;//无相邻顶点 
}

int Nextnei(Graph g,int v,int w){
	for(int i = w + 1;i < g.vernum;i ++){
		if(g.e[v][i] == 1)return i;
	}
	return -1;
}

void BFS(Graph g, int v){
    int Queue[g.vernum];
    int front = -1, rear = -1;//定义一个队列来保存各顶点
    int w;
    print(g ,v);
    vis[v] = 1; //记录v号顶点已经被访问
    Queue[++rear] = v;//将当前顶点入队
    while(front != rear){
        v = Queue[++front]; //队首元素出队
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
    for(int i = 0; i < g.vernum; i++){//初始化访问数组，0代表顶点未被访问，1代表已经访问
        vis[i] = false;
    }
    for(int i = 0; i < g.vernum; i++){//考虑非连通图的情况，连通分量数可能大于1
        if(!vis[i]){
            BFS(g, i);
        }
    }
}

int main(){
	Graph g;
	//构建无向图
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
    /*cout<<"请输入节点数：";
	cin>>g.vernum;
	cout<<"请输入边数：";
	cin>>g.arcnum;
	cout<<"请输入边："; 
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

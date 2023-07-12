#include<iostream>
using namespace std;
const int N = 5e6+50;

struct Node{
    int l,r;
    int lmax,rmax;
    int sum;
    int tmax;
}tr[N*4];

void pushup(Node &u,Node &l,Node &r){
    u.sum = l.sum + r.sum;
    u.lmax = max(l.lmax,l.sum + r.lmax);
    u.rmax = max(r.rmax,r.sum + l.rmax);
    u.tmax = max(max(l.tmax,r.tmax),l.rmax + r.lmax);
}

void pushup(int u){
    pushup(tr[u],tr[u << 1],tr[u << 1 | 1]);
}

void build(int u,int l,int r){
    if(l == r)tr[u] = {l,r,w[r],w[r],w[r],w[r]};
    else{
        tr[u] = {l,r};
        int mid = l + r >> 1;
        build(u << 1,l,mid);build(u << 1,mid + 1,r);
        pushup(u);
    }
}

void modify(int u,int x,int v){
    
}

int main(){

    return 0;
}
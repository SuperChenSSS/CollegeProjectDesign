#ifndef DIJ_H
#define DIJ_H

#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <QString>
using namespace std;
const int INF = 1000000000;
const int maxn = 1e6;
int len;
int startg,endg;
QString name[20] = {"","通达","扬大","汇金谷","顺达","三湾湿地",
                  "万达","宝龙","京华城","三盛","荷花池",
                   "火车站","文昌阁","凯德","双博馆","东关街",
                   "茱萸湾","瘦西湖"};
struct qnode
{
    int v,c;
    qnode(int _v=0,int _c=0):v(_v),c(_c){}
    bool operator <(const qnode &r)const
    {
        return c>r.c;
    }
};
struct Edge
{
    int v,cost;
    Edge(int _v=0,int _cost=0):v(_v),cost(_cost){}
};
vector<Edge> E[maxn];
int path[maxn];//记录路径
bool vis[maxn];
int dist[maxn];
int previous[maxn];
void Dij(int n,int startg)//点的编号从1开始
{
    memset(vis,false,sizeof(vis));
    for(int i=1;i<=n;i++)
        dist[i] = INF;
    priority_queue<qnode> que;
    dist[startg] = 0;
    que.push(qnode(startg,0));
    qnode tmp;
    while(!que.empty())
    {
        tmp = que.top();
        que.pop();
        int u = tmp.v;
        if(vis[u])
            continue;
        vis[u] = true;
        for(int i=0;i<E[u].size();i++)
        {
            int v = E[tmp.v][i].v;
            int cost = E[u][i].cost;
            if(!vis[v]&&dist[v]>dist[u]+cost)
            {
                dist[v] = dist[u] + cost;
                previous[v] = u;
                que.push(qnode(v,dist[v]));
            }
        }
    }
}
void addedge(int u,int v,int w)
{
    E[u].push_back(Edge(v,w));
    E[v].push_back(Edge(u,w));
}
void init()
{
    memset(E, 0, sizeof(E));
    memset(dist,0,sizeof(dist));
    memset(previous,0,sizeof(previous));
}
QString searchPath(int v, int u)
{
    if(v == u)
        return "无路径";
    QString result = "所选取的路径为：";
    int que[maxn];
    int tot = 1;
    que[tot] = u;
    tot++;
    int tmp = previous[u];
    while(tmp != v)
    {
        que[tot] = tmp;
        tot++;
        tmp = previous[tmp];
    }
    que[tot] = v;
    for(int i=tot; i>=1; --i)
        if(i != 1)
            result += name[que[i]] + " -> ";
            //cout << que[i] << " -> ";
        else
            result += name[que[i]];
            //cout << que[i] << endl;
    return result;
}
/*int main()
{
    cin>>n>>m;
    init();
    for(int i=0;i<m;i++)
    {
        cin>>from>>to>>len;
        addedge(from, to, len);
    }
    cout<<"Please input startg:"<<endl;
    cin>>startg;
    cout<<"Please input end:"<<endl;
    cin>>end;
    Dij(n, startg,previous);
    cout<<dist[end]<<endl;
    searchPath(previous, startg, end);
    return 0;
}*/

#endif // DIJ_H

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <functional>
#include <algorithm>
using namespace std;

struct Node{
    int v,g,f;
    bool operator>(const Node&o)const{return f>o.f;}
};

auto buildGraph(){
    return vector<vector<pair<int,int>>>{
        {{1, 2}, {2, 4}},
        {{0, 2}, {2, 1}, {3, 7}},
        {{0, 4}, {1, 1}, {3, 3}, {4, 5}},
        {{1, 7}, {2, 3}, {4, 2}},
        {{2, 5}, {3, 2}}
    };
}

vector<int> heuristic={7,6,2,1,0};

int main(){
    auto g=buildGraph();
    int start=0, goal=4, n=g.size();
    vector<int> gCost(n, INT_MAX), parent(n, -1);
    priority_queue<Node, vector<Node>, greater<Node>> pq;
    gCost[start]=0;
    pq.push({start, 0, heuristic[start]});
    while(!pq.empty()){
        auto cur=pq.top(); pq.pop();
        if(cur.v==goal) break;
        if(cur.g>gCost[cur.v]) continue;
        for(auto &e: g[cur.v]){
            int tg=cur.g+e.second;
            if(tg<gCost[e.first]){
                gCost[e.first]=tg;
                parent[e.first]=cur.v;
                pq.push({e.first, tg, tg+heuristic[e.first]});
            }
        }
    }
    vector<int> path;
    for(int v=goal; v!=-1; v=parent[v]) path.push_back(v);
    reverse(path.begin(), path.end());
    cout<<"A* Path: ";
    for(int i=0;i<path.size();i++) cout<<path[i]<<(i+1<path.size()?" -> ":"");
    cout<<" | Cost: "<<gCost[goal]<<"\n";
}

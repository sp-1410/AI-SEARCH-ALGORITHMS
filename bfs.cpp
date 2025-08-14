#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

auto buildGraph(){
    return vector<vector<pair<int,int>>>{
        {{1, 2}, {2, 4}},
        {{0, 2}, {2, 1}, {3, 7}},
        {{0, 4}, {1, 1}, {3, 3}, {4, 5}},
        {{1, 7}, {2, 3}, {4, 2}},
        {{2, 5}, {3, 2}}
    };
}

int main(){
    auto g = buildGraph();
    int start=0, goal=4, n=g.size();
    vector<int> dist(n, INT_MAX), parent(n,-1);
    dist[start]=0;
    using P=pair<int,int>;
    priority_queue<P, vector<P>, greater<P>> pq;
    pq.push({0,start});
    while(!pq.empty()){
        auto [d,u]=pq.top(); pq.pop();
        if(u==goal) break;
        if(d>dist[u]) continue;
        for(auto &e: g[u]){
            if(dist[u]+e.second < dist[e.first]){
                dist[e.first] = dist[u]+e.second;
                parent[e.first] = u;
                pq.push({dist[e.first], e.first});
            }
        }
    }
    vector<int> path;
    for(int v=goal; v!=-1; v=parent[v]) path.push_back(v);
    reverse(path.begin(), path.end());
    cout << "BFS Cost Path: ";
    for(int i=0;i<path.size();i++) cout<<path[i]<<(i+1<path.size()?" -> ":"");
    cout << " | Cost: " << dist[goal] << "\n";
}

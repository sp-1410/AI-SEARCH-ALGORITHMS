#include <iostream>
#include <vector>
#include <queue>
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

vector<int> heuristic={7, 6, 2, 1, 0};

int main(){
    auto g = buildGraph();
    int start=0, goal=4;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({heuristic[start],start});
    vector<int> parent(g.size(), -1);
    while(!pq.empty()){
        auto [h,u]=pq.top(); pq.pop();
        if(u == goal) break;
        for(auto &e : g[u]){
            parent[e.first] = u;
            pq.push({heuristic[e.first], e.first});
        }
    }
    vector<int> path;
    for(int v=goal; v!=-1; v=parent[v]) path.push_back(v);
    reverse(path.begin(), path.end());
    cout << "HC Path: ";
    for(int i=0;i<path.size();i++) cout<<path[i]<<(i+1<path.size()?" -> ":"");
    cout << "\n";
}

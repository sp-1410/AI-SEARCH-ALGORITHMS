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

int main(){
    auto g = buildGraph();
    int start=0, goal=4;
    vector<bool> visited(g.size(), false);
    vector<int> parent(g.size(), -1);
    queue<int> q;
    visited[start]=true; q.push(start);
    while(!q.empty()){
        int u = q.front(); q.pop();
        if(u==goal) break;
        for(auto &e : g[u])
            if(!visited[e.first]){
                visited[e.first]=true;
                parent[e.first] = u;
                q.push(e.first);
            }
    }
    vector<int> path;
    for(int v=goal; v!=-1; v=parent[v]) path.push_back(v);
    reverse(path.begin(), path.end());
    cout << "BFS+History Path: ";
    for(int i=0;i<path.size();i++) cout<<path[i]<<(i+1<path.size()?" -> ":"");
    cout << "\n";
}

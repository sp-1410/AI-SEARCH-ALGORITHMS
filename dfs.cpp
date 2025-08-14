#include <iostream>
#include <vector>
#include <set>
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

int start=0, goal=4;
vector<int> path;
set<int> visited;

bool dfs(const vector<vector<pair<int,int>>> &g, int node){
    path.push_back(node);
    if(node==goal) return true;
    visited.insert(node);
    for(auto &e: g[node])
        if(!visited.count(e.first) && dfs(g, e.first)) return true;
    path.pop_back();
    return false;
}

int main(){
    auto g=buildGraph();
    if(dfs(g, start)){
        cout << "DFS Path: ";
        for(int i=0;i<path.size();i++)
            cout<<path[i]<<(i+1<path.size()?" -> ":"");
        cout<<"\n";
    } else cout << "No Path\n";
}

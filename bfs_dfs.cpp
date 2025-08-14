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
bool dls(const vector<vector<pair<int,int>>> &g, int node, int depth, set<int> &visited, vector<int> &path){
    path.push_back(node);
    if(node == goal) return true;
    if(depth==0){ path.pop_back(); return false; }
    visited.insert(node);
    for(auto &e : g[node])
        if(!visited.count(e.first) && dls(g, e.first, depth-1, visited, path)) return true;
    path.pop_back();
    return false;
}

int main(){
    auto g = buildGraph();
    for(int limit=0; limit<g.size(); limit++){
        set<int> visited;
        vector<int> path;
        if(dls(g, start, limit, visited, path)){
            cout << "IDDFS Path: ";
            for(int i=0;i<path.size();i++) cout<<path[i]<<(i+1<path.size()?" -> ":"");
            cout << "\n"; break;
        }
    }
}

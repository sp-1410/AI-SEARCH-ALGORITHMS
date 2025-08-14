#include <iostream>
#include <vector>
#include <set>
#include <climits>
using namespace std;

auto buildGraph(){
    return vector<vector<pair<int,int>>>{
        {{1,2},{2,4}},
        {{0,2},{2,1},{3,7}},
        {{0,4},{1,1},{3,3},{4,5}},
        {{1,7},{2,3},{4,2}},
        {{2,5},{3,2}}
    };
}

vector<int> heuristic={7,6,2,1,0};
int start=0, goal=4, bound=8;
vector<int> bestPath, curPath;

void dfsCHBB(const vector<vector<pair<int,int>>> &g, int node, set<int> vis, int cost){
    int est = cost + heuristic[node];
    if(est > bound) return;
    curPath.push_back(node);
    if(node==goal){bestPath=curPath; bound=cost;}
    else{
        vis.insert(node);
        for(auto &e: g[node])
            if(!vis.count(e.first))
                dfsCHBB(g, e.first, vis, cost+e.second);
    }
    curPath.pop_back();
}

int main(){
    auto g=buildGraph();
    dfsCHBB(g, start, {}, 0);
    cout<<"Cost+Heuristics+BB Path: ";
    for(int i=0;i<bestPath.size();i++) cout<<bestPath[i]<<(i+1<bestPath.size()?" -> ":"");
    cout<<" | Cost: "<<bound<<"\n";
}

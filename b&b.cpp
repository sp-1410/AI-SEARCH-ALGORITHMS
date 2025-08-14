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

int start=0, goal=4;
int bestCost=8; // from oracle
vector<int> bestPath, curPath;

void dfsBB(const vector<vector<pair<int,int>>> &g, int node, set<int> vis, int cost){
    if(cost > bestCost) return;
    curPath.push_back(node);
    if(node==goal){
        if(cost < bestCost){ bestCost=cost; bestPath=curPath; }
    } else {
        vis.insert(node);
        for(auto &e: g[node])
            if(!vis.count(e.first))
                dfsBB(g, e.first, vis, cost+e.second);
    }
    curPath.pop_back();
}

int main(){
    auto g=buildGraph();
    dfsBB(g, start, {}, 0);
    cout<<"Branch&Bound Path: ";
    for(int i=0;i<bestPath.size();i++)
        cout<<bestPath[i]<<(i+1<bestPath.size()?" -> ":"");
    cout<<" | Cost: "<<bestCost<<"\n";
}

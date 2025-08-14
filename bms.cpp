#include <iostream>
#include <vector>
#include <set>
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

int start=0, goal=4, bestCost=INT_MAX;
vector<int> bestPath, curPath;

void dfsAll(const vector<vector<pair<int,int>>> &g, int node, set<int> visited, int cost){
    curPath.push_back(node);
    if(node==goal){
        if(cost < bestCost){
            bestCost = cost;
            bestPath = curPath;
        }
    } else {
        visited.insert(node);
        for(auto &e: g[node])
            if(!visited.count(e.first))
                dfsAll(g, e.first, visited, cost + e.second);
    }
    curPath.pop_back();
}

int main(){
    auto g = buildGraph();
    dfsAll(g, start, {}, 0);
    cout << "BMS Path: ";
    for(int i=0;i<bestPath.size();i++)
        cout<<bestPath[i]<<(i+1<bestPath.size()?" -> ":"");
    cout << " | Cost: " << bestCost << "\n";
}

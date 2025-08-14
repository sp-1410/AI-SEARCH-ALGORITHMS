#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
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
vector<bool> visited;

int main(){
    auto g=buildGraph();
    visited.assign(g.size(), false);
    int start=0, goal=4, beamWidth=2;
    vector<int> parent(g.size(), -1);
    vector<int> frontier={start};
    visited[start]=true;

    while(!frontier.empty()){
        sort(frontier.begin(), frontier.end(),
             [&](int a,int b){return heuristic[a] < heuristic[b];});
        if((int)frontier.size()>beamWidth) frontier.resize(beamWidth);
        vector<int> next;
        for(int u:frontier){
            if(u==goal) goto done;
            for(auto &e: g[u]){
                if(!visited[e.first]){
                    visited[e.first]=true;
                    parent[e.first]=u;
                    next.push_back(e.first);
                }
            }
        }
        frontier=next;
    }
done:
    vector<int> path;
    for(int v=goal; v!=-1; v=parent[v]) path.push_back(v);
    reverse(path.begin(), path.end());
    cout<<"BS+History Path: ";
    for(int i=0;i<path.size();i++) cout<<path[i]<<(i+1<path.size()?" -> ":"");
    cout<<"\n";
}

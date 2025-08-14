#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

struct Node{
    int v,g,f;
    vector<int> path;
    bool operator>(const Node &o) const {return f>o.f;}
};

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

int main(){
    auto g=buildGraph();
    int start=0, goal=4, best=8;
    priority_queue<Node,vector<Node>,greater<Node>> open;
    set<pair<int,int>> closed;
    open.push({start,0,heuristic[start],{start}});
    while(!open.empty()){
        auto cur=open.top(); open.pop();
        if(cur.g > best) continue;
        if(cur.v==goal && cur.g<best){best=cur.g; break;}
        if(closed.count({cur.v,cur.g})) continue;
        closed.insert({cur.v,cur.g});
        for(auto &e: g[cur.v]){
            Node nxt={e.first,cur.g+e.second,cur.g+e.second+heuristic[e.first],cur.path};
            nxt.path.push_back(e.first);
            open.push(nxt);
        }
    }
    cout<<"BB+Heuristics+List best cost: "<<best<<"\n";
}

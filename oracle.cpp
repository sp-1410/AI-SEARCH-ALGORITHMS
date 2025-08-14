#include <iostream>
#include <vector>
using namespace std;

int main(){
    // Precomputed shortest path: 0 -> 1 -> 2 -> 3 -> 4 (Cost 8)
    vector<int> path={0,1,2,3,4};
    int cost = 2 + 1 + 3 + 2; // sum of edges
    cout<<"Oracle Path: ";
    for(int i=0; i<path.size(); i++)
        cout<<path[i]<<(i+1<path.size()?" -> ":"");
    cout<<" | Cost: "<<cost<<"\n";
}

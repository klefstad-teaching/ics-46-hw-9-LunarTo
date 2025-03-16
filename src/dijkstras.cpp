#include "dijkstras.h"
#include <algorithm>
#include <queue>

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous){
    int numVertices = G.size();
    vector<int> distances(numVertices,INF);
    vector<bool> visited(numVertices,false);

    distances[source] = 0;

    //this is set equal to undefined, but undefined wont work
    previous[source] = 0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minHeap;
    minHeap.push({source,0});

    while(!minHeap.empty()){
        //implementation might be different
        int u = minHeap.top().first;
        minHeap.pop();

        if(visited[u]) continue;
        visited[u] = true;

        for(Edge edge: G[u]){
            int v = edge.dst;
            int weight = edge.weight;

            if(!visited[v] && distances[u] + weight < distances[v]){
                distances[v] = distances[u] + weight;
                previous[v] = u;
                minHeap.push({v,distances[v]});
            }
        }
    }
    return distances;
}

vector<int> extract_shortest_path(const vector<int>& distances, const vector<int>& previous, int destination){
    vector<int> shortPath;

    //check -1 for predecessor
    for(int i = destination; i != -1; i = previous[i]){
        if(distances[i] != 0){
            shortPath.push_back(i);
        }
    }

    reverse(shortPath.begin(),shortPath.end());

    return shortPath;
}

//what does print path do, and what does the total do 
void print_path(const vector<int>& v, int total){
    for (int node : v){
        cout << node <<" ";
    }
    cout << endl;
    cout << "Total cost is " <<  total << endl;
}
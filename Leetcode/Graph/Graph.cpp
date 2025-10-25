#include<iostream>
#include<queue>
#include<vector>
using namespace std;


void dfs(int node, vector<int> adj[], vector<int> &visited) {
    //node = current node , adj[] = adj list of the graph, visited = checks the visited node
    visited[node] = 1;     // mark the current node as visited
    cout << node << " " << endl;    // process the node

    for(int neighbors : adj[node]) {
        //loop over the the current neighbor , if neighbor is not visited run dfs
        if(!visited[neighbors]) {
            dfs(neighbors, adj, visited);
        }
    }
}
void bfs(int source, vector<int> adj[], int n) {
    // source = starting node, adj[] = adj list of the graph, n = number of nodes
    vector<int> visited{n, 0};  //Initialize a visited to check visited node
    queue<int> q;   //Queue to keep track of the node level by level

    visited[source] = 1;    // Mark the source as visited
    q.push(source);     // Push the source in queue

    cout << "BFS starting from node" << source << endl;

    while(!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << endl;
        for(int neighbor: adj[node]) {
            if(!visited[neighbor]) {
                visited[neighbor] = 1;
                q.push(neighbor);
            }
        }
    }
}

int main () {
    int n = 5;
    vector<int> adj[n];
    adj[0] = {1,2};
    adj[1] = {0, 3, 4};
    adj[2] = {0};
    adj[3] = {1};
    adj[4] = {1};
    vector<int> visited(n, 0);

    cout << "Dfs" << endl;
    dfs(0, adj, visited);
    
    cout << "bfs" << endl;
    bfs(0, adj,n);
}
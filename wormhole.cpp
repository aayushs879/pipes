#include <iostream>
#define INT_MAX 1e8
using namespace std;
int v;
/// a structure to store (x, y) oordinates
struct node{
    int x; 
    int y;
};



/// utility function to calculate distance between two nodes which are not a wormhole
int dist(node a, node b){
    return (abs(a.x - b.x) + abs(a.y - b.y));
}


// for dijkstra 
int minDistance(int dist[], bool sptSet[]) 
{ 
    
    int min = INT_MAX, min_index; 
  
    for (int i = 0; i < v; i++) 
        if (sptSet[i] == false && dist[i] <= min) 
            min = dist[i], min_index = i; 
  
    return min_index; 
} 
  

int main(void){
    // Your code here!
    node src;
    node dest;
    
    cin>>src.x>>src.y;
    cin>>dest.x>>dest.y;
    
    int nw;
    cin>> nw;
    v  = 2*nw + 2;
    int adj[v][v];
    node vertices[v];
    vertices[0] = src;
    vertices[v-1] = dest;
    
    int cost[nw];
    for (int i = 0; i < nw; i++){
        int x1, y1, x2, y2, c;
        cin>>x1>>y1>>x2>>y2>>c;
        node a;
        a.x = x1;
        a.y = y1;
        vertices[i+1] = a;
        node b;
        b.x = x1;
        b.y = y1;
        vertices[i+2] = b;
        cost[i] = c;
    }
    
    
    for (int i = 0; i<v; i++ ){
        for(int j = 0 ; j < v; j++){
            
            adj[i][j] = dist(vertices[i], vertices[j]);
            
            if ((i+2)%2 != 0){
                adj[i][i+1] = cost[i-1];
            }
            if ((i+2)%2 == 0 && i != 0){
                adj[i][i-1] = cost[i];
            }
            if(i == j){
                adj[i][j] = -1;
            }
            
        }
    }
    
    
    
    int dist[v];  
  
    bool sptSet[v]; 
  
    
    for (int i = 0; i < v; i++) 
        dist[i] = INT_MAX, sptSet[i] = false; 
  
    
    dist[0] = 0; 
  
    // Find shortest path for all vertices 
    for (int count = 0; count < v - 1; count++) { 
        // Pick the minimum distance vertex from the set of vertices not 
        // yet processed. u is always equal to src in the first iteration. 
        int u = minDistance(dist, sptSet); 
  
        // Mark the picked vertex as processed 
        sptSet[u] = true; 
  
        // Update dist value of the adjacent vertices of the picked vertex. 
        for (int V = 0; V < v; V++) 
  
            // Update dist[v] only if is not in sptSet, there is an edge from 
            // u to v, and total weight of path from src to  v through u is 
            // smaller than current value of dist[v] 
            if (!sptSet[V] && adj[u][V] && dist[u] != INT_MAX 
                && dist[u] + adj[u][V] < dist[V]) 
                dist[V] = dist[u] + adj[u][V]; 
    } 
  
    
    cout<<dist[v-1];
    
}

#include <iostream>
#include <map>
#include <list>

using namespace std;

// Class for a directed graph using
// adjacency list representation
class Graph {
public:
   map<int, bool> visited;
   map<int, list<int>> adj;

   // Add an edge to graph
   void addEdge(int v, int w);

   // DFS traversal of the vertices from v
   void DFS(int v);
};

void Graph::addEdge(int v, int w) {
   // Add w to v's list
   adj[v].push_back(w);
}

void Graph::DFS(int v) {
   // Mark the current node as visited
   visited[v] = true;
   cout << v << " ";

   // Recur for all the vertices adjacent to this vertex
   list<int>::iterator i;
   for (i = adj[v].begin(); i != adj[v].end(); ++i)
       if (!visited[*i])
           DFS(*i);
}

int main() {
   Graph g;

   int ch{};
   do {
       cout << "\n----------------MENU----------------\n";
       cout << "1. Add edge\n2. Perform DFS traversal\n3. Exit\n";
       cout << "Enter choice: ";
       cin >> ch;
       switch (ch) {
           case 1:
               int firstVertex, secondVertex;
               cout << "Enter first vertex: ";
               cin >> firstVertex;
               cout << "Enter second vertex: ";
               cin >> secondVertex;
               g.addEdge(firstVertex, secondVertex);
               cout << "Edge added from vertex " << firstVertex
                    << " to vertex " << secondVertex << endl;
               break;
           case 2:
               cout << "Enter vertex: ";
               cin >> firstVertex;
               cout << "Following is Depth First Traversal(starting from vertex "
                    << firstVertex << "):\n";
               g.DFS(firstVertex);
               cout << endl;
               break;
           case 3:
               cout << "Exiting...\n";
               break;
           default:
               cout << "Invalid choice!\n";
       }
   } while (ch != 3);

   return 0;
}
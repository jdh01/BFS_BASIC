#include <iostream>
#include <list>

class Graph {
private:
	//No. verticies
	int V;
	//Pointer to adjacency list
	std::list<int> *adj;
public:
	//Constructor prototype
	Graph(int v);
	//Method to add an edge
	void addEdge(int v, int w);
	//Method for BFS traveral from source 's'
	void BFS(int s);
};

//Constructor
Graph::Graph(int v) {
	//Setting no. verticies
	V = v;
	//Creating adjacency list for each vertex
	adj = new std::list<int>[v];
}

//Implemeting method to add edges
void Graph::addEdge(int v, int w) {
	adj[v].push_back(w);
}

//Perform BFS
void Graph::BFS(int s) {
	//Check if we have visited a node
	bool* visited = new bool[V];
	for (int i = 0; i < V; i++) {
		visited[i] = false;
	}
	//Create a queue for BFS
	std::list<int> queue;
	//Starting vertex marked as visited and added to queue
	visited[s] = true;
	queue.push_back(s);
	//Continue until queue is empty
	while (!queue.empty()) {
		//Get the front of the queue and remove it
		s = queue.front();
		queue.pop_front();
		//Get all adjacent verticies from that vertex
		std::cout << "Checking adjacent verticies for vertex" << s << std::endl;
		for (auto i = adj[s].begin(); i != adj[s].end(); i++) {
			//Looking at nodes not yet visited
			if (!visited[*i]) {
				//Mark as visited
				std::cout << "Visit and enqueue" << *i << std::endl;
				visited[*i] = true;
				//Push back and check this vertex vertices
				queue.push_back(*i);
			}
		}
	}
}

int main() {
	Graph g(6);

	g.addEdge(0, 1);
	g.addEdge(0, 2);

	g.addEdge(1, 0);
	g.addEdge(1, 3);
	g.addEdge(1, 4);

	g.addEdge(2, 0);
	g.addEdge(2, 4);

	g.addEdge(3, 1);
	g.addEdge(3, 4);
	g.addEdge(3, 5);

	g.addEdge(4, 1);
	g.addEdge(4, 2);
	g.addEdge(4, 3);
	g.addEdge(4, 5);

	g.addEdge(5, 3);
	g.addEdge(5, 4);

	g.BFS(2);
}
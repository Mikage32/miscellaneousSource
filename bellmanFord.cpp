#include <iostream>

using namespace std;

struct edge {
	int source;
	int distination;
	long long length;
};

struct node {
	long long distance;
	int predecessor;
	bool distanceIsNotInf;
};

//0始まりでフォーマットして入力すること.返値は距離と, 負の重みの閉路があればtrue.
pair<long long, bool> bellmanFord(node* nodes, int numOfNodes, edge* edges, int numOfEdges, int startAt, int endAt) noexcept {
	bool minusCycle = false;

	//relax
	for (int i = 0; i < numOfNodes - 1; ++i) {
		for (int j = 0; j < numOfEdges; ++j) {
			int u = edges[j].source;
			int v = edges[j].distination;

			if (!nodes[v].distanceIsNotInf || nodes[v].distance > nodes[u].distance + edges[j].length) {
				nodes[v].distance = nodes[u].distance + edges[j].length;
				nodes[v].predecessor = u;
				nodes[v].distanceIsNotInf = true;
			}
		}
	}

	//閉路の確認
    for(int i = 0; i < numOfEdges; ++i){
        int u = edges[i].source;
		int v = edges[i].distination;

		if (!nodes[v].distanceIsNotInf || nodes[v].distance > nodes[u].distance + edges[i].length) {
			minusCycle = true;
			break;
		}
    }

	return pair<long long, bool>(nodes[endAt].distance, minusCycle);
}

int main(){
    int n, m;
    cin >> n >> m;
    node* nodes;
    edge* edges;
    nodes = new node[n];
    edges = new edge[m];
    memset(nodes, 0, sizeof(node)*n);

    for(int i = 0; i < m; ++i) cin >> edges[i].source >> edges[i].distination >> edges[i].length;

    int start, end;
    cin >> start >> end;
    pair<long long, bool> t = bellmanFord(nodes, n, edges, m, start, end);
    if(t.second){
        cout << "This graph include minus cycle." << "\n";
    }else{
        cout << t.first << "\n";
    }
}
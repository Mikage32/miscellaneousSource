#include <iostream>

using namespace std;

//ワーシャルフロイド法で連続グラフの各ノード間の距離を求める.
void warshallFloyd(int** graph, int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (graph[j][i] == -1) continue;
			for (int k = 0; k < n; ++k) {
				if (graph[i][k] == -1)continue;
				else if (graph[j][k] == -1) graph[j][k] = graph[j][i] + graph[i][k];
				else graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
			}
		}
	}
}

int main(){
    int n;
    cin >> n;
    int** graph;
    graph = new int*[n];
    for(int i = 0; i < n; ++i) graph[i] = new int[n];

    for(int vertical = 0; vertical < n; ++vertical){
        for(int horizontal = 0; horizontal < n; ++horizontal){
            cin >> graph[vertical][horizontal];
        }
    }

    warshallFloyd(graph, n);

    for(int vertical = 0; vertical < n; ++vertical){
        for(int horizontal = 0; horizontal < n; ++horizontal){
            cout << graph[vertical][horizontal] << " ";
        }
        cout << "\n";
    }

    return 0;
}
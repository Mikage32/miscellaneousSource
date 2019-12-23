#include <iostream>

using namespace std;

//ワーシャルフロイド法で連続グラフの各ノード間の距離を求める.
void warshallFloyd(int** graph, int n) noexcept {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k) {
				graph[j][k] = min(graph[j][k], graph[j][i] + graph[i][k]);
			}
		}
	}
}

int main(){
    int n;
    cin >> n;
    int** graph;
    graph = new int*[n];
    for(int i = 0; i < n; ++i) {
        graph[i] = new int[n];

        for(int j = 0; j < n; ++j) graph[i][j] = 1e9;
    }

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
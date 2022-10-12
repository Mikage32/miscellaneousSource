#include <iostream>
#include <queue>
#include <vector>

#define rep(i, n) for(int i = 0; i < n; ++i)
using ll = long long;
using pii = std::pair<int, int>;
using pli = std::pair<long long, int>;
using pil = std::pair<int, long long>;

const long long INF = 1000000000000000001;

using namespace std;

struct node {
	long long distance;	//距離
	int pre;		//親ノード
	std::vector<std::pair<int, long long>> conected;	//接続先 pair<int, long long>
};
 
void dikstra(node* nodes, int n) {
	std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<std::pair<long long, int>>> que;
	rep(i, n) que.push(std::pair<long long, int>(nodes[i].distance, i));
 
	while (!que.empty()) {
		std::pair<long long, int> pre_node = que.top();
		que.pop();
		auto current_node = &nodes[pre_node.second];
		if (pre_node.first > current_node->distance) continue;

		for(auto i: current_node->conected){
			if (nodes[i.first].distance > current_node->distance + i.second) {
				nodes[i.first].distance = current_node->distance + i.second;
				nodes[i.first].pre = pre_node.second;
 
				que.push(std::pair<long long, int>(nodes[i.first].distance, i.first));
			}
		}
	}
}

int main(){
	int h, w;
	cin >> h >> w;

	string* s = new string[h];
	rep(i, h) std::cin >> s[i];

	int m;
	cin >> m;
	pii* cd = new pii[m];
	rep(i, m) cin >> cd[i].first >> cd[i].second;

	node* nodes = new node[h*w];

	rep(i, h){
		rep(j, w){
			if(i == 0 && j == 0) nodes[i*w+j].distance = 0;
			else nodes[i*w+j].distance = INF;

			if(i != 0	&& s[i - 1][j] == '.') nodes[i*w + j].conected.push_back(pil((i - 1)*w + j, 0));
			if(j != 0	&& s[i][j - 1] == '.') nodes[i*w + j].conected.push_back(pil(i*w + j - 1, 0));
			if(i != h-1	&& s[i + 1][j] == '.') nodes[i*w + j].conected.push_back(pil((i + 1)*w + j, 0));
			if(j != w-1 && s[i][j + 1] == '.') nodes[i*w + j].conected.push_back(pil(i*w + j + 1, 0));
		}
	}
}
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
	ll distance;
	int pre;
	vector<pil> conected;
};
 
void dikstra(node* nodes, int n) {
	priority_queue<pli, vector<pli>, greater<pli>> que;
	rep(i, n) que.push(pli(nodes[i].distance, i));
 
	while (!que.empty()) {
		pli t = que.top();
		que.pop();
		if (t.first > nodes[t.second].distance) continue;
 
		rep(i, nodes[t.second].conected.size()) {
			if (nodes[nodes[t.second].conected[i].first].distance > nodes[t.second].distance + nodes[t.second].conected[i].second) {
				nodes[nodes[t.second].conected[i].first].distance = nodes[t.second].distance + nodes[t.second].conected[i].second;
				nodes[nodes[t.second].conected[i].first].pre = t.second;
 
				que.push(pli(nodes[nodes[t.second].conected[i].first].distance, nodes[t.second].conected[i].first));
			}
		}
	}
}

int main(){
	int h, w;
	cin >> h >> w;

	string* s = new string[h];
	rep(i, h) cin >> s[i];

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
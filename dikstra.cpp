#include <queue>
#include <vector>

#define rep(i, n) for(int i = 0; i < n; ++i)
using ll = long long;
using pli = std::pair<long long, int>;

using namespace std;

struct node {
	ll distance;
	int pre;
	vector<int> conected;
};
 
void dikstra(node* nodes, int n) {
	priority_queue<pli, vector<pli>, greater<pli>> que;
	rep(i, n) que.push(pli(nodes[i].distance, i));
 
	while (!que.empty()) {
		pli t = que.top();
		que.pop();
		if (t.first > nodes[t.second].distance) continue;
 
		rep(i, nodes[t.second].conected.size()) {
			if (nodes[nodes[t.second].conected[i]].distance > nodes[t.second].distance + 1) {
				nodes[nodes[t.second].conected[i]].distance = nodes[t.second].distance + 1;
				nodes[nodes[t.second].conected[i]].pre = t.second;
 
				que.push(pli(nodes[nodes[t.second].conected[i]].distance, nodes[t.second].conected[i]));
			}
		}
	}
}

int main(){
	
}
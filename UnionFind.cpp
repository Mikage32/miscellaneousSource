#include <iostream>
#include <vector>

using namespace std;

typedef class UnionFind {
private:
	int n;
	int* par;
	int* hight;

	int root(int a) {
		while (par[a] != a) a = par[a];
		return a;
	}
public:
	UnionFind(int num) {
		n = num;
		par = new int[n];
		hight = new int[n];
		for (int i = 0; i < n; ++i) {
			par[i] = i;
			hight[i] = 1;
		}
	}
	~UnionFind() {
		delete[] par;
	}

	void unite(int a, int b) {
		int ra = root(a);
		int rb = root(b);
		if (ra == rb) return;
		
		if (hight[ra] > hight[rb]) {
			par[rb] = ra;
		}
		else if (hight[ra] < hight[rb]) {
			par[ra] = rb;
		}
		else {
			par[ra] = rb;
			++hight[rb];
		}
	}
	bool same(int a, int b) {
		return root(a) == root(b);
	}

	int numofRoot() {
		int counter = 0;
		for (int i = 0; i < n; ++i) if (par[i] == i) ++counter;
		return counter;
	}
} Uf;

int main(){
    int n, k;
    cin >> n >> k;
    Uf tree(n);
    for(int i = 0; i < k; ++i){
        int x, a, b;
        cin >> x >> a >> b;
        if(x == 0){
            tree.unite(a, b);
        }else if(x == 1){
            cout << tree.same(a, b) << "\n";
        }else{
            cout << "unDefined command." << "\n";
            --i;
        }
    }

    return 0;
}
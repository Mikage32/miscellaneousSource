#include <iostream>
#include <vector>

using namespace std;

typedef class UnionFind{
private:
    int* par;
    
    int root(int a){
        if(par[a] == a) return a;
        else root(par[a]);
    }
public:
    UnionFind(int n){
        par = new int[n];
        for(int i = 0; i < n; ++i) par[i] = i;
    }
    ~UnionFind(){
        delete[] par;
    }

    void unite(int a, int b){
        int ra = root(a);
        int rb = root(b);

        if(ra == rb) return;
        else par[rb] = ra;
    }
    bool same(int a, int b){
        return root(a) == root(b);
    }
}Uf;

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
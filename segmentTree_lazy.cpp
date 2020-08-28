template <typename T>
class segmentTree {
private:
	std::unique_ptr<T[]> tree;
	std::uniequ_ptr<T[]> tree_lazy;
	T paddingObj;
	T paddingObj_lazy;
	std::function<T(T, T)> segfunc;
	std::function<T(T, T)> segfunc_lazy;
	int treeSize;
	int treeHeight;

	void initialize() {
		for (int i = treeHeight - 1; i >= 1; --i) {
			for (int counter = 0; counter < (1 << (i - 1)); ++counter) {
				int index = (1 << (i - 1)) - 1 + counter;
				tree[(1 << (i - 1)) - 1 + counter] = segfunc(tree[index * 2 + 1], tree[index * 2 + 2]);
			}
		}
	}

	void updateTree(int index) {
		if (index == 0) return;

		if (index % 2 == 0) --index;
		tree[(index - 1) / 2] = segfunc(tree[index], tree[index + 1]);
		updateTree((index - 1) / 2);
	}

	T query(int l, int r, int left, int right, int index) {
		if (l <= left && r >= right) {
			return tree[index];
		}
		else if (l > right || r < left) {
			return paddingObj;
		}
		else {
			return segfunc(query(l, r, left, (left + right) / 2, index * 2 + 1), query(l, r, (left + right) / 2 + 1, right, index * 2 + 2));
		}
	}
public:
	segmentTree(T *originalArray, int arraySize, T paddingObj, std::function<T(T, T)> func, T paddingObj_lazy, std::function<T(T, T)> func_lazy) {
		this->segfunc = func;
		this->segfunc_lazy = func_lazy;
		this->paddingObj = paddingObj;
		this->paddingObj_lazy = paddingObj_lazy;

		treeHeight = 1;
		while ((1 << (treeHeight - 1)) < arraySize) ++treeHeight;
		treeSize = 1 << (treeHeight - 1);
		tree = std::make_unique<T[]>(treeSize * 2 - 1);
		tree_lazy = std::make_unique<T[]>(treeSize * 2 - 1);
		for (int i = 0; i < arraySize; ++i) tree[(treeSize - 1) + i] = originalArray[i];
		for (int i = arraySize; i < treeSize; ++i) tree[(treeSize - 1) + i] = paddingObj;
		for (int i = 0; i < treeSize*2-1; ++i) tree_lazy[i] = paddingObj_lazy;

		initialize();
	}

	void update(int index, T x) {
		if (index >= treeSize || index < 0) {
			throw std::out_of_range("Index must be in [0, treeSize)");
			return;
		}

		tree[treeSize - 1 + index] = x;
		updateTree(treeSize - 1 + index);
	}

	void update(int l, int r, T x){
		if (l > r || l < 0 || r >= treeSize) {
			throw std::out_of_range("Both l and r must be in [0, treeSize) and l must be smaller than r");
		}

		/*
		遅延更新を実装
		遅延評価を実装
		*/
	}

	T get(int l, int r) {
		if (l > r || l < 0 || r >= treeSize) {
			throw std::out_of_range("Both l and r must be in [0, treeSize) and l must be smaller than r");
		}

		return query(l, r, 0, treeSize - 1, 0);
	}
};
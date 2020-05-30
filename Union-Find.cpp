struct Unionfind {
    vector<int> par;
    vector<int> rank;

    void init(int n) {
        par.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++) par[i] = i;
    }

    int root(int x) {
        if (par[x] == x) return x;
        else return par[x] = root(par[x]);
    }

    void unite(int x, int y) {
        x = root(x), y = root(y);
        if (x == y) return;
        else {
            if (rank[x] < rank[y]) par[x] = y;
            else {
                par[y] = x;
                if (rank[x] == rank[y]) rank[x]++;
            }
        }
    }

    bool issame(int x, int y) { return root(x) == root(y); }
};

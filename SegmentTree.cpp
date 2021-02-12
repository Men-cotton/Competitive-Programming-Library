// verified with https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F

#include <iostream>
#include <vector>
#include <climits>

using namespace std;
typedef long long ll;

template<typename T>
struct SegmentTree {
private:
    //////////////////////
    // TODO Change them //
    //////////////////////
    constexpr static T UPDATE_IDENTITY_ELEMENT = 0;
    constexpr static T CALCULATE_IDENTITY_ELEMENT = INT_MAX;
    constexpr static bool IS_LAZY = true;

    static void update(T &x, T y) { x = y; }

    static T calculate(T x, T y) { return min(x, y); }

    void evaluation(int index, int nowL, int nowR) {
        if (changed[index]) {
            update(data[index], lazy[index]); // TODO Change updating
            if (nowR - nowL > 1) {
                update(lazy[index * 2], lazy[index]), changed[index * 2] = true;
                update(lazy[index * 2 + 1], lazy[index]), changed[index * 2 + 1] = true;
            }
            lazy[index] = UPDATE_IDENTITY_ELEMENT, changed[index] = false;
        }
    }
    //////////////////////
    // TODO Change them //
    //////////////////////


    int n;
    vector<T> data;
    vector<T> lazy;
    vector<bool> changed;

    void initialize(int size, vector<T> &v) {
        n = 1;
        while (n < size)n <<= 1;
        data.resize(2 * n);
        if (IS_LAZY) {
            lazy.assign(2 * n, UPDATE_IDENTITY_ELEMENT);
            changed.resize(2 * n);
        }

        for (int i = n; i < n + v.size(); i++)data[i] = v[i - n];
        for (int i = n - 1; i > 0; i--)data[i] = children(i);
    }

    T children(int index) { return calculate(data[index * 2], data[index * 2 + 1]); }

    void update_point(int index, T value) {
        index += n;
        update(data[index], value);
        while (index > 1) {
            index >>= 1;
            data[index] = children(index);
        }
    }

    void update_range(int wantL, int wantR, T value, int index, int nowL, int nowR) {
        evaluation(index, nowL, nowR);

        if (nowR <= wantL || wantR <= nowL)return;

        if (wantL <= nowL && nowR <= wantR) {
            update(lazy[index], value), changed[index] = true;
            evaluation(index, nowL, nowR);
        } else {
            int mid = (nowL + nowR) / 2;
            update_range(wantL, wantR, value, index * 2, nowL, mid);
            update_range(wantL, wantR, value, index * 2 + 1, mid, nowR);
            data[index] = children(index);
        }
    }

    T query(int wantL, int wantR, int index, int nowL, int nowR) {
        if (nowR <= wantL || wantR <= nowL)return CALCULATE_IDENTITY_ELEMENT;

        if (IS_LAZY)evaluation(index, nowL, nowR);
        if (wantL <= nowL && nowR <= wantR) return data[index];
        else {
            int mid = (nowL + nowR) / 2;
            T valueL = query(wantL, wantR, index * 2, nowL, mid);
            T valueR = query(wantL, wantR, index * 2 + 1, mid, nowR);
            return calculate(valueL, valueR);
        }
    }

public:
    SegmentTree(int size, T value) {
        vector<T> tmp(size, value);
        initialize(size, tmp);
    }

    SegmentTree(vector<T> &v) { initialize(v.size(), v); }

    void update(int index, T value) {
        if (IS_LAZY) update(index, index + 1, value);
        else update_point(index, value);
    }

    void update(int indexL, int indexR, T value) {
        if (IS_LAZY) update_range(indexL, indexR, value, 1, 0, n);
        else {
            for (int i = indexL; i < indexR; i++)update(i, value);
        }
    }

    T get(int index) { return get(index, index + 1); }

    T get(int indexL, int indexR) { return query(indexL, indexR, 1, 0, n); }
};

int main() {
    int n, q;
    cin >> n >> q;
    SegmentTree<ll> seg(n, INT_MAX);
    for (int i = 0; i < q; i++) {
        int com;
        cin >> com;
        if (com == 0) {
            int s, t, x;
            cin >> s >> t >> x;
            seg.update(s, t + 1, x);
        } else {
            int s, t;
            cin >> s >> t;
            cout << seg.get(s, t + 1) << endl;
        }
    }
}

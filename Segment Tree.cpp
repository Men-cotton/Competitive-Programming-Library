#include <vector>
#include <climits>

using namespace std;

constexpr int INF = INT_MAX;

struct SegmentTree {
    int n;
    vector<int> data;

    SegmentTree(int size) {
        n = 1;
        while (n < size)n <<= 1;
        data.assign(2 * n, INF);
    }

    void update(int index, int value) {
        index += n;
        data[index] = value;
        while (index > 1) {
            index >>= 1;
            data[index] = min(data[index * 2], data[index * 2 + 1]);
        }
    }

    int get(int wantL, int wantR) { return query(wantL, wantR, 1, 0, n); }

private:
    int query(int wantL, int wantR, int index, int nowL, int nowR) {
        if (nowR <= wantL || wantR <= nowL)return INF;

        if (wantL <= nowL && nowR <= wantR)return data[index];
        else {
            int mid = (nowL + nowR) / 2;
            int valueL = query(wantL, wantR, index * 2, nowL, mid);
            int valueR = query(wantL, wantR, index * 2 + 1, mid, nowR);
            return min(valueL, valueR);
        }
    }
};

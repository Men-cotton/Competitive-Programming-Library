#define ll long long

ll two_pointers_algorithm(vector<ll> &v, ll limit) {
    ll ret = 0;

    ll sum = 0;
    int r = 0;

    for (int l = 0; l < v.size(); l++) {
        if (sum < 0)sum += v[l - 1];
        for (r = max(l, r); r < v.size() && sum + v[r] < limit; r++) {
            sum += v[r];
        }

        ret += r - l;
        sum -= v[l];
    }

    return ret;
}

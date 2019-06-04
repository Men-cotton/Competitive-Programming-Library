ll mod = 1e9 + 7;

vector<ll> fact;

void init_fact(int n) {
    fact = vector<ll>(n);
    fact[0] = 1;
    for (int i = 1; i < n; i++) fact[i] = fact[i - 1] * i % mod;
}

ll calc_pow(ll x, ll pow) {
    if (pow == 0) return 1;
    ll a = calc_pow(x, pow / 2);
    a = a * a % mod;
    if (pow % 2 == 1) a *= x;
    return a % mod;
}

ll calc_div(ll a, ll b) {
    return a * calc_pow(b, mod - 2) % mod;
}

ll calc_comb(ll n, ll r) {
    return calc_div(fact[n], fact[r] * fact[n - r] % mod);
}

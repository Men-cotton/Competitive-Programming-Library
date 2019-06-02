ll mod = 1e9 + 7;

ll Calc_pow(ll x, ll pow) {
    if (pow == 0) return 1;
    ll a = Calc_pow(x, pow / 2);
    a = a * a % mod;
    if (pow % 2 == 1) a *= x;
    return a % mod;
}

vector<ll> fact;

void Init_fact(int n) {
    fact = vector<ll>(n);
    fact[0] = 1;
    for (int i = 1; i < n; i++) fact[i] = fact[i - 1] * i % mod;
}

ll Combination(ll n, ll r) {
    return fact[n] * Calc_pow(fact[r] * fact[n - r] % mod, mod - 2) % mod;
}

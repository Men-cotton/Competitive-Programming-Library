const int mod = 1000000007;
static long calc_pow(long x, long pow)
{
	if (pow == 0) return 1;
	long a = calc_pow(x, pow / 2);
	a = a * a % mod;
	if (pow % 2 == 1) a *= x;
	return a % mod;
}
static long[] fact;
static void init_fact(int n)
{
	fact = new long[n]; fact[0] = 1;
	for (int i = 1; i < n; i++) fact[i] = fact[i - 1] * i % mod;
}
static long combination(long n, long r)
{
	return fact[n] * calc_pow((fact[r] * fact[n - r]) % mod, mod - 2) % mod;
}

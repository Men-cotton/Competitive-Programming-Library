public class Unionfind
{
	public static int[] par;//親
	public static int[] rank; //深さ
	public void init(int n)//初期化
	{
		par = new int[n]; rank = new int[n];
		for (int i = 0; i < n; i++)
		{
			par[i] = i;
			rank[i] = 0;
		}
	}
	public int root(int x)//根を求める
	{
		if (par[x] == x) return x;
		else return par[x] = root(par[x]);
	}
	public void unite(int x, int y)//集合を併合
	{
		x = root(x); y = root(y);
		if (x == y) return;
		else
		{
			if (rank[x] < rank[y]) par[x] = y;
			else
			{
				par[y] = x;
				if (rank[x] == rank[y]) rank[x]++;
			}
		}
	}
	public bool issame(int x, int y)//同じ集合に属しているか
	{
		return root(x) == root(y);
	}
}
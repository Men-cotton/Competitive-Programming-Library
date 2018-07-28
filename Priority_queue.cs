<<<<<<< HEAD
class Priority_queue
{
	List<int> nodevalue;
	int length;
	void swap(int x, int y)
	{
		nodevalue[x] ^= nodevalue[y];
		nodevalue[y] ^= nodevalue[x];
		nodevalue[x] ^= nodevalue[y];
	}
	public void init(int[] x)
	{
		var a = new List<int> { -1 };//番兵
		a.AddRange(x);
		nodevalue = a;
		length = nodevalue.Count;
		for (int i = length / 2; i >= 1; i--)
		{
			maxheapify(i);
		}
	}
	void maxheapify(int par)
	{
		int l, r, largest;
		l = 2 * par;
		r = 2 * par + 1;
		largest = par;
		if (l < length && nodevalue[l] > nodevalue[largest]) largest = l;
		if (r < length && nodevalue[r] > nodevalue[largest]) largest = r;
		if (largest != par)
		{
			swap(par, largest);
			maxheapify(largest);
		}
	}
	public int pop()
	{
		if (length <= 1) return -1;
		int max = nodevalue[1];
		nodevalue[1] = nodevalue[--length];
		nodevalue.RemoveAt(length);
		maxheapify(1);
		return max;
	}
	public void push(int key)
	{
		length++;
		nodevalue.Add(-1);
		increasekey(length - 1, key);
	}
	void increasekey(int i, int key)
	{
		if (key < nodevalue[i]) return;
		nodevalue[i] = key;
		while (i > 1 && nodevalue[i / 2] < nodevalue[i])
		{
			swap(i / 2, i);
			i /= 2;
		}
	}
=======
class Priority_queue
{
	List<int> nodevalue;
	int length;
	void swap(int x, int y)
	{
		nodevalue[x] ^= nodevalue[y];
		nodevalue[y] ^= nodevalue[x];
		nodevalue[x] ^= nodevalue[y];
	}
	public void init(int[] x)
	{
		var a = new List<int> { -1 };//番兵
		a.AddRange(x);
		nodevalue = a;
		length = nodevalue.Count;
		for (int i = length / 2; i >= 1; i--)
		{
			maxheapify(i);
		}
	}
	void maxheapify(int par)
	{
		int l, r, largest;
		l = 2 * par;
		r = 2 * par + 1;
		largest = par;
		if (l < length && nodevalue[l] > nodevalue[largest]) largest = l;
		if (r < length && nodevalue[r] > nodevalue[largest]) largest = r;
		if (largest != par)
		{
			swap(par, largest);
			maxheapify(largest);
		}
	}
	public int pop()
	{
		if (length <= 1) return -1;
		int max = nodevalue[1];
		nodevalue[1] = nodevalue[--length];
		nodevalue.RemoveAt(length);
		maxheapify(1);
		return max;
	}
	public void push(int key)
	{
		length++;
		nodevalue.Add(-1);
		increasekey(length - 1, key);
	}
	void increasekey(int i, int key)
	{
		if (key < nodevalue[i]) return;
		nodevalue[i] = key;
		while (i > 1 && nodevalue[i / 2] < nodevalue[i])
		{
			swap(i / 2, i);
			i /= 2;
		}
	}
>>>>>>> 6afdd871ffa091c85d22c5c16ed3ed44825600a8
}
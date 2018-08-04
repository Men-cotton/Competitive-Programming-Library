static bool IsOK(int index, int key)
{
	if (arr[index] > key) return true;
	else return false;
}

static int Binary_search(int key)
{
	int ng = -1;
	int ok = arr.Count();

	while (ok - ng > 1)
	{
		int mid = ng + (ok - ng) / 2;

		if (IsOK(mid, key)) ok = mid;
		else ng = mid;
	}

	return ok;
}

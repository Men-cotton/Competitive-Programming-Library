static bool IsOK(int index, int key)
{
	if (arr[index] > key) return true;
	else return false;
}

static int Binary_search(int key)
{
	int left = -1;
	int right = arr.Count();

	while (right - left > 1)
	{
		int mid = left + (right - left) / 2;

		if (IsOK(mid, key)) right = mid;
		else left = mid;
	}

	return right;
}

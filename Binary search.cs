static int lowerBound(int[] arr, int value)
{
	int ok = 0;
	int ng = arr.Length;
	int mid;
	while (Math.Abs(ok - ng) > 1)
	{
		mid = ((ng - ok) / 2) + ok;
		if (arr[mid] < value)
			ok = mid + 1;
		else
			ng = mid;
	}
	return ok;
}

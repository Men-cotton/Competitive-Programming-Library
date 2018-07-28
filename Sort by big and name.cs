public class Comparer : IComparer
{
	public int Compare(object x, object y)
	{
		Tuple<string, double> t1 = (Tuple<string, double>)x;
		Tuple<string, double> t2 = (Tuple<string, double>)y;
		if (t1.Item2 < t2.Item2) return 1;
		if (t1.Item2 > t2.Item2) return -1;
		return t1.Item1.CompareTo(t2.Item1);
	}
}
static void Main()
{
IComparer Comp = new Comparer();
Array.Sort(tuples, Comp);
}
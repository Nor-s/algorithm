import java.util.*;

class Solution
{
	public static void main(String args[]) throws Exception
	{
		Scanner sc = new Scanner(System.in);
		int T;
		T=sc.nextInt();

		for(int test_case = 1; test_case <= T; test_case++)
		{
			int max_value = -999;
			for (int i = 0; i < 10; i++) {
				max_value = Math.max(max_value, sc.nextInt());
			}
			System.out.println("#" + test_case + " " + max_value);
		}
	}
}
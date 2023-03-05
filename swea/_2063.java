import java.util.*;

class Solution
{
	public static void main(String args[]) throws Exception
	{
		Scanner sc = new Scanner(System.in);
		int N;
		N=sc.nextInt();

		int Arr [] = new int[N];

		for(int i = 0 ; i < N; i++) {
			Arr[i] = sc.nextInt();
		}
		Arrays.sort(Arr);
		System.out.println(Arr[N/2]);
	}
}
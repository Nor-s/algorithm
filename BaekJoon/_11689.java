import java.util.*;


class _11689
{
	public static void main(String args[]) throws Exception
	{
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int q = sc.nextInt();
		int []vec = new int[n];
		int []psum = new int[n + 1];
		for(int i = 0 ; i < n; i++) {
			vec[i] = sc.nextInt();
			psum[i + 1] = psum[i] + vec[i];
		}
		for(int i = 0 ; i < q; i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			System.out.println(psum[b] - psum[a-1]);
		}
	}
}
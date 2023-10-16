import java.util.*;

class Sol_2023_01_17_09_27 {
	public static int count1 = 0;
	public static int count2 = 0;

	public static int fib1(int n) {
		if (n == 1 || n == 2) {
			count1++;
			return 1;
		} else {
			return fib1(n - 1) + fib1(n - 2);
		}

	}

	public static int fib2(int n) {
		int f[] = new int[n+1];
		for (int i = 3 ; i <= n; i++) {
			count2++;
			f[i] = f[i - 1] + f[i- 2];
		}
		return f[n];
	}

	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
		int T;
		T = sc.nextInt();
		fib1(T);
		fib2(T);

		System.out.println(count1 + " " + count2);

	}
}
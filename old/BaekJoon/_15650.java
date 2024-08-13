import java.util.*;

class Sol_2023_02_08_11_14 {
	public static int nums[];

	public static void print(int idx, int m, int c) {
		if (m == c) {
			for (int i = 0; i < m; i++) {
				System.out.print(nums[i] + " ");
			}
			System.out.println();
			return;
		}
		if (idx == nums.length) {
			return;
		}

		nums[c] = idx + 1;
		print(idx + 1, m, c + 1);
		print(idx + 1, m, c);
	}

	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);

		int N, M;
		N = sc.nextInt();
		M = sc.nextInt();
		nums = new int[N];
		print(0, M, 0);
	}
}
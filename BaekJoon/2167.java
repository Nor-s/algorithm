import java.util.*;

class Sol_2023_01_19_14_18 {
	public static long ssum[][];

	public static int Sum(int yy, int xx, int y, int x) {
		return (int) (ssum[y][x] + ssum[yy - 1][xx - 1] - ssum[y][xx - 1] - ssum[yy - 1][x]);
	}

	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
		int N, M;
		N = sc.nextInt();
		M = sc.nextInt();

		int arr[][] = new int[N + 1][M + 1];
		ssum = new long[N + 1][M + 1];
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				arr[i][j] = sc.nextInt();
				ssum[i][j] = ssum[i-1][j] + ssum[i][j-1] - ssum[i-1][j-1] + arr[i][j];
			}
		}

		int T = sc.nextInt();
		for (int i = 0; i < T; i++) {
			int yy = sc.nextInt();
			int xx = sc.nextInt();
			int y = sc.nextInt();
			int x = sc.nextInt();
			System.out.println(Sum(yy, xx, y, x));
		}
		sc.close();
	}
}
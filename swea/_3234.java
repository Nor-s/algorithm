import java.util.*;

class Solutiona {
	public static int Arr[];
	public static int Visited[];

	public static int Cache2Pow[] = new int[10];
	public static int CachePi[] = new int[10];

	public static int N;
	public static int Answer;
	public static int TotalSum;

	public static void InitCache() {
		Cache2Pow[0] = 1;
		CachePi[0] = 1;
		for (int i = 1; i < 10; i++) {
			Cache2Pow[i] = Cache2Pow[i - 1] * 2;
			CachePi[i] = CachePi[i - 1] * i;
		}
	}

	public static void Search(int left_sum, int right_sum, int count) {
		if (count == N) {
			Answer++;
			return;
		}
		if (right_sum + TotalSum - left_sum <= left_sum) {
			int remain = N - count;
			Answer += Cache2Pow[remain] * CachePi[remain];
			return;
		}

		for (int i = 0; i < N; i++) {
			if (Visited[i] == 0) {
				Visited[i] = 1;
				Search(left_sum + Arr[i], right_sum, count + 1);
				int right = right_sum + Arr[i];

				if (right <= left_sum) {
					Search(left_sum, right, count + 1);
				}

				Visited[i] = 0;
			}
		}

		return;
	}

	public static void main(String args[]) throws Exception {
		InitCache();

		Scanner sc = new Scanner(System.in);
		int T;
		T = sc.nextInt();

		for (int test_case = 1; test_case <= T; test_case++) {
			N = sc.nextInt();
			Answer = 0;
			TotalSum = 0;

			Arr = new int[N];
			Visited = new int[N];

			for (int i = 0; i < N; i++) {
				Arr[i] = sc.nextInt();
				TotalSum += Arr[i];
			}

			Search(0, 0, 0);
			System.out.println("#" + test_case + " " + Answer);
		}
		sc.close();
	}
}
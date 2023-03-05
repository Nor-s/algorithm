import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class _3282 {
	static final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static int V[];
	static int C[];
	static int K;

	static Integer cached[][] = new Integer[102][1002];

	public static int knapsack(int idx, int currentV) {
		if (currentV > K) {
			return -100_000_000;
		}

		if (cached[idx][currentV] == -1) {
			cached[idx][currentV] = 0;
			for (int i = idx; i < V.length; i++) {
				cached[idx][currentV] = Math.max(cached[idx][currentV], knapsack(i + 1, currentV + V[i]) + C[i]);
			}
		}
		return cached[idx][currentV];
	}

	public static void main(String args[]) throws Exception {
		int T = Integer.parseInt(in.readLine());

		for (int test_case = 1; test_case <= T; test_case++) {
			StringTokenizer st = new StringTokenizer(in.readLine());
			int N = Integer.parseInt(st.nextToken());
			K = Integer.parseInt(st.nextToken());
			V = new int[N];
			C = new int[N];
			for (Integer[] row : cached) {
				Arrays.fill(row, -1);
			}

			for (int i = 0; i < N; i++) {
				st = new StringTokenizer(in.readLine());
				V[i] = Integer.parseInt(st.nextToken());
				C[i] = Integer.parseInt(st.nextToken());
			}
			out.write("#" + test_case + " " + knapsack(0, 0) + "\n");
		}

		out.flush();
		out.close();
		in.close();
	}
}

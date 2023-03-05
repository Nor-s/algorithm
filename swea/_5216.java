import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class _5216 {
	static final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

	static int dp(int[][] cached, int[] t, int[] k, int foodidx, int currentk, int l) {
		if (currentk > l) {
			return -Integer.MIN_VALUE;
		}

		if (cached[foodidx][currentk] == 0) {
			for (int i = foodidx; i < t.length; i++) {
				int nextT = dp(cached, t, k, i + 1, currentk + k[i], l) + t[i];
				cached[foodidx][currentk] = Math.max(cached[foodidx][currentk], nextT);
			}
		}
		return cached[foodidx][currentk];
	}

	public static void main(String args[]) throws Exception {
		int TC = Integer.parseInt(in.readLine());

		for (int test_case = 1; test_case <= TC; test_case++) {
			StringTokenizer st = new StringTokenizer(in.readLine());
			int n = Integer.parseInt(st.nextToken());
			int l = Integer.parseInt(st.nextToken());
			int cached[][] = new int[n + 1][l + l];
			int T[] = new int[n];
			int K[] = new int[n];

			for (int i = 0; i < n; i++) {
				st = new StringTokenizer(in.readLine());
				T[i] = Integer.parseInt(st.nextToken());
				K[i] = Integer.parseInt(st.nextToken());
			}
			int answer = dp(cached, T, K, 0, 0, l);

			out.write("#" + test_case + " " + answer + "\n");
		}

		out.flush();
		out.close();
		in.close();
	}
}

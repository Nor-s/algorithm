import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class _9229 {
	static final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static int m[];
	static int M;
	static int answer;

	public static void knapsack(int idx, int currentM, int count) {
		if (currentM > M) {
			return;
		}
		if (count == 2) {
			answer = Math.max(answer, currentM);
			return;
		}
		for (int i = idx; i < m.length; i++) {
			knapsack(i + 1, currentM + m[i], count + 1);
		}
	}

	public static void main(String args[]) throws Exception {
		int T = Integer.parseInt(in.readLine());

		for (int test_case = 1; test_case <= T; test_case++) {
			StringTokenizer st = new StringTokenizer(in.readLine());
			int N = Integer.parseInt(st.nextToken());
			M = Integer.parseInt(st.nextToken());
			m = new int[N];
			answer = 0;

			st = new StringTokenizer(in.readLine());
			for (int i = 0; i < N; i++) {
				m[i] = Integer.parseInt(st.nextToken());
			}
			knapsack(0, 0, 0);
			out.write("#" + test_case + " " + ((0 == answer) ? -1 : answer) + "\n");
		}

		out.flush();
		out.close();
		in.close();
	}
}

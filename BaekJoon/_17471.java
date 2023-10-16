import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class _17471 {
	static final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static int[][] arr;
	static int[] num;
	static int sum = 0;
	static boolean[] visited;

	static int dfs(int node, int state, int[] memo) {
		int ret = 1;
		visited[node] = true;
		memo[0] += num[node];
		for (int i = 0; i < arr[node].length; i++) {
			int current = 1 << i;
			boolean isSameGroup = (state & current) == current;
			if (!visited[i] && arr[node][i] == 1 && isSameGroup) {
				ret += dfs(i, state, memo);
			}
		}
		return ret;
	}

	static int solve(int N) {
		int size = 1 << N;
		int answer = (int) 1e9;
		for (int i = 1; i < size; i++) {
			int start = -1;
			int start2 = -1;

			for (int j = 0; j < arr.length; j++) {
				int tmp = 1 << j;
				if ((i & tmp) == tmp) {
					start = j;
				} else {
					start2 = j;
				}
			}
			// System.out.println(Integer.toBinaryString(i));
			// System.out.println(start + " " + start2);
			if (start != -1 && start2 != -1) {
				visited = new boolean[N];
				int[] memo = new int[1];
				int connectCount1 = dfs(start, i, memo);
				visited = new boolean[N];
				memo = new int[1];
				int connectCount2 = dfs(start2, ~i, memo);
				if (connectCount1 + connectCount2 == N) {
					answer = Math.min(answer, Math.abs(sum - 2 * memo[0]));
				}
			}

		}

		if (answer == 1e9) {
			return -1;
		}
		return answer;
	}

	public static void main(String args[]) throws Exception {
		int N = Integer.parseInt(in.readLine());

		StringTokenizer st = new StringTokenizer(in.readLine());

		arr = new int[N][N];
		num = new int[N];

		for (int i = 0; i < N; i++) {
			num[i] = Integer.parseInt(st.nextToken());
			sum += num[i];
		}

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(in.readLine());
			int size = Integer.parseInt(st.nextToken());

			for (int j = 0; j < size; j++) {
				arr[i][Integer.parseInt(st.nextToken()) - 1] = 1;
			}
		}
		out.write(solve(N) + "");

		out.flush();
		out.close();
		in.close();
	}
}

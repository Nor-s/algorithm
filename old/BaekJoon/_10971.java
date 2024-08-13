import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class _10971 {
	static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static int adj[][];
	static int cached[][];
	static int N;

	public static int dfs(int visited, int idx, int start) throws Exception {
		if (visited == (1 << N) - 1) {
			if (adj[idx][start] != 0) {
				return adj[idx][start];
			}
			return Integer.MAX_VALUE / 2;
		}
		if (cached[visited][idx] == 0) {
			cached[visited][idx] = Integer.MAX_VALUE / 2;
			for (int i = 0; i < N; i++) {
				if (adj[idx][i] != 0 && ((visited & (1 << i)) == 0)) {
					cached[visited][idx] = Math.min(cached[visited][idx],
							dfs(visited | (1 << i), i, start) + adj[idx][i]);
				}
			}
		}
		return cached[visited][idx];
	}

	public static void main(String args[]) throws Exception {
		N = Integer.parseInt(in.readLine());
		adj = new int[N][N];
		cached = new int[1 << N][N];

		for (int i = 0; i < N; i++) {
			StringTokenizer st = new StringTokenizer(in.readLine());
			for (int j = 0; j < N; j++) {
				adj[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		;
		System.out.println(dfs(1 << 0, 0, 0));

		in.close();
	}
}
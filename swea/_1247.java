import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class _1247 {
	static final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static int y[];
	static int x[];
	static int answer = 0;

	static boolean visited[];

	public static int dist(int y, int x, int yy, int xx) {
		return Math.abs(yy - y) + Math.abs(xx - x);
	}

	public static void perm(int count, int currenty, int currentx, int currentD) {
		if (count + 2 == y.length) {
			answer = Math.min(answer, currentD + dist(currenty, currentx, y[1], x[1]));
			return;
		}
		for (int i = 2; i < y.length; i++) {
			if (!visited[i]) {
				visited[i] = true;
				perm(count + 1, y[i], x[i], currentD + dist(currenty, currentx, y[i], x[i]));
				visited[i] = false;
			}
		}
	}

	public static void main(String args[]) throws Exception {
		int T = Integer.parseInt(in.readLine());

		for (int test_case = 1; test_case <= T; test_case++) {
			int N = Integer.parseInt(in.readLine());
			StringTokenizer st = new StringTokenizer(in.readLine());
			y = new int[N + 2];
			x = new int[N + 2];
			visited = new boolean[N + 2];
			answer = Integer.MAX_VALUE;

			for (int i = 0; i < N + 2; i++) {
				x[i] = Integer.parseInt(st.nextToken());
				y[i] = Integer.parseInt(st.nextToken());
			}
			perm(0, y[0], x[0], 0);

			out.write("#" + test_case + " " + answer + "\n");
		}

		out.flush();
		out.close();
		in.close();
	}
}

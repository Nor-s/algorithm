import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class _2961aasds {
	static final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static int[][] food;
	static int answer = Integer.MAX_VALUE;

	public static void solve(int idx, int S, int B, int count) throws IOException {
		if (idx == food.length) {
			if (count != 0) {
				answer = Math.min(answer, Math.abs(B - S));
			}
			return;
		}
		solve(idx + 1, food[idx][0] * S, food[idx][1] + B, count + 1);
		solve(idx + 1, S, B, count);
	}

	public static void main(String args[]) throws Exception {
		int N = Integer.parseInt(in.readLine());
		food = new int[N][2];

		for (int i = 0; i < N; i++) {
			StringTokenizer st = new StringTokenizer(in.readLine());
			food[i][0] = Integer.parseInt(st.nextToken());
			food[i][1] = Integer.parseInt(st.nextToken());
		}
		solve(0, 1, 0, 0);
		out.write(String.valueOf(answer));
		out.flush();
		out.close();
		in.close();
	}
}

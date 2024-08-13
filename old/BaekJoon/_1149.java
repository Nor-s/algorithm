import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class _1149 {
	static final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static final int R = 0;
	static final int G = 1;
	static final int B = 2;

	public static void solve() throws IOException {
	}

	public static void main(String args[]) throws Exception {
		int N = Integer.parseInt(in.readLine());

		// 집을 빨강, 초록 파랑 중 하나의 색으로 칠해야함
		// 비용 최소화
		// 1번집 != 2번집
		// N번집 != N-1번집
		//// i != i -1 && i != i+1번째 집
		int cost[][] = new int[N + 1][3];
		for (int i = 1; i <= N; i++) {
			StringTokenizer st = new StringTokenizer(in.readLine());
			cost[i][R] = Integer.parseInt(st.nextToken());
			cost[i][G] = Integer.parseInt(st.nextToken());
			cost[i][B] = Integer.parseInt(st.nextToken());
		}

		int cached[][] = new int[N + 1][3];

		// 규칙 그대로 적용
		for (int i = 1; i <= N; i++) {
			cached[i][R] = Math.min(cached[i - 1][G], cached[i - 1][B]) + cost[i][R];
			cached[i][G] = Math.min(cached[i - 1][R], cached[i - 1][B]) + cost[i][G];
			cached[i][B] = Math.min(cached[i - 1][R], cached[i - 1][G]) + cost[i][B];
		}

		System.out.println(Math.min(cached[N][R], Math.min(cached[N][G], cached[N][B])));

		out.flush();
		out.close();
		in.close();
	}
}

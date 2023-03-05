import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class _2115 {
	static final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static int board[][];
	static int N, M, C;
	static int answer = 0;

	public static boolean checkNest(int a, int b) {
		int ax = a % N, bx = b % N;

		if (ax + M > N || bx + M > N) {
			return false;
		}
		if (ax < bx && bx < ax + M) {
			return false;
		}
		if (bx < ax && ax < bx + M) {
			return false;
		}
		return true;
	}

	public static int getMax(int start, int idx) {
		if (idx == M) {
			return 0;
		}
		int ret = 0;
		for (int i = idx; i < start + M; i++) {
			ret = Math.max(ret, getMax(start, i + 1, sum + board[start / N][start % N])
					+ board[start / N][start % N] * board[start / N][start % N]);
		}
		return ret;
	}

	public static int check(int A, int B) {
		if (!checkNest(A, B)) {
			return 0;
		}
		return getMax(0, A) + getMax(B);
	}

	public static void combination() {
		int size = N * N;
		for (int i = 0; i < size; i++) {
			for (int j = i + 1; j < size; j++) {
				answer = Math.max(answer, check(i, j));
			}
		}
	}

	public static void main(String args[]) throws Exception {
		int T = Integer.parseInt(in.readLine());

		for (int test_case = 1; test_case <= T; test_case++) {
			StringTokenizer st = new StringTokenizer(in.readLine());
			N = Integer.parseInt(st.nextToken());
			M = Integer.parseInt(st.nextToken());
			C = Integer.parseInt(st.nextToken());
			answer = 0;

			board = new int[N][N];

			for (int i = 0; i < N; i++) {
				st = new StringTokenizer(st.nextToken());
				for (int j = 0; j < N; j++) {
					board[i][j] = Integer.parseInt(st.nextToken());
				}
			}

			out.write("#" + test_case + "\n");
		}

		out.flush();
		out.close();
		in.close();
	}
}

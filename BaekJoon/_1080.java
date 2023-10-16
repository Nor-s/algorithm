import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class _1080 {
	static final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static int[][] mat1;
	static int[][] mat2;

	public static void flip(int y, int x) {
		for (int i = y; i < y + 3; i++) {
			for (int j = x; j < x + 3; j++) {
				mat1[i][j] = (mat1[i][j] == 0) ? 1 : 0;
			}
		}
	}

	public static int solve() {
		int answer = 0;
		for (int i = 0; i < mat1.length - 2; i++) {
			for (int j = 0; j < mat1[0].length - 2; j++) {
				if (mat1[i][j] != mat2[i][j]) {
					flip(i, j);
					answer++;

				}
			}
		}
		for (int i = 0; i < mat1.length; i++) {
			for (int j = 0; j < mat1[0].length; j++) {
				if (mat1[i][j] != mat2[i][j]) {
					return -1;
				}
			}
		}

		return answer;
	}

	public static void main(String args[]) throws Exception {
		StringTokenizer st = new StringTokenizer(in.readLine());
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		mat1 = new int[N][M];
		mat2 = new int[N][M];

		for (int i = 0; i < N; i++) {
			String s = in.readLine();
			for (int j = 0; j < M; j++) {
				mat1[i][j] = s.charAt(j) - '0';
			}
		}

		for (int i = 0; i < N; i++) {
			String s = in.readLine();
			for (int j = 0; j < M; j++) {
				mat2[i][j] = s.charAt(j) - '0';
			}
		}
		int answer = solve();
		out.write(answer + "");

		out.flush();
		out.close();
		in.close();
	}
}
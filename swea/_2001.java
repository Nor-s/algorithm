import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class _2001 {
	static final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	public static int board[][];

	public static int solve(int M) throws IOException {
		int answer = 0;
		// 파리채의 위치 설정
		for(int i = 0; i <= board.length - M; i++) {
			for(int j = 0; j <= board.length - M; j++) {
				int sum = 0;
				// 파리채 범위 설정 및 파리 잡기
				for(int ii = 0; ii < M; ii++) {
					for(int jj = 0; jj < M; jj++) {
						sum += board[i + ii][j + jj];
					}
				}
				// 죽은 파리의 개수의 최댓값
				answer = Math.max(answer, sum);
			}
		}
		return answer;
	}

	public static void main(String args[]) throws Exception {
		int T = Integer.parseInt(in.readLine());

		for (int test_case = 1; test_case <= T; test_case++) {
			StringTokenizer st = new StringTokenizer(in.readLine());
			int N = Integer.parseInt(st.nextToken());
			int M = Integer.parseInt(st.nextToken());
			board = new int[N][N];

			for (int i = 0; i < N; i++) {
				st = new StringTokenizer(in.readLine());
				for (int j = 0; j < N; j++) {
					board[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			
			out.write("#" + test_case + " "+  solve(M) + "\n" );
		}

		out.flush();
		out.close();
		in.close();
	}
}

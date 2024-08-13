import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class _3025 {
	static final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

	// R x C 보드를 세워 놓은 상태
	// 맨 처음 정사각형 칸이 비어있거나 벽으로 막혀있음
	// 돌을 떨어트림
	// 중력은 다음과 같음
	// 1. (벽 or 아랫줄) 막혀 있으면 그대로 멈춤
	// 2. 돌의 아랫칸이 비어있다면, 돌은 아랫칸으로 이동
	// 3. 돌의 아랫칸에 돌이 있다면, 돌은 다음과 같이 미끄러짐
	// 1. 돌의 왼쪽 칸과 왼쪽 아래 칸이 비어있으면 왼쪽으로 미끄러짐
	// 2. 오른쪽칸과 오른쪽 아래 칸이 비어있다면, 돌은 오른쪽으로 미끄러짐
	// 3. 위의 두 경우가 아니라면 돌이멈춤

	static class Stone {
		char board[][];
		int R, C;
		int wallTopPosition[];

		void firstColision() {
			int lo = 0, R = 30_001;
		}

		void init() throws IOException {
			StringTokenizer st = new StringTokenizer(in.readLine());
			R = Integer.parseInt(st.nextToken());
			C = Integer.parseInt(st.nextToken());
			for (int i = 0; i < R; i++) {
				String s = in.readLine();
				for (int j = 0; j < C; j++) {
					board[i][j] = s.charAt(j);
				}
			}
			int n = Integer.parseInt(in.readLine());

			for (int i = 0; i < n; i++) {
			}
		}
	}

	public static void main(String args[]) throws Exception {
		int T = Integer.parseInt(in.readLine());

		out.flush();
		out.close();
		in.close();
	}
}

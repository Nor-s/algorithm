import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class _6987 {
	static final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static int board[][] = new int[4][18];
	static final int WIN = 0;
	static final int DRAW = 1;
	static final int LOSE = 2;
	static final int match[] = { LOSE, DRAW, WIN };

	public static boolean check(int scoreBoard[][], int A, int B) {
		// 기저 조건: 모든 국가가 정상적으로 결과를 냄
		if (A == 6) {
			return true;
		}
		if (B == 6 && scoreBoard[A][WIN] == 0 && scoreBoard[A][DRAW] == 0 && scoreBoard[A][LOSE] == 0) {
			return check(scoreBoard, A + 1, A + 2);
		} else if (B == 6) {
			return false;
		}
		// A 와 B 의 경우의 수를 구함
		for (int i = WIN; i <= LOSE; i++) {
			if (scoreBoard[A][i] > 0 && scoreBoard[B][match[i]] > 0) {
				scoreBoard[A][i]--;
				scoreBoard[B][match[i]]--;
				if (check(scoreBoard, A, B + 1)) {
					return true;
				}
				scoreBoard[A][i]++;
				scoreBoard[B][match[i]]++;
			}
		}
		return false;
	}

	public static boolean isOkay(int y) {
		int scoreBoard[][] = new int[6][3];
		for (int i = 0; i < 6; i++) {
			scoreBoard[i][0] = board[y][i * 3 + 0];
			scoreBoard[i][1] = board[y][i * 3 + 1];
			scoreBoard[i][2] = board[y][i * 3 + 2];
		}
		return check(scoreBoard, 0, 1);
	}

	public static void main(String args[]) throws Exception {
		for (int i = 0; i < 4; i++) {
			StringTokenizer st = new StringTokenizer(in.readLine());
			for (int j = 0; j < 18; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
			}
		}
		out.write((isOkay(0) ? 1 : 0) + " ");
		out.write((isOkay(1) ? 1 : 0) + " ");
		out.write((isOkay(2) ? 1 : 0) + " ");
		out.write((isOkay(3) ? 1 : 0) + "");

		out.flush();
		out.close();
		in.close();
	}
}

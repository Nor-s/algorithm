import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class _1992 {
	static final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static char board[][];

	public static void quadTree(int y, int x, int size) throws Exception {
		int sum = 0;
		int half = size / 2;

		for (int i = y; i < y + size; i++) {
			for (int j = x; j < x + size; j++) {
				sum += (board[i][j] - '0');
			}
		}

		if (sum == size * size) {
			out.write("1");
		} else if (sum == 0) {
			out.write("0");
		} else {
			out.write("(");
			quadTree(y, x, half);
			quadTree(y, x + half, half);
			quadTree(y + half, x, half);
			quadTree(y + half, x + half, half);
			out.write(")");
		}
	}

	public static void main(String args[]) throws Exception {
		int N = Integer.parseInt(in.readLine());
		board = new char[N][N];
		for (int i = 0; i < N; i++) {
			String s = in.readLine();
			for (int j = 0; j < N; j++) {
				board[i][j] = s.charAt(j);
			}
		}
		quadTree(0, 0, N);
		out.flush();
		out.close();
		in.close();
	}
}

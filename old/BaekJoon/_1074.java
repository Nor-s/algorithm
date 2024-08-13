import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class _1074 {
	static final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

	static int[][] board = new int[][] { { 0, 1 }, { 2, 3 } };

	public static int Z(int r, int c, int n) {
		if (n == 1) {
			return board[r][c];
		}
		int div = (int) Math.pow(2, n - 1);
		int num = div * div;
		return Z(r % div, c % div, n - 1) + num * board[r / div][c / div];
	}

	public static void main(String args[]) throws Exception {
		StringTokenizer st = new StringTokenizer(in.readLine());
		int N = Integer.parseInt(st.nextToken());
		int r = Integer.parseInt(st.nextToken());
		int c = Integer.parseInt(st.nextToken());
		out.write(String.valueOf(Z(r, c, N)));
		out.flush();
		out.close();
		in.close();
	}
}

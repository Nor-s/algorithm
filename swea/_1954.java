import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class _1954
{
    static final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
    static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

	public static void printSnail(int n) throws IOException {
		int board[][] = new int[n][n];
		int dx[] = {1, 0, -1, 0};
		int dy[] = {0, 1, 0, -1};
		int dir = 0;
		int N = n*n;
		int y = 0;
		int x = 0;

		for(int num = 1 ; num <= N; num++) {
			int ny = y + dy[dir];
			int nx = x + dx[dir];

			board[y][x] = num;
			if(ny >= n || nx >= n || ny < 0 || nx < 0 || board[ny][nx] != 0) {
				dir = (dir + 1)%4;
				ny = y + dy[dir];
				nx = x + dx[dir];
			}
			y = ny;
			x = nx;
		}

		StringBuilder sb = new StringBuilder();
		for(int i = 0; i < n; i++) {
			for(int j = 0 ; j < n ; j++) {
				sb.append(board[i][j]);
				sb.append(" ");
			}
			sb.append("\n");
		}
		out.write(sb.toString());
	}

	public static void main(String args[]) throws Exception
	{
		int T = Integer.parseInt(in.readLine());

		for(int test_case = 1; test_case <= T; test_case++)
		{
			int N = Integer.parseInt(in.readLine());
			out.write("#" + test_case + "\n");
			printSnail(N);
		}

		out.flush();
        out.close();
        in.close();
	}
}
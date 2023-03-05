import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class _1873 {
	static final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static char board[][];
	static String cmd;
	static int[] tankPoint;
	static Map<Character, Integer> cmdMap = new HashMap<Character, Integer>() {
		{
			put('U', 0);
			put('D', 1);
			put('L', 2);
			put('R', 3);
			put('S', 4);

			put('^', 0);
			put('v', 1);
			put('<', 2);
			put('>', 3);
		}
	};
	static int[] dx = { 0, 0, -1, 1 };
	static int[] dy = { -1, 1, 0, 0 };
	static char[] mark = { '^', 'v', '<', '>' };

	public static boolean move(int[] what, int dir, boolean checkMark) {
		if (checkMark) {
			board[what[0]][what[1]] = mark[dir];
		}
		if (board[what[0] + dy[dir]][what[1] + dx[dir]] == '.') {
			if (checkMark) {
				board[what[0]][what[1]] = '.';
				board[what[0] + dy[dir]][what[1] + dx[dir]] = mark[dir];
			}

			what[0] += dy[dir];
			what[1] += dx[dir];
			return true;
		}
		return false;
	}

	public static void shoot(int y, int x) {
		int bullet[] = new int[2];
		bullet[0] = y;
		bullet[1] = x;
		int dir = cmdMap.get(board[tankPoint[0]][tankPoint[1]]);
		while (move(bullet, dir, false)) {
		}
		char obst = board[bullet[0] + dy[dir]][bullet[1] + dx[dir]];
		if (obst == '*') {
			board[bullet[0] + dy[dir]][bullet[1] + dx[dir]] = '.';
		} else if (obst == '-') {
			shoot(bullet[0] + dy[dir], bullet[1] + dx[dir]);
		}
	}

	public static void solve() {
		for (int i = 0; i < cmd.length(); i++) {
			int cmdCode = cmdMap.get(cmd.charAt(i));
			if (cmdCode < 4) {
				move(tankPoint, cmdCode, true);
			} else {
				shoot(tankPoint[0], tankPoint[1]);
			}
		}
	}

	public static void main(String args[]) throws Exception {
		int T = Integer.parseInt(in.readLine());

		for (int test_case = 1; test_case <= T; test_case++) {
			StringTokenizer st = new StringTokenizer(in.readLine());
			int H = Integer.parseInt(st.nextToken());
			int W = Integer.parseInt(st.nextToken());
			tankPoint = new int[2];

			board = new char[H + 2][W + 2];
			for (int i = 1; i <= H; i++) {
				String tmp = in.readLine();
				for (int j = 1; j <= W; j++) {
					board[i][j] = tmp.charAt(j - 1);
					if (board[i][j] > '0') {
						tankPoint[0] = i;
						tankPoint[1] = j;
					}
				}
			}
			int cmdCnt = Integer.parseInt(in.readLine());

			cmd = in.readLine();
			solve();
			out.write("#" + test_case + " ");
			for (int i = 1; i < board.length - 1; i++) {
				for (int j = 1; j < board[0].length - 1; j++) {
					out.write(board[i][j]);
				}
				out.write("\n");
			}
		}

		out.flush();
		out.close();
		in.close();
	}
}

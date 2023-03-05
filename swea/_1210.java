import java.util.*;

class Sol_2023_02_07_11_24ee {
	static int[][] board = new int[100][100];
	static int goal_x = 0;
	static int goal_y = 0;
	// left , right
	static int dx[] = { -1, 1 };
	static int answer = 0;

	static boolean check(int y, int x) {
		if (x == -1 || x == 100 || board[y][x] == 0) {
			return false;
		}
		return true;
	}

	static int getNextX(int y, int x, int dir) {
		while (check(y, x)) {
			x += dx[dir];
		}
		return x -= dx[dir];
	}

	static void search(int y, int x) {
		if (y == 0) {
			answer = x;
			return;
		}
		y++;
		for (int i = 0; i < 2; i++) {
			if (check(y, x + dx[i])) {
				y--;
				x = getNextX(y, x, i);
				break;
			}
		}
		search(y, x);
		return;
	}

	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);

		for (int test_case = 1; test_case <= 10; test_case++) {
			int t = sc.nextInt();
			for (int i = 0; i < 100; i++) {
				for (int j = 0; j < 100; j++) {
					board[i][j] = sc.nextInt();
					if (board[i][j] == 2) {
						goal_x = j;
						goal_y = i;
					}
				}
			}
			search(goal_y, goal_y);

			System.out.println("#" + t + " " + answer);
		}
	}
}
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class _17135 {
	static final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static int board[][];
	static int D; // 궁수 사거리

	// 적 클래스
	public static class Enemy {
		static int count = 0;
		int y, x;

		Enemy(int y, int x) {
			this.y = y;
			this.x = x;
		}

		Enemy(Enemy e) {
			this.y = e.y;
			this.x = e.x;
		}

		boolean next(int y) {
			this.y += 1;
			return y != this.y;
		}
	}

	static List<Enemy> rawEnemies = new ArrayList<>();
	static int players[] = new int[3];

	public static void turnEnd(List<Enemy> enemies) {
		for (int i = enemies.size() - 1; i >= 0; i--) {
			if (!enemies.get(i).next(board.length)) {
				enemies.remove(i);
			}
		}
	}

	public static int getDist(int player, Enemy e) {
		return Math.abs(player - e.x) + Math.abs(board.length - e.y);
	}

	public static int attack(List<Enemy> enemies) {
		// 공격
		Set<Integer> attackedEnemies = new HashSet<>();
		for (int i = 0; i < players.length; i++) {
			int minDist = (int) 1e9;
			int minX = minDist;
			int minIdx = -1;

			for (int j = 0; j < enemies.size(); j++) {
				int dist = getDist(players[i], enemies.get(j));
				if (dist <= D) {
					boolean isUpdate = false;
					if (dist < minDist || (dist == minDist && enemies.get(j).x < minX)) {
						isUpdate = true;
					}
					if (isUpdate) {
						minDist = dist;
						minX = enemies.get(j).x;
						minIdx = j;
					}
				}
			}

			if (minIdx != -1) {
				attackedEnemies.add(enemies.get(minIdx).x + enemies.get(minIdx).y * board.length);
			}
		}

		for (int i = enemies.size() - 1; i >= 0; i--) {
			if (attackedEnemies.contains(enemies.get(i).x + enemies.get(i).y * board.length)) {
				enemies.remove(i);
			}
		}

		return attackedEnemies.size();
	}

	public static int simulation() {
		// 적 deepcopy
		List<Enemy> enemies = new ArrayList<>();
		for (int i = 0; i < rawEnemies.size(); i++) {
			enemies.add(new Enemy(rawEnemies.get(i)));
		}

		// 시뮬레이션
		int count = 0;
		while (enemies.size() > 0) {
			count += attack(enemies);
			turnEnd(enemies);
		}
		return count;
	}

	static int answer = 0;

	public static void combination(int idx, int count) {
		if (count == 3) {
			answer = Math.max(answer, simulation());
			return;
		}
		for (int i = idx; i < board[0].length; i++) {
			players[count] = i;
			combination(i + 1, count + 1);
		}
	}

	public static void main(String args[]) throws Exception {
		StringTokenizer st = new StringTokenizer(in.readLine());
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		D = Integer.parseInt(st.nextToken());

		board = new int[N][M];

		for (int i = 0; i < N; i++) {
			st = new StringTokenizer(in.readLine());
			for (int j = 0; j < M; j++) {
				board[i][j] = Integer.parseInt(st.nextToken());
				if (board[i][j] == 1) {
					rawEnemies.add(new Enemy(i, j));
				}
			}
		}

		combination(0, 0);
		out.write(answer + "");
		out.flush();
		out.close();
		in.close();
	}
}

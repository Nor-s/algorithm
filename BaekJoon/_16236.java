import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class _16236 {
	static final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

	// 물고기 M 마리
	// 아기 상어 1마리
	// 한칸에는 물고기 최대 1마리
	// 물고기는 모두 크기를 가짐
	// 이 크기는 자연수
	// - 가장 처음에 아기 상어의 크기는 2
	// - 아기 상어는 1초에 상하좌우로 한칸 씩 이동
	// - 아기 상어는 자신의 크기보다 큰 물고기가 있는 칸은 지나갈 수 없음
	// - 크기가 같으면 먹을 수 없음 but 지나갈 수 있음

	// 상어의 이동방법
	// - 1초에 한칸씩
	// - 먹을 수 있는 물고기가 공간에 없으면, 엄마 상어 호출
	// - 먹을 수 있는 물고기가 1마리 => 그 물고기 먹으로 감
	// - 먹을 수 있는 물고기가 1마리 이상 => 가까운 물고기
	// - 거리 = 최단 거리 칸의 개수
	// - 가장 위, 가장 왼쪽 부터

	// 이동 == 1초
	// 아기상어는 자신의 크기와 같은 수의 물고기를 먹으면 크기 증가

	// 몇초 동안 물고기를 잡아 먹을 수 있는지?

	public static class Fish {
		int y;
		int x;
		int size;
		int d = 0;

		Fish(int y, int x, int size, int d) {
			this.y = y;
			this.x = x;
			this.size = size;
			this.d = d;
		}
	}

	public static class Board {
		static final int dx[] = { 1, 0, -1, 0 };
		static final int dy[] = { 0, 1, 0, -1 };
		int board[][];
		int n;
		Fish shark = new Fish(0, 0, 2, 0);

		public void init() throws Exception {
			StringTokenizer st = new StringTokenizer(in.readLine());
			n = Integer.parseInt(st.nextToken());
			board = new int[n][n];

			for (int i = 0; i < n; i++) {
				st = new StringTokenizer(in.readLine());
				for (int j = 0; j < n; j++) {
					board[i][j] = Integer.parseInt(st.nextToken());
					if (board[i][j] == 9) {
						shark.y = i;
						shark.x = j;
					}
				}
			}
		}

		public void debug() {
			System.out.print("================\n");
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					System.out.print(board[i][j] + " ");
				}
				System.out.println();
			}
		}

		// bfs 탐색, 가장 왼쪽, 가장 위쪽
		public Fish find() {
			Queue<Fish> fishQueue = new ArrayDeque<>();
			List<Fish> eatableFishs = new ArrayList<>();
			boolean visited[][] = new boolean[n][n];
			int beforeDist = Integer.MAX_VALUE;

			visited[shark.y][shark.x] = true;
			fishQueue.add(shark);

			while (!fishQueue.isEmpty()) {
				Fish current = fishQueue.poll();

				if (beforeDist < current.d) {
					break;
				}

				if (0 < current.size && current.size < shark.size) {
					eatableFishs.add(current);
					if (beforeDist == Integer.MAX_VALUE) {
						beforeDist = current.d;
					}
				}

				for (int i = 0; i < 4; i++) {
					int ny = current.y + dy[i];
					int nx = current.x + dx[i];
					if (!(ny == -1 || nx == -1 || ny == n || nx == n || visited[ny][nx]
							|| board[ny][nx] > shark.size)) {
						Fish fish = new Fish(ny, nx, board[ny][nx], current.d + 1);
						visited[ny][nx] = true;
						fishQueue.add(fish);
					}
				}
			}

			Collections.sort(eatableFishs, (a, b) -> {
				int dist = a.d - b.d;
				if (dist == 0) {
					int tmp = a.y - b.y;
					if (tmp == 0) {
						return a.x - b.x;
					}
					return tmp;
				}
				return dist;
			});

			return eatableFishs.isEmpty() ? null : eatableFishs.get(0);
		}

		public int simulation() {
			int count = 0;
			int time = 0;

			while (true) {
				Fish fish = find();

				if (fish == null) {
					break;
				}
				time += fish.d;
				board[shark.y][shark.x] = 0;

				count++;
				if (count == shark.size) {
					shark.size++;
					count = 0;
				}

				shark.x = fish.x;
				shark.y = fish.y;
				shark.d = 0;
				board[shark.y][shark.x] = 9;
			}

			return time;
		}
	}

	public static void main(String args[]) throws Exception {
		Board board = new Board();
		board.init();
		out.write(board.simulation() + "");
		out.flush();
		out.close();
		in.close();
	}
}

/*
 * 
 * ================
 * 1 1 1 1 1 9
 * 2 2 6 2 2 3
 * 2 2 5 2 2 3
 * 2 2 2 4 6 3
 * 0 0 0 0 0 6
 * 0 0 0 0 0 0
 * 5 2
 * ================
 * 1 1 1 1 9 0
 * 2 2 6 2 2 3
 * 2 2 5 2 2 3
 * 2 2 2 4 6 3
 * 0 0 0 0 0 6
 * 0 0 0 0 0 0
 * 6 3
 * ================
 * 1 1 1 9 0 0
 * 2 2 6 2 2 3
 * 2 2 5 2 2 3
 * 2 2 2 4 6 3
 * 0 0 0 0 0 6
 * 0 0 0 0 0 0
 * 7 3
 * ================
 * 1 1 9 0 0 0
 * 2 2 6 2 2 3
 * 2 2 5 2 2 3
 * 2 2 2 4 6 3
 * 0 0 0 0 0 6
 * 0 0 0 0 0 0
 * 8 3
 * ================
 * 1 9 0 0 0 0
 * 2 2 6 2 2 3
 * 2 2 5 2 2 3
 * 2 2 2 4 6 3
 * 0 0 0 0 0 6
 * 0 0 0 0 0 0
 * 9 4
 * ================
 * 9 0 0 0 0 0
 * 2 2 6 2 2 3
 * 2 2 5 2 2 3
 * 2 2 2 4 6 3
 * 0 0 0 0 0 6
 * 0 0 0 0 0 0
 * 10 4
 * ================
 * 0 0 0 0 0 0
 * 9 2 6 2 2 3
 * 2 2 5 2 2 3
 * 2 2 2 4 6 3
 * 0 0 0 0 0 6
 * 0 0 0 0 0 0
 * 11 4
 * ================
 * 0 0 0 0 0 0
 * 0 9 6 2 2 3
 * 2 2 5 2 2 3
 * 2 2 2 4 6 3
 * 0 0 0 0 0 6
 * 0 0 0 0 0 0
 * 12 4
 * ================
 * 0 0 0 0 0 0
 * 0 0 6 2 2 3
 * 2 9 5 2 2 3
 * 2 2 2 4 6 3
 * 0 0 0 0 0 6
 * 0 0 0 0 0 0
 * 13 5
 * ================
 * 0 0 0 0 0 0
 * 0 0 6 2 2 3
 * 9 0 5 2 2 3
 * 2 2 2 4 6 3
 * 0 0 0 0 0 6
 * 0 0 0 0 0 0
 * 14 5
 * ================
 * 0 0 0 0 0 0
 * 0 0 6 2 2 3
 * 0 0 5 2 2 3
 * 9 2 2 4 6 3
 * 0 0 0 0 0 6
 * 0 0 0 0 0 0
 * 15 5
 * ================
 * 0 0 0 0 0 0
 * 0 0 6 2 2 3
 * 0 0 5 2 2 3
 * 0 9 2 4 6 3
 * 0 0 0 0 0 6
 * 0 0 0 0 0 0
 * 16 5
 * ================
 * 0 0 0 0 0 0
 * 0 0 6 2 2 3
 * 0 0 5 2 2 3
 * 0 0 9 4 6 3
 * 0 0 0 0 0 6
 * 0 0 0 0 0 0
 * 17 5
 * ================
 * 0 0 0 0 0 0
 * 0 0 6 2 2 3
 * 0 0 5 2 2 3
 * 0 0 0 9 6 3
 * 0 0 0 0 0 6
 * 0 0 0 0 0 0
 * 18 6
 * ================
 * 0 0 0 0 0 0
 * 0 0 6 2 2 3
 * 0 0 5 9 2 3
 * 0 0 0 0 6 3
 * 0 0 0 0 0 6
 * 0 0 0 0 0 0
 * 19 6
 * ================
 * 0 0 0 0 0 0
 * 0 0 6 9 2 3
 * 0 0 5 0 2 3
 * 0 0 0 0 6 3
 * 0 0 0 0 0 6
 * 0 0 0 0 0 0
 * 20 6
 * ================
 * 0 0 0 0 0 0
 * 0 0 6 0 9 3
 * 0 0 5 0 2 3
 * 0 0 0 0 6 3
 * 0 0 0 0 0 6
 * 0 0 0 0 0 0
 * 21 6
 * ================
 * 0 0 0 0 0 0
 * 0 0 6 0 0 9
 * 0 0 5 0 2 3
 * 0 0 0 0 6 3
 * 0 0 0 0 0 6
 * 0 0 0 0 0 0
 * 22 6
 * ================
 * 0 0 0 0 0 0
 * 0 0 6 0 0 0
 * 0 0 5 0 2 9
 * 0 0 0 0 6 3
 * 0 0 0 0 0 6
 * 0 0 0 0 0 0
 * 23 6
 * ================
 * 0 0 0 0 0 0
 * 0 0 6 0 0 0
 * 0 0 5 0 9 0
 * 0 0 0 0 6 3
 * 0 0 0 0 0 6
 * 0 0 0 0 0 0
 * 24 7
 * ================
 * 0 0 0 0 0 0
 * 0 0 6 0 0 0
 * 0 0 5 0 0 0
 * 0 0 0 0 9 3
 * 0 0 0 0 0 6
 * 0 0 0 0 0 0
 * 25 7
 * ================
 * 0 0 0 0 0 0
 * 0 0 6 0 0 0
 * 0 0 5 0 0 0
 * 0 0 0 0 0 9
 * 0 0 0 0 0 6
 * 0 0 0 0 0 0
 * 26 7
 * ================
 * 0 0 0 0 0 0
 * 0 0 6 0 0 0
 * 0 0 5 0 0 0
 * 0 0 0 0 0 0
 * 0 0 0 0 0 9
 * 0 0 0 0 0 0
 * 27 7
 * ================
 * 0 0 0 0 0 0
 * 0 0 6 0 0 0
 * 0 0 9 0 0 0
 * 0 0 0 0 0 0
 * 0 0 0 0 0 0
 * 0 0 0 0 0 0
 * 32 7
 * ================
 * 0 0 0 0 0 0
 * 0 0 9 0 0 0
 * 0 0 0 0 0 0
 * 0 0 0 0 0 0
 * 0 0 0 0 0 0
 * 0 0 0 0 0 0
 * 33 7
 * 33
 */
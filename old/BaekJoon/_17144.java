import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class _17144 {
	static final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

	// 공기 청정기는 항상 1번 열에 설치됨 (크기는 두 행을 차지
	// (r, c) 에 있는 미세먼지 양은 Arc
	// 1초 동안 다음 순서대로 일어남
	// 1. 미세먼지 확산. 미세먼지가 있는 모든 칸에서 동시에 일어남
	// - 미세먼지는 4방향으로 확산
	// - 확산되는 양은 Arc/5, 소수점은 버림
	// - (r, c) 에 남은 미세먼지 양 = Ar,c - (Ar,c/5) x 확산뵌 방향의 개수
	// - 공기 청정기 있는 칸으로는 확산 x
	// 2. 공기 청정기 작동
	// - 공기청정기 바람 위: 반시계방향으로 순환, 아래: 시계방향으로 순환
	// - 바람에 의해 미세먼지가 한칸씩 이동
	// - 공기 청정기에 들어간 미세먼지 모두 정화

	public static class Room {
		public static class Dust {
			int y;
			int x;
			int amount;

			Dust(int y, int x, int amount) {
				this.y = y;
				this.x = x;
				this.amount = amount;
			}
		}

		static final int dx[][] = { { 1, 0, -1, 0 }, { 1, 0, -1, 0 } };
		static final int dy[][] = { { 0, -1, 0, 1 }, { 0, 1, 0, -1 } };
		static final int UP = 0, DOWN = 1;
		int purifier[] = new int[2];
		int board[][];
		int r, c, t;
		Queue<Dust> dustQ = new ArrayDeque<>();

		public void spreadDust() {
			while (!dustQ.isEmpty()) {
				Dust currentDust = dustQ.poll();
				int y = currentDust.y;
				int x = currentDust.x;
				int amount = currentDust.amount;
				for (int i = 0; i < 4; i++) {
					int ny = y + dy[0][i];
					int nx = x + dx[0][i];
					if (ny < 0 || nx < 0 || nx >= c || ny >= r || board[ny][nx] == -1) {
						continue;
					}
					board[ny][nx] += amount / 5;
					board[y][x] -= amount / 5;
				}
			}
		}

		public void wind(int dir) {
			int position[] = { purifier[dir], 0 };
			int dxx[] = dx[dir];
			int dyy[] = dy[dir];
			int before = 0;
			for (int i = 0; i < 4; i++) {
				while (true) {
					int np[] = { position[0] + dyy[i], position[1] + dxx[i] };
					if (np[0] < 0 || np[1] < 0 || np[0] >= r || np[1] >= c || board[np[0]][np[1]] == -1) {
						break;
					}
					int tmp = board[np[0]][np[1]];
					board[np[0]][np[1]] = before;
					before = tmp;
					position = np;
				}
			}
		}

		public void workAirPurifier() {
			wind(DOWN);
			wind(UP);
		}

		public void updateDustQ() {
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					if (board[i][j] >= 0) {
						dustQ.add(new Dust(i, j, board[i][j]));
					}
				}
			}
		}

		public void timePass(int time) {
			for (int i = 0; i < time; i++) {
				spreadDust();
				workAirPurifier();
				updateDustQ();
				// debug();
			}
		}

		public void init() throws Exception {
			StringTokenizer st = new StringTokenizer(in.readLine());
			r = Integer.parseInt(st.nextToken());
			c = Integer.parseInt(st.nextToken());
			t = Integer.parseInt(st.nextToken());
			board = new int[r][c];

			int purifierCount = 0;
			for (int i = 0; i < r; i++) {
				st = new StringTokenizer(in.readLine());
				for (int j = 0; j < c; j++) {
					board[i][j] = Integer.parseInt(st.nextToken());
					if (board[i][j] == -1) {
						purifier[purifierCount++] = i;
					} else if (board[i][j] > 0) {
						dustQ.add(new Dust(i, j, board[i][j]));
					}
				}
			}
		}

		public int getDustAmount() {
			timePass(t);
			int sum = 0;
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					if (board[i][j] > 0) {
						sum += board[i][j];
					}
				}
			}
			return sum;
		}

		public void debug() {
			System.out.print("================\n");
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					System.out.print(board[i][j] + " ");
				}
				System.out.println();
			}
		}
	}

	public static void main(String args[]) throws Exception {
		Room room = new Room();
		room.init();
		out.write(room.getDustAmount() + "");
		out.flush();
		out.close();
		in.close();
	}
}

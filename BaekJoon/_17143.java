import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class _17143 {
	static final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static final int dx[] = { 0, 0, 1, -1 };
	static final int dy[] = { -1, 1, 0, 0 };
	static int version[][];
	static final int OLD_VERSION = -111111111;

	static class Shark {
		static Shark sharks[];
		int r, c, s, d, z;
		int ver = 0;

		public void changeDir() {
			d += ((d % 2) * -2) + 1;
		}

		public void move(int currentVer, int idx) {
			ver++;
			for (int i = 0; i < s; i++) {
				int nr = r + dy[d];
				int nc = c + dx[d];

				if (nr == -1 || nc == -1 || nr == version.length || nc == version[0].length) {
					changeDir();
					nr = r + dy[d];
					nc = c + dx[d];
				}

				r = nr;
				c = nc;
			}

			// 만약 먼저 상어가 와있으면 상어를 죽임
			if (version[r][c] == currentVer) {
				ver = OLD_VERSION;
			}

			version[r][c] = Math.max(version[r][c], ver);
		}
	}

	public static int sim() {
		int count = 0;

		for (int king = 0; king < version[0].length; king++) {
			// 제일 가까운 상어 잡음
			{
				int minY = -1;
				for (int i = 0; i < Shark.sharks.length; i++) {
					if (king != Shark.sharks[i].c || Shark.sharks[i].ver != king) {
						continue;
					}
					if (minY == -1 || Shark.sharks[i].r < Shark.sharks[minY].r) {
						minY = i;
					}
				}
				if (minY != -1) {
					Shark.sharks[minY].ver = OLD_VERSION;
					count += Shark.sharks[minY].z;
				}
			}

			// 상어들을 움직임, 내림차순으로 정렬되었으므로 먼저 움직인 상어가 전부 먹음
			for (int i = 0; i < Shark.sharks.length; i++) {
				Shark.sharks[i].move(king + 1, i);
			}
		}

		return count;

	}

	public static void main(String args[]) throws Exception {
		StringTokenizer st = new StringTokenizer(in.readLine());

		int R = Integer.parseInt(st.nextToken());
		int C = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());

		Shark.sharks = new Shark[M];
		version = new int[R][C];

		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(in.readLine());
			Shark.sharks[i] = new Shark();
			Shark.sharks[i].r = Integer.parseInt(st.nextToken()) - 1;
			Shark.sharks[i].c = Integer.parseInt(st.nextToken()) - 1;
			Shark.sharks[i].s = Integer.parseInt(st.nextToken());
			Shark.sharks[i].d = Integer.parseInt(st.nextToken()) - 1;
			Shark.sharks[i].z = Integer.parseInt(st.nextToken());
			Shark.sharks[i].ver = 0; // king 과 같은 번호일때 먹을 수 있음
		}
		// 내림차순 정렬
		Arrays.sort(Shark.sharks, (shark1, shark2) -> shark2.z - shark1.z);
		System.out.println(sim());

		out.flush();
		out.close();
		in.close();
	}
}
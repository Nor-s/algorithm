import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.StringTokenizer;

class Main {
	static final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

	static interface Op {
		public int move(int n);
	}

	static class Right implements Op {
		public int move(int n) {
			return n + 1;
		}
	}

	static class Left implements Op {
		public int move(int n) {
			return n - 1;
		}
	}

	static class Teleport implements Op {
		public int move(int n) {
			return 2 * n;
		}
	}

	static Op[] op = { new Teleport(), new Right(), new Left() };

	static int cached[];
	static int check[];

	// dp 메모이제이션 업데이트, 및 사용한 연산 체크 (왼쪽, 오른쪽, 순간이동)
	static void updateCached(int current, int num, int op) {
		if (num < cached[current]) {
			cached[current] = num;
			check[current] = op;
		}
	}

	static int search(int current, int target) {
		// 기저조건: 찾으면 끝
		if (current == target) {
			return 0;
		}
		// DP 만약 current 위치 계산이 처음이라면, 연산 수행
		if (cached[current] == 0) {
			cached[current] = (int) 1e9;

			// 만약 current가 더 높을 시  왼쪽으로만 이동
			if (target < current) {
				int next = op[2].move(current);
				updateCached(current, search(next, target) + 1, 2);
			} else {
				// 3가지 경우를 전부 다 해보고, 최소인것만 기록
				for (int i = 0; i < 3; i++) {
					int next = op[i].move(current);
					if (next != -1 && next < cached.length) {
						updateCached(current, search(next, target) + 1, i);
					}
				}
			}
		}
		return cached[current];
	}

	// 기록한 연산을보고 따라가며 해를 구함
	static void tracer(int current, int target) throws IOException {
		out.write(current + " ");
		if (current != target) {
			tracer(op[check[current]].move(current), target);
		}
	}

	public static void main(String args[]) throws Exception {
		StringTokenizer st = new StringTokenizer(in.readLine());
		// 0 ~ 100_000
		int N = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());
		check = new int[100000 + 100];
		cached = new int[100000 + 100];
		out.write(search(N, K) + "\n");
		tracer(N, K);

		out.flush();
		out.close();
		in.close();
	}
}
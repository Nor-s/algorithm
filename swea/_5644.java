import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class Solution_5644 {
	static final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static final int dx[] = { 0, 0, 1, 0, -1 };
	static final int dy[] = { 0, -1, 0, 1, 0 };
	static int a[];
	static int b[];

	static class AP implements Comparable<AP> {
		public int y;
		public int x;
		public int cover;
		public int power;
		public int hash;

		@Override
		public int compareTo(AP o) {
			return this.power - o.power;
		}

	};

	static class Person {
		public int y;
		public int x;

		public Person(int y, int x) {
			this.y = y;
			this.x = x;
		}

		public void next(int dir) {
			this.y += dy[dir];
			this.x += dx[dir];
		}
	};

	static public AP[] ap;

	public static int dist(AP ap1, Person p) {
		return Math.abs(p.y - ap1.y) + Math.abs(p.x - ap1.x);
	}

	public static List<AP> findAp(Person p) {
		List<AP> ret = new ArrayList<>();
		for (int i = 0; i < ap.length; i++) {
			if (dist(ap[i], p) <= ap[i].cover) {
				ret.add(ap[i]);
			}
		}
		return ret;
	}

	public static int solve() throws IOException {
		Person A = new Person(1, 1);
		Person B = new Person(10, 10);
		int answer = 0;

		for (int t = 0; t < a.length; t++) {
			A.next(a[t]);
			B.next(b[t]);

			List<AP> bAp = findAp(B);
			List<AP> aAp = findAp(A);

			int aCharge = 0;
			int bCharge = 0;
			Collections.sort(bAp, Collections.reverseOrder());
			Collections.sort(aAp, Collections.reverseOrder());

			bCharge = (bAp.size() > 0) ? bAp.get(0).power : 0;
			aCharge = (aAp.size() > 0) ? aAp.get(0).power : 0;
			if (bAp.size() > 0 && aAp.size() > 0) {
				// A와 B가 중복된 부분이 있을 때
				// 만약 가장 큰 값이 서로 다르면 그냥 더함
				if (bAp.get(0).hash == aAp.get(0).hash) {
					// A 와 B의 의 가장 큰 값이 같으면 분할 해야하므로 손해, 다음으로 큰 값을 찾음
					int a1 = (aAp.size() > 1) ? aAp.get(1).power : 0;
					int b1 = (bAp.size() > 1) ? bAp.get(1).power : 0;
					bCharge = Math.max(a1, b1);
				}
			}
			answer += aCharge + bCharge;
		}
		return answer;

	}

	// 만약 한 BC에 두 명의 사용자가 접속한 경우,
	// 접속한 사용자의 수만큼 충전 양을 균등하게 분배한다.
	public static void main(String args[]) throws Exception {
		int T = Integer.parseInt(in.readLine());

		for (int test_case = 1; test_case <= T; test_case++) {
			StringTokenizer st = new StringTokenizer(in.readLine());
			int M = Integer.parseInt(st.nextToken());
			int A = Integer.parseInt(st.nextToken());

			a = new int[M + 1];
			b = new int[M + 1];

			st = new StringTokenizer(in.readLine());
			a[0] = 0;
			for (int i = 1; i < M + 1; i++) {
				a[i] = Integer.parseInt(st.nextToken());
			}

			st = new StringTokenizer(in.readLine());
			b[0] = 0;
			for (int i = 1; i < M + 1; i++) {
				b[i] = Integer.parseInt(st.nextToken());
			}

			ap = new AP[A];
			for (int i = 0; i < A; i++) {
				st = new StringTokenizer(in.readLine());
				ap[i] = new AP();
				ap[i].x = Integer.parseInt(st.nextToken());
				ap[i].y = Integer.parseInt(st.nextToken());
				ap[i].cover = Integer.parseInt(st.nextToken());
				ap[i].power = Integer.parseInt(st.nextToken());
				ap[i].hash = i;
			}
			int answer = solve();

			out.write("#" + test_case + " " + answer + "\n");
		}

		out.flush();
		out.close();
		in.close();
	}
}
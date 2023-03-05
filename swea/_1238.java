import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class _1238 {
	static final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static int arrMat[][];

	static int bfs(int s) {
		Queue<Integer[]> q = new ArrayDeque<>();
		boolean visited[] = new boolean[101];

		visited[s] = true;
		ArrayList<ArrayList<Integer>> st = new ArrayList<>();
		st.add(new ArrayList<>());
		q.add(new Integer[] { s, 0 });

		int currentDist = 0;

		while (!q.isEmpty()) {
			Integer current[] = q.poll();
			int node = current[0];
			int dist = current[1];

			if (currentDist != dist) {
				st.add(new ArrayList<>());
				currentDist = dist;
			}

			st.get(st.size() - 1).add(node);

			for (int i = 0; i < 101; i++) {
				if (arrMat[node][i] == 1 && !visited[i]) {
					visited[i] = true;
					q.add(new Integer[] { i, dist + 1 });
				}
			}
		}

		ArrayList<Integer> back = st.get(st.size() - 1);
		Collections.sort(back);
		return back.get(back.size() - 1);
	}

	public static void main(String args[]) throws Exception {
		for (int test_case = 1; test_case <= 10; test_case++) {
			StringTokenizer st = new StringTokenizer(in.readLine());

			int N = Integer.parseInt(st.nextToken());
			int start = Integer.parseInt(st.nextToken());

			st = new StringTokenizer(in.readLine());
			arrMat = new int[101][101];
			for (int i = 0; i < N; i += 2) {
				int from = Integer.parseInt(st.nextToken());
				int to = Integer.parseInt(st.nextToken());
				arrMat[from][to] = 1;
			}

			out.write("#" + test_case + " " + bfs(start) + "\n");
		}

		out.flush();
		out.close();
		in.close();
	}
}

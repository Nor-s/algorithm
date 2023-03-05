import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class _3124 {
	static final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static ArrayList<ArrayList<int[]>> adjList;

	static class UF {
		int parent[];

		UF(int n) {
			parent = new int[n + 1];
			for (int i = 0; i < parent.length; i++) {
				parent[i] = i;
			}
		}

		int find(int u) {
			if (u == parent[u]) {
				return u;
			}
			return parent[u] = find(parent[u]);
		}

		void merge(int u, int v) {
			parent[find(u)] = parent[find(v)];
		}
	};

	static long kruskal() {
		ArrayList<int[]> edges = new ArrayList<>();

		// V + E
		for (int i = 0; i < adjList.size(); i++) {
			for (int j = 0; j < adjList.get(i).size(); j++) {
				edges.add(new int[] { i, adjList.get(i).get(j)[0], adjList.get(i).get(j)[1] });
			}
		}
		UF uf = new UF(adjList.size());

		// E log E
		Collections.sort(edges, (a, b) -> a[2] - b[2]);
		long ret = 0;

		// E log E
		for (int i = 0; i < edges.size(); i++) {
			int a = edges.get(i)[0];
			int b = edges.get(i)[1];
			int c = edges.get(i)[2];

			if (uf.find(a) != uf.find(b)) {
				uf.merge(b, a);
				ret += c;
			}
		}

		return ret;
	}

	// 프림 배열 방법
	static long prim() {
		boolean visited[] = new boolean[adjList.size()];
		int current = 0;
		long ret = 0;

		long[] dist = new long[adjList.size()];
		Arrays.fill(dist, Integer.MAX_VALUE);
		visited[0] = true;

		// V*V + E 100,000 * 100,000
		for (int i = 0; i < adjList.size(); i++) {
			int minIdx = 0;
			long minCost = Integer.MAX_VALUE;

			// 현재 연결된 간선들 중 최소를 고름
			for (int j = 0; j < dist.length; j++) {
				long c = dist[j];
				if (!visited[j] && c < minCost) {
					minIdx = j;
					minCost = c;
				}
			}
			if (minCost != Integer.MAX_VALUE) {
				current = minIdx;
				ret += minCost;
				visited[current] = true;
			}

			// 새로운 간선 거리 업데이트
			for (int j = 0; j < adjList.get(current).size(); j++) {
				int b = (int) adjList.get(current).get(j)[0];
				long c = adjList.get(current).get(j)[1];
				dist[b] = Math.min(c, dist[b]);
			}
		}
		return ret;
	}

	// 프림 pq 방법
	static long prim2() {
		PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> a[1] - b[1]);
		int dist[] = new int[adjList.size()];
		long ret = 0;
		int count = 0;

		Arrays.fill(dist, Integer.MAX_VALUE);
		dist[0] = 0;
		pq.add(new int[] { 0, 0 });

		// E*logV + E
		while (!pq.isEmpty()) {
			// 현재 연결된 간선 중 가장 비용이 낮은 것 가져옴
			int[] first = pq.poll();
			int current = first[0];
			int cost = first[1];

			// 이미 방문했으면 스킵
			if (dist[current] < cost) {
				continue;
			}

			count++;
			ret += (long) cost;
			dist[current] = cost;

			// 모든 노드를 방문했으면 중단.
			if (count == adjList.size()) {
				break;
			}

			// 추가한 노드와 연결되어 있고, 아직 방문하지 않은 노드를 추가
			int size = adjList.get(current).size();
			for (int i = 0; i < size; i++) {
				int next[] = adjList.get(current).get(i);
				int nextNode = next[0];

				if (dist[nextNode] == Integer.MAX_VALUE) {
					pq.add(next);
				}
			}
		}

		return ret;
	}

	public static void main(String args[]) throws Exception {
		int T = Integer.parseInt(in.readLine());

		for (int test_case = 1; test_case <= T; test_case++) {
			StringTokenizer st = new StringTokenizer(in.readLine());

			int V = Integer.parseInt(st.nextToken());
			int E = Integer.parseInt(st.nextToken());

			adjList = new ArrayList<ArrayList<int[]>>();
			for (int i = 0; i < V; i++) {
				adjList.add(new ArrayList<>());
			}

			for (int i = 0; i < E; i++) {
				st = new StringTokenizer(in.readLine());
				int A = Integer.parseInt(st.nextToken());
				int B = Integer.parseInt(st.nextToken());
				int C = Integer.parseInt(st.nextToken());
				A--;
				B--;

				adjList.get(A).add(new int[] { B, C });
				adjList.get(B).add(new int[] { A, C });
			}

			// out.write("#" + test_case + " " + prim2() + "\n");
			out.write("#" + test_case + " " + kruskal() + "\n");
		}

		out.flush();
		out.close();
		in.close();
	}
}

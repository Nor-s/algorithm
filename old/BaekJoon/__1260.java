import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class Main {
	static final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static ArrayList<ArrayList<Integer>> adjList;

	static void makeGraph(int v) {
		adjList = new ArrayList<ArrayList<Integer>>();
		for (int i = 0; i < v; i++) {
			adjList.add(new ArrayList<>());
		}
	}

	static void dfs(int v, boolean[] visited) throws IOException {
		visited[v] = true;
		out.write(String.valueOf(v + 1) + " ");

		ArrayList<Integer> edges = adjList.get(v);
		for (int i = 0; i < edges.size(); i++) {
			int node = edges.get(i);
			if (!visited[node]) {
				dfs(node, visited);
			}
		}
	}

	static void bfs(int v) throws IOException {
		ArrayDeque<Integer> adq = new ArrayDeque<>();
		boolean[] visited = new boolean[adjList.size()];

		visited[v] = true;
		adq.add(v);

		while (!adq.isEmpty()) {
			int node = adq.pollFirst();
			ArrayList<Integer> edges = adjList.get(node);
			out.write(String.valueOf(node + 1) + " ");

			for (int i = 0; i < edges.size(); i++) {
				int nnode = edges.get(i);
				if (!visited[nnode]) {
					adq.add(nnode);
					visited[nnode] = true;
				}
			}
		}
	}

	public static void main(String args[]) throws Exception {
		StringTokenizer st = new StringTokenizer(in.readLine());
		int N = Integer.parseInt(st.nextToken());
		int M = Integer.parseInt(st.nextToken());
		int V = Integer.parseInt(st.nextToken());

		makeGraph(N);
		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(in.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			a--;
			b--;
			adjList.get(a).add(b);
			adjList.get(b).add(a);
		}
		for (int i = 0; i < N; i++) {
			Collections.sort(adjList.get(i));
		}
		dfs(V - 1, new boolean[N]);
		out.write("\n");
		bfs(V - 1);

		out.flush();
		out.close();
		in.close();
	}
}

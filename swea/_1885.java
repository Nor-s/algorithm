import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class _1885 {
	static final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

	static class Node {
		List<Node> children = new ArrayList<>();
		int idx;
	}

	static Node nodes[] = new Node[100001];

	static public class Node2 {
		Node node;
		int depth;

		Node2(Node node, int depth) {
			this.node = node;
			this.depth = depth;
		}
	}

	static public void bfs() {
		Queue<Node2> q = new LinkedList<>();
		boolean visited[] = new boolean[100001];
		visited[1] = true;
		q.add(new Node2(nodes[1], 0));
		int answer
		while (!q.isEmpty()) {
			Node2 node = q.poll();

			for (Node child : node.node.children) {
				if(!visited[child.idx]) {
					q.add(new Node2(child, node.depth + 1));
				}
			}
		}
	}

	public static void main(String args[]) throws Exception {
		int T = Integer.parseInt(in.readLine());

		for (int test_case = 1; test_case <= T; test_case++) {
			for(int i = 0; i <)
			int N = Integer.parseInt(in.readLine());

			out.write("#" + test_case + "\n");
		}

		out.flush();
		out.close();
		in.close();
	}
}

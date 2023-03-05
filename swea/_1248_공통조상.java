import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class _1248_공통조상 {
	static class Node {
		Node left = null;
		Node right = null;
		Node parent = null;
		int val;
		int count = 0;

		Node(Node left, Node right) {
			this.left = left;
			this.right = right;
		}

		Node add(Node node) {
			node.parent = this;
			if (left == null) {
				left = node;
			} else {
				right = node;
			}
			Node tmp = this;
			int count = node.count + 1;
			while (tmp != null) {
				tmp.count += count;
				tmp = tmp.parent;
			}
			return this;
		}
	}

	static final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static Node nodes[] = new Node[10001];

	public static int LCA(int a, int b) {
		Node nodeA = nodes[a];
		Node nodeB = nodes[b];
		Set<Integer> set = new HashSet<>();

		while (nodeA != null) {
			set.add(nodeA.val);
			nodeA = nodeA.parent;
		}

		while (nodeB != null) {
			if (set.contains(nodeB.val)) {
				return nodeB.val;
			}
			nodeB = nodeB.parent;
		}

		return 0;
	}

	public static void main(String args[]) throws Exception {
		int T = Integer.parseInt(in.readLine());

		for (int test_case = 1; test_case <= T; test_case++) {
			for (int i = 0; i < 10001; i++) {
				nodes[i] = new Node(null, null);
				nodes[i].val = i;
			}
			StringTokenizer st = new StringTokenizer(in.readLine());
			int V = Integer.parseInt(st.nextToken());
			int E = Integer.parseInt(st.nextToken());
			int A = Integer.parseInt(st.nextToken());
			int B = Integer.parseInt(st.nextToken());

			st = new StringTokenizer(in.readLine());
			for (int i = 0; i < E; i++) {
				int a = Integer.parseInt(st.nextToken());
				int b = Integer.parseInt(st.nextToken());

				nodes[a].add(nodes[b]);
			}
			int p = LCA(A, B);
			out.write("#" + test_case + " " + p + " " + nodes[p].count + "\n");
		}

		out.flush();
		out.close();
		in.close();
	}
}

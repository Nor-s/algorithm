import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class No_7_9_중위순회 {
	static final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

	static class Node {
		Node left = null;
		Node right = null;
		Character ch = null;

		Node(Node left, Node right, Character ch) {
			set(left, right, ch);
		}

		public void set(Node left, Node right, Character ch) {
			this.left = left;
			this.right = right;
			this.ch = ch;
		}
	}

	static final Node nodes[] = new Node[101];

	public static void inorder(Node node) throws IOException {
		if (node == null || node.ch == null)
			return;
		inorder(node.left);
		out.write(String.valueOf(node.ch));
		inorder(node.right);
	}

	public static void main(String args[]) throws Exception {

		for (int i = 0; i <= 100; i++) {
			nodes[i] = new Node(null, null, null);
		}

		for (int test_case = 1; test_case <= 10; test_case++) {
			int N = Integer.parseInt(in.readLine());

			for (int i = 0; i < N; i++) {
				String[] line = in.readLine().split(" ");
				int num = Integer.parseInt(line[0]);
				char ch = line[1].charAt(0);

				if (line.length == 4) {
					int left = Integer.parseInt(line[2]);
					int right = Integer.parseInt(line[3]);

					nodes[num].set(nodes[left], nodes[right], ch);
				} else if (line.length == 3) {
					int left = Integer.parseInt(line[2]);

					nodes[num].set(nodes[left], null, ch);
				} else {
					nodes[num].set(null, null, ch);
				}
			}
			out.write("#" + test_case + " ");
			inorder(nodes[1]);
			out.write("\n");
		}

		out.flush();
		out.close();
		in.close();
	}
}

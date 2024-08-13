import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class Main_1158 {
	static final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static Node nodes[] = new Node[5001];

	static {
		// 노드 풀 생성
		for (int i = 0; i < 5001; i++) {
			nodes[i] = new Node();
		}
	}

	// 더블 링크드 리스트의 노드
	static class Node {
		int val = -1;
		Node right = null;
		Node left = null;
	}

	public static void main(String args[]) throws Exception {
		StringBuilder sb = new StringBuilder();
		StringTokenizer st = new StringTokenizer(in.readLine());
		int N = Integer.parseInt(st.nextToken());
		int K = Integer.parseInt(st.nextToken());

		// 노드를 환형 링크드 리스트로 구성
		for (int i = 0; i < N; i++) {
			nodes[i].val = i + 1;
			nodes[i].right = nodes[(i + 1) % N];
			nodes[i].left = nodes[(i == 0) ? N - 1 : i - 1];
		}

		Node tmp = nodes[0];
		int die = 0;

		sb.append('<');
		while (tmp.right != tmp) {
			// 링크드 리스트를 순회하면서 K 번째 제거
			if (++die == K) {
				die = 0;
				sb.append(tmp.val).append(", ");
				tmp.left.right = tmp.right;
				tmp.right.left = tmp.left;
			}
			tmp = tmp.right;
		}
		sb.append(tmp.val).append('>');

		out.write(sb.toString());

		out.flush();
		out.close();
		in.close();
	}
}

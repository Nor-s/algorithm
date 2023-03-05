import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class _3289 {
	static final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

	static class UF {
		int parent[];
		int rank[];

		UF(int n) {
			parent = new int[n + 1];
			rank = new int[n + 1];
			for (int i = 0; i < n + 1; i++) {
				parent[i] = i;
				rank[i] = 1;
			}
		}

		int getParent(int u) {
			if (parent[u] == u) {
				return u;
			}
			return parent[u] = getParent(parent[u]);
		}

		boolean isSameParent(int u, int v) {
			return getParent(u) == getParent(v);
		}

		void merge(int u, int v) {
			int uparent = getParent(u);
			int vparent = getParent(v);
			if (isSameParent(uparent, vparent)) {
				return;
			}
			if (rank[uparent] > rank[vparent]) {
				int tmp = uparent;
				uparent = vparent;
				vparent = tmp;
			}
			parent[uparent] = vparent;
			rank[vparent] = Math.max(rank[uparent] + 1, rank[vparent]);
			return;
		}
	}

	public static void main(String args[]) throws Exception {
		int T = Integer.parseInt(in.readLine());

		for (int test_case = 1; test_case <= T; test_case++) {
			StringTokenizer st = new StringTokenizer(in.readLine());
			int n = Integer.parseInt(st.nextToken());
			int m = Integer.parseInt(st.nextToken());

			UF uf = new UF(n);

			out.write("#" + test_case + " ");

			for (int i = 0; i < m; i++) {
				st = new StringTokenizer(in.readLine());
				int op = Integer.parseInt(st.nextToken());
				int a = Integer.parseInt(st.nextToken());
				int b = Integer.parseInt(st.nextToken());
				if (op == 0) {
					uf.merge(a, b);
				} else {
					out.write((uf.isSameParent(a, b)) ? '1' : '0');
				}
			}
		}

		out.flush();
		out.close();
		in.close();
	}
}

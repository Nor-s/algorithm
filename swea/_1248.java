import java.util.Scanner;
import java.util.*;

class Solution {
    public static int V;
    public static int E;
    public static int A;
    public static int B;
    public static ArrayList<ArrayList<Integer>> Arr;
    public static int[] parent;

    public static int get_subtree_size(int idx) {
        int ret = Arr.get(idx).size();
        for (int i = 0; i < Arr.get(idx).size(); i++) {
            ret += get_subtree_size(Arr.get(idx).get(i));
        }
        return ret;
    }

    public static int get_LCA(int a, int b) {
        int[] visited = new int[V + 1];
        
        while (visited[a] != 1) {
            visited[a] = 1;
            a =  parent[a];
        }
        while (visited[b] != 1) {
            visited[b] = 1;
            b =  parent[b];
        }
        return b;
    }

    public static void main(String args[]) throws Exception {
        Scanner sc = new Scanner(System.in);
        int T;
        T = sc.nextInt();
        for (int test_case = 1; test_case <= T; test_case++) {
            V = sc.nextInt();
            E = sc.nextInt();
            A = sc.nextInt();
            B = sc.nextInt();
            Arr = new ArrayList<>();
            parent = new int[V+1];
            for (int i = 0; i < V + 1; i++) {
                Arr.add(new ArrayList<Integer>());
            }

            for (int i = 0; i < E; i++) {
                int p = sc.nextInt();
                int c = sc.nextInt();
                Arr.get(p).add(Integer.valueOf(c));
                parent[c] = p;
            }
            int LCA = get_LCA(A, B);
            int size = get_subtree_size(LCA) + 1;

            System.out.println("#" + test_case + " " + LCA + " " + size);
        }
    }
}
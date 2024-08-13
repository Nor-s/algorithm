import java.util.*;

class Sol_2023_01_18_08_35 {
	public static double building[];

	public static int check(int idx) {
		int count = 0;
		// right
		ArrayList<Double> right_stack = new ArrayList<>();
		for (int i = idx+1; i < building.length; i++) {
			double dydx = (building[idx] - building[i])/(double)(idx - i);

			if(right_stack.size() == 0 || right_stack.get(right_stack.size() - 1) < dydx) {
				right_stack.add(dydx);
				count++;
			}
		}

		// left
		ArrayList<Double> left_stack = new ArrayList<>();
		for (int i = idx-1; i >= 0; i--) {
			double dydx = (building[idx] - building[i])/(double)(idx - i);

			if(left_stack.size() == 0 || left_stack.get(left_stack.size() - 1) > dydx) {
				left_stack.add(dydx);
				count++;
			}
		}
		return count;
	}

	public static int solve() {
		int max = Integer.MIN_VALUE;
		for(int i = 0; i < building.length; i++) {
			int chk = check(i);
			max = Math.max(max, chk);
		}
		return max;
	}
	/* 
	15
	1 5 3 2 6 3 2 6 4 2 5 7 3 1 5
	*/
	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
		int N;
		N = sc.nextInt();
		building = new double[N];

		for (int i = 0; i < N; i++) {
			building[i] = (double)sc.nextInt();
		}
		System.out.println(solve());
		sc.close();
	}
}
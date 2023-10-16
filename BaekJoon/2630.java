import java.util.*;

class Solutionad {
	public static int[][] board;
	public static int[] color = new int[2];

	public static boolean check(int y, int x, int size) {
		int sum = 0;
		int product = 1;

		for(int i = y; i < y + size; i++) 
		{
			for(int j = x; j < x + size; j++)  
			{
				sum += board[i][j];
				product *= board[i][j];
			}
		}
		if(sum == 0 || product == 1) 
		{
			color[product]++;
			return true;
		}
		return false;
	}

	public static void dp(int y, int x, int size) 
	{
		if(!check(y, x, size)) {
			dp(y, x, size/2);
			dp(y, x + size/2, size/2);
			dp(y + size/2, x, size/2);
			dp(y + size/2, x + size/2, size/2);
		}
	}

	public static void main(String args[]) throws Exception
	{
		Scanner sc = new Scanner(System.in);
		int N;

		N=sc.nextInt();
		board = new int[N][N];

		for(int i = 0; i < N; i++)
		{
			for(int j = 0; j < N; j++) {
				board[i][j] = sc.nextInt();
			}
		}
		dp(0, 0, N);
		System.out.println(color[0]);
		System.out.println(color[1]);

		sc.close();
	}
}
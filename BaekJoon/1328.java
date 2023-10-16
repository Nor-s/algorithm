import java.util.*;

/**

가능한 빌딩 순서의 경우의 수를 구하는 프로그램을 작성하시오.

3 2 2
-> 2

//15824
 */
class Sol_2023_01_17_11_19
{
	static final long DIV =  1000000007L;
	static int N;
	static int L;
	static int R;
	// 가장 큰것의 위치를 먼저 결정 => 재귀 div

	public static int tmp() {
		int left = L - 1;
		int right = N - L - 1;
		while(right >= R) 
		{
			// leftCL =>        NCleft .. N개 중 left 선택 x       left개 중에서 L 개 선택 ...... X left 개 자리 선정 
			left++;right--;
		}
	}
	public static void main(String args[]) throws Exception
	{
		Scanner sc = new Scanner(System.in);
		N = sc.nextInt();
		L = sc.nextInt();
		L--;
		R = sc.nextInt();
		R--;
		
	}
}
import java.util.*;

class Sol_2023_02_07_14_27
{
	public void solver() {
	}
	public static void main(String args[]) throws Exception
	{
		Scanner sc = new Scanner(System.in);

		for(int test_case = 1; test_case <= 10; test_case++)
		{
			int dump = sc.nextInt(); 
			int[] box = new int[100];

			for(int i = 0 ; i < 100; i++) {
				box[i] = sc.nextInt();
			}

			for(int i = 0; i < dump; i++) {
				if(box[99] == box[0]) {
					break;
				}
				box[0]++;
				box[99]--;
				if(test_case == 6) {
					System.out.println(box);
				}
			}
			Arrays.sort(box);
			int answer =  box[99] - box[0] + 2;
			System.out.println("#" + test_case + " " + answer);
		}
	}
}
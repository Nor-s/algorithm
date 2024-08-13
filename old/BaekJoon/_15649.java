import java.util.*;

class Sol_2023_02_07_11_25
{
	// 길이 M인 수열을 구하는 함수
	static void perm(int n, int m, List<Integer> number, List<Boolean> checked) {
		// 기저조건: m개 선택 완료 하면 출력
		if(m == 0) {
			for(int i = 0; i < number.size(); i++) {
				System.out.print(number.get(i) + " ");
			}
			System.out.print("\n");
			return;
		}
		// 1~n개의 숫자를 탐색
		for(int i = 1; i <= n; i++) {
			// 만약, 이미 numbers에 있다면 스킵
			if(checked.get(i)) continue;
			// 숫자 선택 및 체크
			checked.set(i, true);
			number.add(i);
			// 길이 M - 1 인 수열을 구함
			perm(n, m - 1, number, checked);
			// 숫자 해제 및 언체크
			number.remove(number.size() - 1) ;
			checked.set(i, false);
		}
	}
	public static void main(String args[]) throws Exception
	{
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		List<Integer> number = new ArrayList<>();
		List<Boolean> checked = new ArrayList<>();
		for(int i = 0; i <= n; i++) {
			checked.add(false);
		}
		perm(n , m, number, checked);
	}
}
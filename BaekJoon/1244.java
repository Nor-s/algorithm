import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

class Sol_2023_02_07_16_29 {
	static int s[];
	// 남학생은 스위치 번호가 자기가 받은 수의 배수이면,
	// 그 스위치의 상태를 바꾼다. 즉, 스위치가 켜져 있으면 끄고,
	// 꺼져 있으면 켠다.
	// <그림 1>과 같은 상태에서 남학생이 3을 받았다면,
	// 이 학생은 <그림 2>와 같이 3번, 6번 스위치의 상태를 바꾼다.

	public static void male(int num) {
		for (int i = num - 1; i < s.length; i += num) {
			s[i] = (s[i] + 1) % 2;
		}
	}

	public static void female(int left, int right) {
		while (left != -1 && right != s.length && s[left] == s[right]) {
			s[left] = s[right] = (s[right] + 1) % 2;
			--left;
			++right;
		}
	}

	public static void main(String args[]) throws Exception {
		Scanner sc = new Scanner(System.in);
		int switchNum = sc.nextInt();

		s = new int[switchNum];
		for (int i = 0; i < switchNum; i++) {
			s[i] = sc.nextInt();
		}

		int studentNum = sc.nextInt();
		// 넷째 줄부터 마지막 줄까지 한 줄에
		// 한 학생의 성별, 학생이 받은 수가 주어진다.
		for (int i = 0; i < studentNum; i++) {
			int gender = sc.nextInt();
			int num = sc.nextInt();
			if (gender == 1) {
				male(num);
			} else {
				female(num - 1, num - 1);
			}
		}
		StringBuilder sb = new StringBuilder();
		for (int i = 1; i <= s.length; i++) {
			sb.append(s[i - 1]);
			sb.append(" ");
			if (i % 20 == 0) {
				sb.append("\n");
			}
		}
		System.out.println(sb.toString());
	}
}
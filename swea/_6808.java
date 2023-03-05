import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class Solution_6808 {
	static final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	static int[] kyuCard;
	static int[] inCard;
	static int kyu = 0;

	public static void swap(int arr[], int aidx, int bidx) {
		int temp = arr[aidx];
		arr[aidx] = arr[bidx];
		arr[bidx] = temp;
	}

	public static boolean nextPerm(int[] arr) {
		int n = arr.length;
		int i = n - 1;
		while (i > 0 && arr[i - 1] >= arr[i]) {
			i--;
		}
		if (i == 0) {
			return false;
		}
		int j = n - 1;
		while (arr[i - 1] >= arr[j]) {
			j--;
		}

		int k = n - 1;
		swap(arr, i - 1, j);
		while (i < k) {
			swap(arr, i, k);
			k--;
			i++;
		}
		return true;
	}

	static int calcScore() {
		int kyuScore = 0;
		int inScore = 0;
		for (int i = 0; i < kyuCard.length; i++) {
			int score = kyuCard[i] + inCard[i];
			if (kyuCard[i] > inCard[i]) {
				kyuScore += score;
			} else {
				inScore += score;
			}
		}
		return kyuScore - inScore;
	}

	public static void main(String args[]) throws Exception {
		int T = Integer.parseInt(in.readLine());

		for (int test_case = 1; test_case <= T; test_case++) {
			StringTokenizer st = new StringTokenizer(in.readLine());
			kyuCard = new int[9];
			inCard = new int[9];
			kyu = 0;
			for (int i = 0; i < 9; i++) {
				kyuCard[i] = Integer.parseInt(st.nextToken());
				kyu |= (1 << kyuCard[i]);
			}
			for (int i = 1, j = 0; i < 19; i++) {
				if ((kyu & (1 << i)) == 0) {
					inCard[j++] = i;
				}
			}

			int inWin = 0;
			int kyuWin = 0;
			do {
				int score = calcScore();
				if (score > 0) {
					kyuWin++;
				} else if (score < 0) {
					inWin++;
				}
			} while (nextPerm(inCard));

			out.write("#" + test_case + " " + kyuWin + " " + inWin + "\n");
		}

		out.flush();
		out.close();
		in.close();
	}
}

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class _16935 {
	static final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
	static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

	public static interface Operation {
		public abstract int[][] work(int arr[][]);

		public default void swap(int arr[][], int y, int x, int yy, int xx) {
			int tmp = arr[y][x];
			arr[y][x] = arr[yy][xx];
			arr[yy][xx] = tmp;
		}
	}

	public static class FlipUpDown implements Operation {
		@Override
		public int[][] work(int arr[][]) {
			int H = arr.length;
			int halfH = H / 2;
			for (int i = 0; i < halfH; i++) {
				for (int j = 0; j < arr[0].length; j++) {
					swap(arr, i, j, H - i - 1, j);
				}
			}
			return arr;
		}
	}

	public static class FlipLeftRight implements Operation {
		@Override
		public int[][] work(int arr[][]) {
			int W = arr[0].length;
			int halfW = W / 2;
			for (int i = 0; i < arr.length; i++) {
				for (int j = 0; j < halfW; j++) {
					swap(arr, i, j, i, W - j - 1);
				}
			}
			return arr;
		}
	}

	public static class RotateCW implements Operation {
		@Override
		public int[][] work(int arr[][]) {
			return rotate(arr, 1);
		}

		public int[][] rotate(int arr[][], int dir) {
			int[][] ret = new int[arr[0].length][arr.length];
			for (int i = 0; i < arr.length; i++) {
				for (int j = 0; j < arr[0].length; j++) {
					if (dir == 1) {
						int ni = j;
						int nj = arr.length - 1 - i;
						ret[ni][nj] = arr[i][j];
					}
					if (dir == -1) {
						int ni = arr[0].length - 1 - j;
						int nj = i;
						ret[ni][nj] = arr[i][j];
					}
				}
			}
			return ret;
		}
	}

	public static class RotateCCW implements Operation {
		@Override
		public int[][] work(int arr[][]) {
			RotateCW rotate = new RotateCW();
			return rotate.rotate(arr, -1);
		}
	}

	public static class RotatBatchCW implements Operation {
		@Override
		public int[][] work(int arr[][]) {
			arr = this.swap(arr, 1, 2);
			arr = this.swap(arr, 1, 3);
			return this.swap(arr, 1, 4);
		}

		public int[] getStartPoint(int[][] arr, int i) {
			int[] point = new int[2];
			int[] y = { 0, 0, arr.length / 2, arr.length / 2 };
			int[] x = { arr[1].length / 2, arr[1].length / 2, 0, 0 };
			point[0] = y[i - 1];
			point[1] = x[i - 1];
			return point;
		}

		public int[][] swap(int arr[][], int a, int b) {
			int[] aPoint = getStartPoint(arr, a);
			int[] bPoint = getStartPoint(arr, b);
			int endH = aPoint[0] + arr.length / 2;
			int endW = aPoint[1] + arr[0].length / 2;

			for (int i = aPoint[0], ii = bPoint[0]; i < endH; i++, ii++) {
				for (int j = aPoint[1], jj = bPoint[1]; j < endW; j++, jj++) {
					swap(arr, i, j, ii, jj);
				}
			}
			return arr;
		}
	}

	public static class RotatBatchCCW implements Operation {
		@Override
		public int[][] work(int arr[][]) {
			RotatBatchCW rbcw = new RotatBatchCW();
			arr = rbcw.swap(arr, 1, 4);
			arr = rbcw.swap(arr, 1, 3);
			return rbcw.swap(arr, 1, 2);
		}
	}

	public static class MagicArray {
		int arr[][];
		Operation[] op = { new FlipUpDown(), new FlipLeftRight(), new RotateCW(), new RotateCCW(), new RotatBatchCW(),
				new RotatBatchCCW() };

		public void init(BufferedReader br) throws IOException {
			StringTokenizer st = new StringTokenizer(br.readLine());
			int N = Integer.parseInt(st.nextToken());
			int M = Integer.parseInt(st.nextToken());
			int R = Integer.parseInt(st.nextToken());

			arr = new int[N][M];

			for (int i = 0; i < N; i++) {
				st = new StringTokenizer(br.readLine());
				for (int j = 0; j < M; j++) {
					arr[i][j] = Integer.parseInt(st.nextToken());
				}
			}
			String[] s = br.readLine().split(" ");
			int opIdxArr[] = new int[s.length];
			for (int i = 0; i < s.length; i++) {
				opIdxArr[i] = s[i].charAt(0) - '0' - 1;
			}

			for (int i = 0; i < R; i++) {
				arr = op[opIdxArr[i % opIdxArr.length]].work(arr);
			}
		}

		public void print(BufferedWriter bw) throws IOException {
			for (int i = 0; i < arr.length; i++) {
				for (int j = 0; j < arr[0].length; j++) {
					bw.write(arr[i][j] + " ");
				}
				bw.write("\n");
			}
		}
	}

	public static void main(String args[]) throws Exception {
		MagicArray ma = new MagicArray();
		ma.init(in);
		ma.print(out);

		out.flush();
		out.close();
		in.close();
	}
}

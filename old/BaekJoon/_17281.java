import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.*;

class _17281 {
    static final BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
    static final BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    // 9 명 두팀 공격 수비 번갈아 수행
    // - 총 N 이밍동안 진행
    // - 한 이닝에 3아웃 == 종료, 공수 교대

    // 경기 시작전
    // - 타순 정함
    // - 9번타자가 공을 쳤는데 3 아웃 x 면 이닝은 끝나지않고, 1버 타자 다시
    // - 타순은 이닝이 변경되어도 유지, 첫 타자는 이전 이닝의 마지막 타자 다음 순

    // 공격
    // - 투수가 던진 공을 타자가 치는 것
    // - 1루, 2루, 3루, 홈에 도착하면 1점을 득점
    // - 타자가 홈에 도착하지 못하고, 1루, 2루, 3루 중 하나에 머물러 있을 수 이음

    // 안타: 타자 + 모든 주자 한루씩 1
    // 2루타: 타자 + 모두 주자 2루 2
    // 3루 : + 3루 3
    // 홈런 : + 전부 홈 4
    // 아웃 : 0 , 아웃 증가

    static Integer score[][];
    static Integer order[] = new Integer[9];
    static boolean visited[] = new boolean[9];
    static int answer = 0;
    static boolean ru[] = new boolean[4];

    static int moveRu(int score) {
        ru[0] = true;
        int count = 0;
        for (int i = ru.length - 1; i >= 0; i--) {
            if (ru[i]) {
                ru[i] = false;
                if (i + score > ru.length - 1) {
                    count++;
                } else {
                    ru[i + score] = true;
                }
            }
        }
        return count;
    }

    static int simulation() {
        int hitter = 0;
        int outCount = 0;
        int ret = 0;

        for (int game = 0; game < score.length; game++) {
            outCount = 0;
            ru = new boolean[4];
            while (outCount < 3) {
                int s = score[game][order[hitter]];
                hitter = (hitter + 1) % 9;
                if (s == 0) {
                    outCount++;
                    continue;
                }
                ret += moveRu(s);
            }
        }

        return ret;
    }

    static void permutation(int idx) {
        if (idx == 9) {
            answer = Math.max(answer, simulation());
            return;
        }
        for (int i = 1; i < 9; i++) {
            if (!visited[i]) {
                visited[i] = true;
                order[idx] = i;
                if (idx + 1 == 3) {
                    permutation(idx + 2);
                } else {
                    permutation(idx + 1);
                }
                visited[i] = false;
            }
        }
    }

    public static void main(String args[]) throws Exception {
        int N = Integer.parseInt(in.readLine());

        score = new Integer[N][9];
        order[3] = 0;
        visited[0] = true;

        for (int i = 0; i < N; i++) {
            StringTokenizer st = new StringTokenizer(in.readLine());
            for (int j = 0; j < 9; j++) {
                score[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        permutation(0);
        out.write(answer + "");
        out.flush();
        out.close();
        in.close();
    }
}

import java.util.*;
import java.io.*;

class cine {
    static public void main(String[] args) throws Exception {
        var in = new BufferedReader(new InputStreamReader(System.in));
        var st = new StringTokenizer(in.readLine());

        int N = Integer.parseInt(st.nextToken());
        int M = Integer.parseInt(st.nextToken());
        int K = Integer.parseInt(st.nextToken());

        var seats = new int[N + 1][M + 1];
        var sums = new int[N + 1][M + 1];
        for (int y = 1; y <= N; ++y) {
            st = new StringTokenizer(in.readLine());
            for (int x = 1; x <= M; ++x) {
                seats[y][x] = Integer.parseInt(st.nextToken());
                sums[y][x] = (seats[y][x] == 0 ? 1 : 0) + sums[y-1][x] + sums[y][x-1] - sums[y-1][x-1];
            }
        }

        int min = Math.max(N, M);
        for (int y = 1; y <= N; ++y) {
            for (int x = 1; x <= M; ++x) {
                if (seats[y][x] == 1) {
                    continue;
                }
                int left = 1;
                int right = Math.max(N, M);
                while (left < right) {
                    int mid = left + (right - left)/2;

                    int x1 = Math.max(x-mid, 1), x2 = Math.min(x+mid, M);
                    int y1 = Math.max(y-mid, 1), y2 = Math.min(y+mid, N);

                    int count = sums[y2][x2] - sums[y2][x1-1] - sums[y1-1][x2] + sums[y1-1][x1-1];

                    if (count >= K + 1) {
                        right = mid;
                    } else {
                        left = mid + 1;
                    }
                }
                min = Math.min(left, min);
            }
        }
        System.out.println(min);
    }

}

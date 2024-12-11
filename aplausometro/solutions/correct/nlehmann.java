import java.util.*;
import java.io.*;

class aplausometro {
    static public void main(String[] args) throws Exception {
        var in = new BufferedReader(new InputStreamReader(System.in));

        int N = Integer.parseInt(in.readLine());

        var st = new StringTokenizer(in.readLine());

        var aplos = new int[N];
        for (int i = 0; i < N; ++i) {
            aplos[i] = Integer.parseInt(st.nextToken());
        }
        System.out.println(findRounds(aplos));
    }

    static int findRounds(int[] arr) {
        int n = arr.length;
        var stk = new Stack<Pair>();
        int maxRounds = 0;
        for (int i = 0; i < n; ++i) {
            int currentRound = 0;

            while (!stk.isEmpty() && stk.peek().first() <= arr[i]) {
                currentRound = Math.max(currentRound, stk.peek().second());
                stk.pop();
            }

            // Calculate the round for the current element
            if (!stk.isEmpty()) {
                currentRound++;
            }

            stk.push(new Pair(arr[i], currentRound));

            maxRounds = Math.max(maxRounds, currentRound);
        }

        return maxRounds + 1;
    }
}

record Pair(int first, int second) {}

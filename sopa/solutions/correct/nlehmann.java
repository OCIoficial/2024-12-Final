import java.io.*;
import java.util.*;

class burrito {
    static public void main(String[] args) throws Exception {
        var in = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(in.readLine());

        var rows = new String[n];
        for (int i = 0; i < n; ++i) {
            rows[i] = in.readLine();
        }

        int m = Integer.parseInt(in.readLine());

        for (int c = 0; c < m; ++c) {
            var s = in.readLine();

            boolean found = false;
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    boolean horizontal = true;
                    for (int k = 0; k < s.length(); ++k) {
                        if (rows[i].charAt((j + k) % n) != s.charAt(k)) {
                            horizontal = false;
                            break;
                        }
                    }

                    boolean vertical = true;
                    for (int k = 0; k < s.length(); ++k) {
                        if (i + k >= n || rows[i + k].charAt(j) != s.charAt(k)) {
                            vertical = false;
                            break;
                        }
                    }
                    found = found || horizontal || vertical;
                }
            }
            System.out.println(found ? "PRESENTE" : "AUSENTE");
        }
    }
}

#include "testlib.h"

static std::tuple<int, int, int> readHeader() {
    int n = inf.readInt(1, 1e6, "n");
    inf.readSpace();
    int m = inf.readInt(1, 1e6, "m");
    inf.readSpace();
    int k = inf.readInt();
    inf.readEoln();
    return {n, m, k};
}

static int readMatrix(int n, int m) {
    int C[n][m];
    int zeros = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            C[i][j] = inf.readInt(0, 1, "C_ij");
            if (j != m-1) {
                inf.readSpace();
            }
            if (C[i][j] == 0) {
                zeros++;
            }
        }
        inf.readEoln();
    }
    return zeros;
}

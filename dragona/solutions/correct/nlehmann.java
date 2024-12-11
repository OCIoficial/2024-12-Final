import java.util.*;
import java.io.*;

class dragona {
    static public void main(String[] args) throws Exception {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

        StringTokenizer st = new StringTokenizer(in.readLine());

        int n = Integer.parseInt(st.nextToken());
        int h = Integer.parseInt(st.nextToken());

        ArrayList<Integer>[] edges = new ArrayList[h+1];
        for (int i = 1; i <= h; ++i) {
            edges[i] = new ArrayList<>();
        }
        for (int i = 0; i < n; ++i) {
            st = new StringTokenizer(in.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            edges[a].add(b);
        }
        System.out.println(dijkstra(edges, h));
    }

    static int dijkstra(ArrayList<Integer>[] edges, int h) {
        var q = new PriorityQueue<Pair>();
        var dist = new int[h+1];
        Arrays.fill(dist, Integer.MAX_VALUE);
        q.add(new Pair(0, 1));
        while (!q.isEmpty()) {
            var pn = q.poll();
            int i = pn.snd();
            int d = pn.fst();
            if (d >= dist[i]) {
                continue;
            }
            dist[i] = d;

            if (i + 1 <= h) {
                q.add(new Pair(d + 1, i + 1));
            }
            for (var v : edges[i]) {
                q.add(new Pair(d, v));
            }
        }
        return dist[h];
    }
}

record Pair(int fst, int snd) implements Comparable<Pair> {
    @Override
    public int compareTo(Pair other) {
        return fst == other.fst ?  snd - other.snd : fst - other.fst ;
    }
}
// 3 1000000
// 98923 308453
// 780132 834105
// 547607 658585

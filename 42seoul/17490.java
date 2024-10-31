import java.util.*;
import java.io.*;

public class Main {

	static class Pair implements Comparable<Pair> {
		long d;
		int n;

		public Pair(long d, int n) {
			this.d = d;
			this.n = n;
		}

		@Override
		public int compareTo(Pair other) {
			return Long.compare(this.d, other.d);
		}

		@Override
		public boolean equals(Object o) {
			if (this == o) return true;
			if (o == null || getClass() != o.getClass()) return false;
			Pair p = (Pair)o;
			return n == p.n && d == p.d;
		}
	}

	public static int N, M;
	public static long K;
	public static boolean[] D = new boolean[1000002];

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		K = Long.parseLong(st.nextToken());

		ArrayList<Pair>[] V = (ArrayList<Pair>[]) new ArrayList[N + 2];
		for (int i = 1; i <= N + 1; i++)
			V[i] = new ArrayList<>();
		st = new StringTokenizer(br.readLine());
		for (int i = 1; i <= N; i++) {
			long t = Long.parseLong(st.nextToken());
			V[N + 1].add(new Pair(t, i));
			V[i].add(new Pair(t, N + 1));
			int prev = i - 1, next = i + 1;
			if (prev < 1) prev = N;
			if (next > N) next = 1;
			V[i].add(new Pair(0, prev));
			V[i].add(new Pair(0, next));
		}
		for (int i = 0; i < M; i++) {
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			V[a].remove(new Pair(0, b));
			V[b].remove(new Pair(0, a));
		}
		PriorityQueue<Pair> pq = new PriorityQueue<>();
		pq.add(new Pair(0, 1));
		long sum = 0;
		int cnt = 0;
		while (!pq.isEmpty()) {
			Pair p = pq.poll();
			if (!D[p.n]) {
				sum += p.d;
				D[p.n] = true;
				if (p.n != N + 1) {
					cnt++;
					if (cnt == N)
						break;
				}
			}
			for (Pair nP : V[p.n]) {
				if (!D[nP.n])
					pq.add(new Pair(nP.d, nP.n));
			}
		}
		if (sum <= K)
			System.out.println("YES");
		else
			System.out.println("NO");
	}
}
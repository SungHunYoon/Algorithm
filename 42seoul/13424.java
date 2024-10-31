import java.util.*;
import java.io.*;

public class Main {

	public static int T, N, M, A, B, C, K;
	public static int[][] V = new int[101][101];
	public static int[] F = new int[101];


	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		T = Integer.parseInt(st.nextToken());
		while (T-- != 0) {
			st = new StringTokenizer(br.readLine());
			N = Integer.parseInt(st.nextToken());
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= N; j++) {
					if (i == j) V[i][j] = 0;
					else V[i][j] = (int)1e9;
				}
			}
			M = Integer.parseInt(st.nextToken());
			for (int i = 0; i < M; i++) {
				st = new StringTokenizer(br.readLine());
				A = Integer.parseInt(st.nextToken());
				B = Integer.parseInt(st.nextToken());
				C = Integer.parseInt(st.nextToken());
				V[A][B] = C;
				V[B][A] = C;
			}
			st = new StringTokenizer(br.readLine());
			K = Integer.parseInt(st.nextToken());
			st = new StringTokenizer(br.readLine());
			for (int i = 0; i < K; i++)
				F[i] = Integer.parseInt(st.nextToken());
			for (int k = 1; k <= N; k++)
				for (int i = 1; i <= N; i++)
					for (int j = 1; j <= N; j++)
						V[i][j] = Math.min(V[i][j], V[i][k] + V[k][j]);
			long minValue = (int)1e9;
			int minIdx = 0;
			for (int i = 1; i <= N; i++) {
				long sum = 0;
				for (int j = 0; j < K; j++)
					sum += V[F[j]][i];
				if (sum < minValue) {
					minValue = sum;
					minIdx = i;
				}
			}
			System.out.println(minIdx);
		}
	}
}
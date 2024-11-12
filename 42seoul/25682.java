import java.util.*;
import java.io.*;

public class Main {

	public static int N, M, K;

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());

		N = Integer.parseInt(st.nextToken());
		M = Integer.parseInt(st.nextToken());
		K = Integer.parseInt(st.nextToken());

		char[][] A = new char[N + 1][M + 1];
		for (int i = 1; i <= N; i++) {
			st = new StringTokenizer(br.readLine());
			String S = st.nextToken();
			for (int j = 1; j <= M; j++) {
				A[i][j] = S.charAt(j - 1);
			}
		}
		char[][][] WB = new char [2][N + 1][M + 1];
		for (int i = 1; i <= N; i++) {
			char T1, T2;
			if (i % 2 == 0) {
				T1 = 'W';
				T2 = 'B';
			} else {
				T1 = 'B';
				T2 = 'W';
			}
			for (int j = 1; j <= M; j++) {
				WB[0][i][j] = T1;
				WB[1][i][j] = T2;
				if (T1 == 'W') T1 = 'B';
				else T1 = 'W';
				if (T2 == 'B') T2 = 'W';
				else T2 = 'B';
			}
		}
		int[][][] P = new int[2][N + 1][M + 1];
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= M; j++) {
				for (int k = 0; k < 2; k++) {
					P[k][i][j] = P[k][i - 1][j] + P[k][i][j - 1] - P[k][i - 1][j - 1];
					if (WB[k][i][j] != A[i][j])
						P[k][i][j]++;
				}
			}
		}
		int answer = (int)1e9;
		for (int i = 0; i <= N - K; i++) {
			for (int j = 0; j <= M - K; j++) {
				answer = Math.min(answer,
						Math.min(P[0][i + K][j + K] - P[0][i + K][j] - P[0][i][j + K] + P[0][i][j],
								P[1][i + K][j + K] - P[1][i + K][j] - P[1][i][j + K] + P[1][i][j]));
			}
		}
		System.out.println(answer);
	}
}
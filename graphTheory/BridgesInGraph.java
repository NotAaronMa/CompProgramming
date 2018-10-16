import java.io.*;
import java.util.*;

public class BridgesInGraph {
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

	public static void main(String[] args) throws NumberFormatException, IOException {
		for (int i1 = 0; i1 < 5; i1++) {
			int n = Integer.parseInt(in.readLine());
			int m = Integer.parseInt(in.readLine());
			int[][]a = new int[n][n];
			for (int i = 0; i < m; i++) {
				String[] tokens = in.readLine().split(" ");
				int s = Integer.parseInt(tokens[0]);
				int f = Integer.parseInt(tokens[1]);
				add(s-1,f-1,a);
			}
			int x = 0;
			for(int i = 0; i < a.length; i++) {
				for(int j = 0; j < a.length; j++) {
					if(a[i][j] == 1) {
						delete(i,j, a);
						boolean[]b = bfs(0,a);
						boolean flag = false;
						for(int k= 0; k < b.length; k++) {
							if(!b[i]) {
								flag = true;
							}
						}
						if(flag) {
							x++;
						}
						add(i,j,a);
					}
				}
			}
			System.out.println(x);
		}
	}
	public static void add(int s, int f, int[][]adj) {
		adj[s][f] = 1;
		adj[f][s] = 1;
	}
	public static void delete(int s, int f, int[][]adj) {
		adj[s][f] = 0;
		adj[f][s] = 0;
	}
	public static boolean[] bfs(int start, int[][]adj) {
		boolean[] visited = new boolean[adj.length];
		LinkedList<Integer> q = new LinkedList<Integer>();
		visited[start] = true;
		q.add(start);
		while (!q.isEmpty()) {
			int[] n = adj[q.pollFirst()];
			for (int i = 0; i < n.length; i++) {
				if(n[i] == 1) {
					if(!visited[i]) {
						visited[i] = true;
						q.add(i);
					}
				}
			}

		}
		return visited;

	}
}

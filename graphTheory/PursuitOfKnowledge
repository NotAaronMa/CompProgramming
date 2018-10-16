import java.io.*;
import java.util.*;

public class PursuitOfKnowledge {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		int n,m,t;
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String[]tokens = in.readLine().split(" ");
		n = Integer.parseInt(tokens[0]);
		m = Integer.parseInt(tokens[1]);
		t = Integer.parseInt(tokens[2]);
		ArrayList<Integer>[]adj = new ArrayList[n+1];
		for(int i = 0; i < adj.length; i++) {
			adj[i] = new ArrayList<Integer>();
		}
		for(int i = 0; i < m; i++) {
			tokens = in.readLine().split(" ");
			int a = Integer.parseInt(tokens[0]);
			int b = Integer.parseInt(tokens[1]);
			adj[a].add(b);
			//adj[b].add(a);
		}
		int q = Integer.parseInt(in.readLine());
		for(int i = 0; i < q;i++) {
			tokens = in.readLine().split(" ");
			int a = Integer.parseInt(tokens[0]);
			int b = Integer.parseInt(tokens[1]);
			bfs(adj,a,b,t);
		}
		
		
	}
	public static void bfs(ArrayList<Integer>[]adj, int start, int end,int t) {
		LinkedList<Integer>q = new LinkedList<Integer>();
		boolean[]visited = new boolean[adj.length];
		int[]dist = new int[adj.length];
		q.add(start);
		visited[start] = true;
		while(!q.isEmpty()) {
			int n = q.pollFirst();
			ArrayList<Integer> next = adj[n];
			for(int i = 0; i < next.size();i++) {
				int p = next.get(i);
				if(!visited[p]) {
					visited[p] = true;
					dist[p] = dist[n] + 1;
					q.add(p);
				}
			}
		}
		if(visited[end]) {
			System.out.println(dist[end]*t);
		}else {
			System.out.println("Not enough hallways!");
		}
		
	}

}

import java.io.*;
import java.util.*;
public class JaidenStudiesTrees {
	public static void main(String[]args) throws IOException {
	
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int n  = Integer.parseInt(in.readLine());
		ArrayList<Integer>[] adj = new ArrayList[n+1];
		for(int i = 0; i < adj.length; i++) {
			adj[i] = new ArrayList<Integer>();
		}
		for(int i = 0; i < n-1; i++) {
			String[] tokens = in.readLine().split(" ");
			int a = Integer.parseInt(tokens[0]);
			int b = Integer.parseInt(tokens[1]);
			adj[a].add(b);
			adj[b].add(a);
		}
		int[]dist = bfs(1,adj);
		int d1 = 0;
		int indexOfd1 = 0;
		for(int i = 0; i < dist.length; i++) {
			if(d1 < dist[i]) {
				indexOfd1 = i;
				d1 = dist[i];
			}
		}
		dist = bfs(indexOfd1,adj);
		for(int i = 0; i < dist.length; i++) {
			//System.out.println(dist[i]);
			d1 = Math.max(d1,dist[i]);
		}
		System.out.println(d1);
	}
	public static int[] bfs(int start, ArrayList<Integer>[]adj) {
		int[]dist = new int[adj.length];
		boolean[]visited = new boolean[adj.length];
		LinkedList<Integer>q = new LinkedList<Integer>();
		q.add(start);
		visited[start] = true;
		while(!q.isEmpty()) {
			int prev = q.pollFirst();
			for(int i = 0; i < adj[prev].size();i++) {
				int next = adj[prev].get(i);
				if(!visited[next]) {
					visited[next] = true;
					q.add(next);
					dist[next] = dist[prev]+1;
				}
			}
			
		}
		return dist;
		
		
		
		
	}
}

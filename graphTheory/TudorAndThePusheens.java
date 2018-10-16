package graphTheory;
import java.util.*;
import java.io.*;

public class TudorAndThePusheens {
	static ArrayList<Integer>[]servers;
	@SuppressWarnings("unchecked")
	public static void main(String[]args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String[]tokens = in.readLine().split(" ");
		int n,m;
		n = Integer.parseInt(tokens[0]);
		m = Integer.parseInt(tokens[1]);
		servers = new ArrayList[n+1];
		for(int i = 0; i < servers.length; i++) {
			servers[i] = new ArrayList<Integer>();
		}
		for(int i = 0 ; i< m; i++) {
			tokens = in.readLine().split(" ");
			int a,b;
			a = Integer.parseInt(tokens[0]);
			b = Integer.parseInt(tokens[1]);
			servers[a].add(b);
			servers[b].add(a);
		}
		tokens = in.readLine().split(" ");
		int s, e;
		s = Integer.parseInt(tokens[0]);
		e = Integer.parseInt(tokens[1]);
		System.out.println(m - bfs(servers,s,e));
	}
	public static int bfs(ArrayList<Integer>[]adj,int start, int end) {
		int[]dist = new int[adj.length];
		boolean[]visited = new boolean[adj.length];
		visited[start] = true;
		LinkedList<Integer>q = new LinkedList<Integer>();		
		q.addLast(start);
		while(!q.isEmpty()) {
			int next = q.pollFirst();
			ArrayList<Integer>children = adj[next];
			
			for(int i = 0; i < children.size(); i++) {
				int child = children.get(i);
				if(!visited[child]) {
					visited[child] = true;
					dist[child] = dist[next]+1;
					q.addLast(child);
				}
			}
		}
		return dist[end];
	}
}
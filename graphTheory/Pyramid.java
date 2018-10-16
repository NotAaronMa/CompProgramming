package graphTheory;
import java.io.*;
import java.util.*;
public class Pyramid {
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	public static void main(String[]args) throws NumberFormatException, IOException {
		int l = Integer.parseInt(in.readLine());
		for(int i = 0; i < l; i++) {
			testCase();
		}
	}
	public static void testCase() throws IOException, NumberFormatException {
		int n = Integer.parseInt(in.readLine());
		String[]names = new String[n];
		for(int i = 0; i < n; i++) {
			names[i] = in.readLine();
		}
		@SuppressWarnings("unchecked")
		ArrayList<Integer>[]adj = new ArrayList[n];
		for(int i = 0; i < n; i++) {
			adj[i] = new ArrayList<Integer>();
		}
		Hashtable<String,Integer> ht = new Hashtable<String,Integer>();
		for(int i = 0; i < adj.length; i++) {
			ht.put(names[i], i);
		}
		for(int i = 0; i < n; i+=2) {
			String s1 = names[i];
			String s2 = names[i+1];
			adj[ht.get(s1)].add(ht.get(s2));
			adj[ht.get(s2)].add(ht.get(s1));
			
		}
		int d1 = n*10;;
		int d2 = bfs(adj,n-1);
		d2*=20;
		System.out.println(d1-d2);
	}
	
	public static int bfs(ArrayList<Integer>[]adj,int st) {

		
		int[]dis = new int[adj.length];
		boolean[]vis = new boolean[adj.length];
		LinkedList<Integer>q = new LinkedList<Integer>();
		q.push(st);
		vis[st] = true;
		while(!q.isEmpty()) {
			int prev = q.pollFirst();
			ArrayList<Integer>n = adj[prev];
			for(int i = 0; i < n.size(); i++) {
				int nex = n.get(i);
				if(!vis[nex]) {
					dis[nex] = dis[prev]+1;
					q.push(nex);
					vis[nex] = true;
				}	
			}
		}
		int m = dis[0];
		for(int i = 1; i < dis.length; i++) {
			m = Math.max(m, dis[i]);
		}
		return m;
	}
}
package graphTheory;
import java.io.*;
import java.util.*;
public class PhonominalReviews {
	static int n,m;
	static boolean[]pho;
	static int[]pho2;
	static ArrayList<Integer>[]adj;
	@SuppressWarnings("unchecked")
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader in  = new BufferedReader(new InputStreamReader(System.in));
		String[]tokens = in.readLine().split(" ");
		n = Integer.parseInt(tokens[0]);
		m = Integer.parseInt(tokens[1]);
		tokens = in.readLine().split(" ");
		pho = new boolean[n];
		pho2 = new int[m];
		for(int i = 0; i < m; i++) {
			int n = Integer.parseInt(tokens[i]);
			pho[n] = true;
			pho2[i] = n;
		}
		adj = new ArrayList[n];
		for(int i = 0; i < adj.length; i++) {
			adj[i] = new ArrayList<Integer>();
		}
		for(int i = 0; i < n-1; i++) {
			tokens= in.readLine().split(" ");
			int a = Integer.parseInt(tokens[0]);
			int b = Integer.parseInt(tokens[1]);
			adj[a].add(b);
			adj[b].add(a);
		}
		LinkedList<Integer>st = new LinkedList<Integer>();
		st.push(pho2[0]);
		bfs1(st);
		System.out.println(diameter());
		
	}
	
	static boolean[]mark;
	public static void bfs1(LinkedList<Integer>q) {
		boolean[]v = new boolean[n];
		int[]prev = new int[n];
		prev[pho2[0]] = -1;
		v[pho2[0]] = true;
		while(!q.isEmpty()) {
			int n = q.pollFirst();
			ArrayList<Integer> nex = adj[n];
			for(int i = 0; i < nex.size(); i++) {
				int ve = nex.get(i);
				if(!v[ve]) {
					prev[ve] = n;
					v[ve] = true;
					q.push(ve);
				}
			}
		}
		mark = new boolean[n];
		for(int i = 1; i < m; i++) {
			int n = prev[pho2[i]];
			mark[n] = true;
			while(true) {
				n = prev[n];
				
				if(n == -1 || mark[n]) {
					break;
				}
				mark[n] = true;
				//System.out.println(n);
			}
		}
		for(int i = 0; i < m; i++) {
			int n = pho2[i];
			mark[n] = true;
		}
	}
	
	static int nodes = 0;
	public static int diameter() {
		int p = pho2[0];
		int diam = dbfs(p);
		for(int i = 0; i < n; i++) {
			if(mark[i]) {
				nodes++;
			}
		}
		return (nodes-1)*2 -diam;
	}
	public static int dbfs(int st){
		int[]d = new int[n];
		boolean[]v = new boolean[n];
		LinkedList<Integer>q = new LinkedList<Integer>();
		v[st] = true;
		q.add(st);
		int maxdist = 0;
		int vmd = 0;
		while(!q.isEmpty()) {
			int n = q.pollFirst();
			ArrayList<Integer> nex = adj[n];
			for(int i = 0; i < nex.size(); i++) {
				int ne = nex.get(i);
				if(!v[ne]) {
					q.add(ne);
					v[ne] = true;
					d[ne] = d[n]+1;
					if (d[ne] > maxdist && mark[ne]) {
						maxdist = d[ne];
						vmd = ne;
					}
				}
			}
		}
		return bfs(vmd);
	}
	public static int bfs(int st){
		int[]d = new int[n];
		boolean[]v = new boolean[n];
		LinkedList<Integer>q = new LinkedList<Integer>();
		v[st] = true;
		q.add(st);
		int maxdist = 0;
		int vmd = 0;
		while(!q.isEmpty()) {
			int n = q.pollFirst();
			ArrayList<Integer> nex = adj[n];
			for(int i = 0; i < nex.size(); i++) {
				int ne = nex.get(i);
				if(!v[ne]&& mark[ne]) {
					q.add(ne);
					v[ne] = true;
					d[ne] = d[n]+1;
					if (d[ne] > maxdist) {
						maxdist = d[ne];
						vmd = ne;
					}
				}
			}
		}
		return maxdist;
	}
}
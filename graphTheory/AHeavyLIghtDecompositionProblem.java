import java.io.*;
import java.util.*;
public class AHeavyLIghtDecompositionProblem {
	static int[]values ;
	static ArrayList<Integer>[]adj;
	public static void main(String[]args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String[]tokens = in.readLine().split(" ");
		int n,q;
		n = Integer.parseInt(tokens[0]);
		q = Integer.parseInt(tokens[1]);
		tokens = in.readLine().split(" ");
		values = new int[n+1];
		
		for(int i = 1; i < n+1; i++) {
			values[i] = Integer.parseInt(tokens[i-1]);
		} 
		adj = new ArrayList[n+1];
		for(int i = 0; i < adj.length; i++) {
			adj[i] = new ArrayList<Integer>();
		} 
		for(int i = 0; i < n-1; i++) {
			tokens = in.readLine().split(" ");
			int a,b;
			a = Integer.parseInt(tokens[0]);
			b = Integer.parseInt(tokens[1]);
			adj[a].add(b);
			adj[b].add(a);
		
		}
		
		for(int i = 0; i < q; i++) {
			int a,b,m;
			tokens = in.readLine().split(" ");
			m = Integer.parseInt(tokens[0]);
			a = Integer.parseInt(tokens[1]);
			b = Integer.parseInt(tokens[2]);
		
		
			int[]path = getPath(a,b);
		
			switch(m) {
			case 1:
				System.out.println(mean(path));
				break;
			case 2:
				System.out.println(median(path));
				break;
			case 3:
				//mode(path);
				System.out.println(mode(path));
				break;
				
			}
		}		
	}
	
	public static int mode(int[]a) {
		//printarr(a);
		int[]occ = new int[100001];
		for(int i = 0; i < a.length; i++) {
			occ[values[a[i]]]+=1;
		}
		int m = -1, im = -1;
		for(int i = 0; i < occ.length; i++) {
			if(m < occ[i]) {
				m = occ[i];
				im = i;
			}
		}
		return im;
	}
	
	public static int median(int[]a) {
		int[]value = new int[a.length];
		for(int i = 0; i < a.length; i++) {
			value[i] = values[a[i]];
		}
		//printarr(value);
		Arrays.sort(value);
		if(value.length %2 == 0) {
			if(value.length == 2) {
				return Math.round((value[0] + value[1])/2f);
			}
			return Math.round((value[value.length/2]+ value[value.length/2-1])/2f);
		}else {
			return value[value.length/2];
		}
		
	}
	public static int mean(int[]a) {
		double d = 0;
		for(int i = 0; i< a.length; i++) {
			d+= values[a[i]];
		}
		d/=a.length;
		return (int)Math.round(d);
	}
	
	public static int[]getPath(int start, int end){
		int[]prev,dist;
		boolean[]visited;
		dist = new int[adj.length]; prev = new int[adj.length];
		visited = new boolean[adj.length];
		LinkedList<Integer>q = new LinkedList<Integer>();
		q.addLast(start);
		visited[start] = true;
		
		while(!q.isEmpty()) {
			int n = q.pollFirst();
			ArrayList<Integer>children = adj[n];
			for(int i = 0; i < children.size(); i++) {
				int child  = children.get(i);
				if(!visited[child]) {
					visited[child] = true;
					dist[child] = dist[n]+1;
					prev[child] = n;
					q.addLast(child);
				}
			}
		}
		
		int[]path = new int[dist[end]+1];
		path[dist[end]] = end;
		for(int i = path.length-2; i >= 0; i--) {
			path[i] = prev[path[i+1]];
		}
		return path;
		
	}
	public static void printarr(int[]a) {
		for(int i = 0; i < a.length; i++) {
			System.out.print(a[i]);
			
		}
		System.out.println();
	}
}
package graphTheory;
import java.io.*;
import java.util.*;

public class Maze {
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	public static void main(String[] args) throws NumberFormatException, IOException {
		int a = Integer.parseInt(in.readLine());
		for(int i = 0; i < a; i++) {
			testcase();
		}
	}
	public static void testcase() throws NumberFormatException, IOException {
		int r = Integer.parseInt(in.readLine());
		int c = Integer.parseInt(in.readLine());
		char[][]map = new char[r][c];
		for(int i = 0; i < r; i++) {
			char[]n = in.readLine().toCharArray();
			map[i] = n;
		}
		int[][]dist = new int[r][c];
		boolean[][]visited = new boolean[r][c];
		LinkedList<Integer>rq = new LinkedList<Integer>();
		LinkedList<Integer>cq = new LinkedList<Integer>();
		rq.push(0);
		cq.push(0);
		visited[0][0] = true;
		while(!rq.isEmpty()) {
			int pr = rq.pollFirst();
			int pc = cq.pollFirst();
			boolean up = false,dwn = false,rgt = false,lft = false;
			switch(map[pr][pc]) {
				case'+': up = true;dwn = true;rgt = true;lft = true; break;
				case'-': rgt = true; lft = true; break;
				case'|': up = true; dwn = true; break;
			}
			int pd = dist[pr][pc];
			if(up) {
				bfshelp(map,pr-1,pc,visited,rq,cq,dist,pd);
			}
			if(dwn) {
				bfshelp(map,pr+1,pc,visited,rq,cq,dist,pd);
			}
			if(rgt) {
				bfshelp(map,pr,pc+1,visited,rq,cq,dist,pd);
			}
			if(lft) {
				bfshelp(map,pr,pc-1,visited,rq,cq,dist,pd);
			}
		
		}
		if(visited[r-1][c-1]) {
			System.out.println(dist[r-1][c-1]+1);
		}else {
			System.out.println(-1);
		}
		
		
	}
	public static void bfshelp(char[][]map, int r, int c, boolean[][]visited, LinkedList<Integer>rq, LinkedList<Integer>cq, int[][]dist, int pd) {
		if(r >= 0 && r< map.length && c>=0 && c<map[r].length) {
			if(map[r][c]!= '*'&&!visited[r][c]) {
				rq.addLast(r);
				cq.addLast(c);
				visited[r][c] = true;
				dist[r][c] = pd+1;
			}
		}
		
	}
}
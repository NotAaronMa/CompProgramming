package graphTheory;
import java.util.LinkedList;
import java.io.*;
public class AFK {
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	public static void main(String[]arg) throws IOException {
		int a = Integer.parseInt(in.readLine());
		for(int i = 0; i < a; i++) {
			testCase();
		}
	}
	public static void testCase() throws IOException {
		String[] tokens = in.readLine().split(" ");
		int l = Integer.parseInt(tokens[0]);
		int w = Integer.parseInt(tokens[1]);
		char[][]map = new char[w][l];
		int sx = 0;
		int sy = 0;
		boolean notfound = true;
		boolean wnotfound = true;
		for(int i = 0; i < w; i++) {
			char[]a = in.readLine().toCharArray();
			map[i] = a;
		}
		//System.out.println();
		for(int i = 0; i < map.length; i++) {
			for(int j = 0; j < map[0].length; j++) {
					//System.out.println();
					if(map[i][j] == 'C') {
						sx = i;
						sy = j;
						notfound = false;
					}
					if(map[i][j]== 'W') {
						wnotfound = false;
				}
				
			}
			//System.out.println();
		}
		if(notfound || wnotfound) {
			System.out.println("#notworth");
			System.exit(0);
		}
		//System.out.println(sx + " " + sy);
		
		bfs(map, sx,sy);
	
	}
	public static void bfs(char[/*x*/][/*y*/]map, int startx, int starty) {
		LinkedList <Integer> qx = new LinkedList<Integer>();
		LinkedList <Integer> qy = new LinkedList<Integer>();
		qx.add(startx);
		qy.add(starty);	
		boolean[][]visited = new boolean[map.length][map[0].length];
		int[][]dist =new int[map.length][map[0].length];
		visited[startx][starty] = true;
		while(!qx.isEmpty() && !qy.isEmpty()){
			int x = qx.pollFirst();
			int y = qy.pollFirst();
			if(dist[x][y] >= 60) {
				System.out.println("#notworth");
				return;
			}
			if(map[x][y] == 'W') {
				System.out.println(dist[x][y]);
				return;
			}
			bfsHelp(x,y,x, y+1, map,visited,dist,qx,qy);
			bfsHelp(x,y,x, y-1, map,visited,dist,qx,qy);
			bfsHelp(x,y,x+1, y, map,visited,dist,qx,qy);
			bfsHelp(x,y,x-1, y, map,visited,dist,qx,qy);
			
		}
		System.out.println("#notworth");
	}
	public static void bfsHelp(int prevx, int prevy, int x, int y, char[][]map, boolean[][]visited, int[][]dist, LinkedList<Integer> qx, LinkedList<Integer>qy) {
		if(inBounds(x,y,map)) {
			if(!visited[x][y] && map[x][y] != 'X') {
				qx.add(x);
				qy.add(y);
				visited[x][y] = true;
			}
			dist[x][y] = dist[prevx][prevy]+1;
		}
	}
	public static boolean inBounds(int x, int y, char[][]map) {
		return x < map.length && y < map[0].length && x >= 0 && y >= 0;
		
	}
}
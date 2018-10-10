import java.io.*;
import java.util.LinkedList;
public class CrossingFields {
	public static void main(String[]args) throws IOException{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String[] tokens = in.readLine().split(" ");
		int a = Integer.parseInt(tokens[0]);
		int b = Integer.parseInt(tokens[1]);
		int[][]map = new int[a][a];
		for(int i = 0; i < a; i++) {
			tokens = in.readLine().split(" ");
			for(int j = 0; j < a; j++) {
				map[i][j] = Integer.parseInt(tokens[j]);
			}
		}
		bfs(map,b);
	}
	public static void bfs(int[][]map, int q) {
		int sx = 0;
		int sy = 0;
		boolean[][]visited = new boolean[map.length][map.length];
		LinkedList<Integer> xq = new LinkedList<Integer>();
		LinkedList<Integer> yq = new LinkedList<Integer>();
		visited[sx][sy] = true;
		xq.add(sx);
		yq.add(sy);
		while(!xq.isEmpty()) {
			int x = xq.pollFirst();
			int y = yq.pollFirst();
			int nx = x + 1;
			int ny = y;
			if(inbounds(nx, ny,map)) {
				if(!visited[nx][ny]) {
				if(Math.abs(map[nx][ny] - map[x][y]) <= q) {
					xq.add(nx);
					yq.add(ny);
					visited[nx][ny] = true;
					if(nx == map.length-1 && ny == map.length -1) {
						System.out.println("yes");
						return;
					}
				}
				}
			}
			nx = x - 1;
			ny = y;
			if(inbounds(nx, ny,map)) {
				if(!visited[nx][ny]) {
				if(Math.abs(map[nx][ny] - map[x][y]) <= q) {
					xq.add(nx);
					yq.add(ny);
					visited[nx][ny] = true;
					if(nx == map.length-1 && ny == map.length -1) {
						System.out.println("yes");
						return;
					}
				}
				}
			}
			nx = x;
			ny = y + 1;
			if(inbounds(nx, ny,map)) {
				if(!visited[nx][ny]) {
				if(Math.abs(map[nx][ny] - map[x][y]) <= q) {
					xq.add(nx);
					yq.add(ny);
					visited[nx][ny] = true;
					if(nx == map.length-1 && ny == map.length -1) {
						System.out.println("yes");
						return;
					}
				}
				}
			}
			nx = x;
			ny = y-1;
			if(inbounds(nx, ny,map)) {
				if(!visited[nx][ny]) {
				if(Math.abs(map[nx][ny] - map[x][y]) <= q) {
					xq.add(nx);
					yq.add(ny);
					visited[nx][ny] = true;
					if(nx == map.length-1 && ny == map.length -1) {
						System.out.println("yes");
						return;
					}
				}
				}
			}
			
		}
		System.out.println("no");
		
	}
	public static boolean inbounds(int x, int y, int[][] map) {
		return x < map.length && y < map.length && y >= 0 && x >= 0;
	}
	
}
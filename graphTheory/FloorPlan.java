package graphTheory;
import java.io.*;
import java.util.*;
public class FloorPlan {
	static char[][] floor;
	public static void main(String[] args) throws NumberFormatException, IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int flooring = Integer.parseInt(in.readLine());
		int r = Integer.parseInt(in.readLine());
		int c = Integer.parseInt(in.readLine());
		floor = new char[r][c];
		for(int i = 0; i < r ; i++) {
			floor[i] = in.readLine().toCharArray();
		}
		ArrayList<Integer> rooms = new ArrayList<Integer>();
		for(int i = 0; i < r; i++) {
			for(int j = 0; j < c; j++) {
				if(floor[i][j] == '.') {
					rooms.add(bfs(i,j));
				}
			}
		}
		Collections.sort(rooms);
		int floored = 0;
		for(int i = rooms.size()-1; i >= 0; i--) {
			if(flooring >= rooms.get(i)) {
				flooring -= rooms.get(i);
				floored++;
			}else {
				break;
			}
		}
		System.out.printf("%d %s, %d square metre(s) left over", floored, floored == 1 ? "room": "rooms", flooring);
		
	}
	
	public static int bfs(int sr, int sc) {
		LinkedList<Integer>rq = new LinkedList<Integer>();
		LinkedList<Integer>cq = new LinkedList<Integer>();
		rq.push(sr);
		cq.push(sc);
		int rs = 0;
		while(!rq.isEmpty()) {
			int r = rq.pollFirst();
			int c = cq.pollFirst();
			
			
			int nr;
			int nc;
			nr = r+1;
			nc = c;
			if(inBounds(nr,nc)) {
				if(floor[nr][nc] != 'I') {
					rs++;
					rq.push(nr);
					cq.push(nc);
					floor[nr][nc] = 'I';
				}
			}
			nr = r-1;
			nc = c;
			if(inBounds(nr,nc)) {
				if(floor[nr][nc] != 'I') {
					rs++;
					rq.push(nr);
					cq.push(nc);
					floor[nr][nc] = 'I';
				}
			}
			nr = r;
			nc = c+1;
			if(inBounds(nr,nc)) {
				if(floor[nr][nc] != 'I') {
					rs++;
					rq.push(nr);
					cq.push(nc);
					floor[nr][nc] = 'I';
				}
			}
			nr = r;
			nc = c-1;
			if(inBounds(nr,nc)) {
				if(floor[nr][nc] != 'I') {
					rs++;
					rq.push(nr);
					cq.push(nc);
					floor[nr][nc] = 'I';
				}
			}
		
			
		}
		return rs;
	}
	public static boolean inBounds(int a, int b) {
		return (a < floor.length && b < floor[0].length && a >= 0 && b >= 0);
		
	}
	
}
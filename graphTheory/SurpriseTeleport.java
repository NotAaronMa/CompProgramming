import java.io.*;
import java.util.*;
public class SurpriseTeleport {

    static boolean[][]visited;
    public static void main(String[] args) throws IOException {
        // TODO Auto-generated method stub
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String[]tokens = in.readLine().split(" ");
        int r,c;
        r = Integer.parseInt(tokens[0]);
        c = Integer.parseInt(tokens[1]);
        tokens = in.readLine().split(" ");
        mpoint sp = new mpoint(Integer.parseInt(tokens[0]), Integer.parseInt(tokens[1]));
        tokens = in.readLine().split(" ");
        mpoint ep = new mpoint(Integer.parseInt(tokens[0]), Integer.parseInt(tokens[1]));
        char[][]map = new char[r][c];
        for(int i = 0; i < r; i++) {
            map[i] = in.readLine().toCharArray();
        }
        int[][]dist = bfs(sp,map);
        int d1 = dist[ep.r][ep.c];
        //System.out.println(d1);
        int tps = Integer.parseInt(in.readLine());
        int cm = d1;
        for(int i = 0; i < tps; i++) {

            tokens = in.readLine().split(" ");
            int a = Integer.parseInt(tokens[0]);
            int b = Integer.parseInt(tokens[1]);
            if(visited[a][b]) {
                cm = Math.min(cm, dist[a][b]);
            }
        }
        System.out.println(d1-cm);

    }
    public static int[][] bfs(mpoint sp, char[][]map) {
        LinkedList<mpoint>q = new LinkedList<mpoint>();
        visited = new boolean[map.length][map[0].length];
        int[][]dist = new int[map.length][map[0].length];
        q.add(sp);
        visited[sp.r][sp.c] = true;
        while(!q.isEmpty()) {
            mpoint prev = q.pollFirst();
            int pd = dist[prev.r][prev.c];
            bfshelp(map,visited,prev.r+1, prev.c, q,dist,pd);
            bfshelp(map,visited,prev.r-1, prev.c, q,dist,pd);
            bfshelp(map,visited,prev.r, prev.c+1, q,dist,pd);
            bfshelp(map,visited,prev.r, prev.c-1, q,dist,pd);
        }
        return dist;

    }
    public static void bfshelp(char[][]map, boolean[][]visited, int r,int c, LinkedList<mpoint>q, int[][]dist, int prevDist) {
        if(r >= 0 && r < map.length  &&c >= 0 && c < map[0].length) {
            if(map[r][c]!= 'X' && !visited[r][c]) {
                q.add(new mpoint(r,c));
                dist[r][c] =  prevDist+1;
                visited[r][c] = true;
            }
        }

    }

}
class mpoint{
    int r,c;
    public mpoint(int a, int b) {
        r = a;
        c = b;
    }
}
import java.util.ArrayList;
import java.util.LinkedList;
import java.io.*;
public class DealingWithKnots {
    public static boolean hasPath(ArrayList<Integer>[] adj, int start, int target) {
        LinkedList<Integer> q = new LinkedList<Integer>();
        q.add(start);
        boolean[] visited = new boolean[adj.length];
        visited[start] = true;
        while (!q.isEmpty()) {
            ArrayList<Integer> next = adj[q.pollFirst()];
            for (int i = 0; i < next.size(); i++) {
                int n = next.get(i);
                //System.out.println(n);
                if (n == target)
                    return true;
                if (!visited[n]) {
                    visited[n] = true;
                    q.add(n);
                }
            }

        }
        return false;

    }
    public static void main(String[]args) throws NumberFormatException, IOException{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(in.readLine());
        ArrayList<Integer> []adj = new ArrayList[n+1];
        for(int i = 0; i < n+1; i++) {
            adj[i] = new ArrayList<Integer>();
        }
        for(int i = 0; i < n; i++) {

            String[]tokens = in.readLine().split(" ");
            int a = Integer.parseInt(tokens[0]);
            int b = Integer.parseInt(tokens[1]);
            adj[a].add(b);
        }
        String[] tokens = in.readLine().split(" ");
        System.out.println(hasPath(adj,Integer.parseInt(tokens[0]), Integer.parseInt(tokens[1]))? "Tangled":"Not Tangled");



    }
}
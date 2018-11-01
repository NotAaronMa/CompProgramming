import java.io.*;
import java.util.*;
public class ANoisyClass {
    static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    public static void main(String[] args) throws NumberFormatException, IOException {
        // TODO Auto-generated method stub
        int n = Integer.parseInt(in.readLine())+1;
        int m = Integer.parseInt(in.readLine());
        int[]indegrees = new int[n];
        ArrayList<Integer>[]adj = new ArrayList[n];
        for(int i = 0; i < n; i++) {
            adj[i] = new ArrayList<Integer>();
        }
        for(int i = 0; i < m; i++) {
            String[]tokens = in.readLine().split(" ");
            int a = Integer.parseInt(tokens[0]);
            int b = Integer.parseInt(tokens[1]);
            adj[a].add(b);
            indegrees[b] ++;
        }
        System.out.println(topsort(adj,indegrees)? "Y":"N");
    }
    public static boolean topsort(ArrayList<Integer>[]adj, int []indegrees) {
        LinkedList<Integer> q = new LinkedList<Integer>();
        boolean[]removed = new boolean[adj.length];
        for(int i = 1; i < adj.length;i++) {
            if(indegrees[i] == 0) {
                q.addFirst(i);
                removed[i] = true;
            }
        }
        while(!q.isEmpty()) {
            int next = q.pollFirst();
            for(int i = 0; i < adj[next].size(); i++) {
                int n = adj[next].get(i);
                if(--indegrees[n] == 0) {
                    q.addFirst(n);
                    removed[n] = true;
                }
            }
        }
        for(int i = 1; i < adj.length; i++) {
            if(removed[i] == false) {
                return false;
            }
        }
        return true;

    }

}
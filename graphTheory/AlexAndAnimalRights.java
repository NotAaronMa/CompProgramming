import java.io.*;
public class AlexAndAnimalRights {

    static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    public static void main(String[] args) throws IOException {
        // TODO Auto-generated method stub
        String[]tokens = in.readLine().split(" ");
        int R = Integer.parseInt(tokens[0]);
        int C = Integer.parseInt(tokens[1]);
        char[][]a = new char[R][C];
        for(int i = 0; i < R;i++) {
            a[i] = in.readLine().toCharArray();
        }
        int c = 0;
        for(int i = 0; i < R; i++) {
            for(int j = 0; j < C; j++) {
                if(a[i][j] == 'M') {
                    dfs(i,j,a);
                    c++;
                }
            }
        }
        System.out.println(c);
    }

    public static int dfs(int r, int c, char[][]map) {
        int c1  = 0;
        if(!(map[r][c] == '#')) {
            c1++;
            map[r][c] = '#';
            c1 += dfs(r,c+1,map);
            c1 +=dfs(r,c-1,map);
            c1 += dfs(r+1,c,map);
            c1 += dfs(r-1,c,map);
        }
        return c1;
    }
}
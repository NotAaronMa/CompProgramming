import java.io.*;
public class RoundingToFibonacci {
    static long[]fibs = new long[50];
    static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    public static void main(String[]args) throws NumberFormatException, IOException {
        fibs[1] = 1;
        fibs[2] = 1;
        for(int i = 2; i < fibs.length; i++) {
            fibs[i] = fibs[i-1] + fibs[i-2];
        }
        //System.out.println(fibs[49]);
        for(int i = 0; i < 5; i++) {
            long n = Long.parseLong(in.readLine());
            long mindif = Math.abs(n - fibs[0]);
            long indexOfmindif = 0;
            for(int j = 1; j < 49; j++) {
                long next = Math.abs(n - fibs[j]);
                if(next <= mindif) {
                    indexOfmindif++;
                    mindif = next;
                }

            }
            System.out.println(fibs[(int) indexOfmindif]);
        }

    }
}
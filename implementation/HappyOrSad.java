import java.io.*;
public class HappyOrSad {
    static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    public static int occurencesOf(String s1, String substring){
        int c =0;
        for(int i = 0; i < s1.length() - substring.length();i++){
            String s = s1.substring(i, i+ substring.length());
            //System.out.println(s);
            if(s.equals(substring)){
                c++;

            }
        }
        //System.out.println(c);
        return c;
    }
    public static void main(String[] args) throws IOException {
        // TODO Auto-generated method stub
        String s = in.readLine();
        int c = 0;
        int c1 = 0;
        c+= occurencesOf(s, ":-)");
        c1 += occurencesOf(s,":-(");
        //System.out.println(c1 + " " + c);
        if(c1 == 0 && c == 0 )
            System.out.println("none");
        else if(c1 == c)
            System.out.println("unsure");
        if(c > c1)
            System.out.println("happy");
        if(c < c1)
            System.out.println("sad");

    }

}
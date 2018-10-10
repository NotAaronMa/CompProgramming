import java.io.*;
import java.util.*;
public class MIMIANDPRIMES {
	  public static long gcd(long p, long q) {
	        if (q == 0) return p;
	        else return gcd(q, p % q);
	  }
	  public static void seive(boolean[]n) {
			n[2] = false;
			for(int i = 2; i < n.length; i++) {
				if(!n[i]) {
					for(int j = i+i; j+i < n.length; j+=i) {
						n[j] = true;
					}
				}
			}
			for(int i = 0; i < n.length; i++) {
				n[i] = !n[i];
			}
		}
	  public static ArrayList<Long> Primefactors(long gcd){
			//	System.out.println("Primefactors is called");
				ArrayList<Long> Primefactors = new ArrayList<Long>();
				long i = 2;
				for(i = 2; i <= (int)Math.sqrt(gcd); i++){
					if(gcd % i == 0){
						gcd = gcd/i;
						Primefactors.add(i);
						i--;
					}
				}
				Primefactors.add(gcd);
				return Primefactors;
				 
			}
	  public static void main(String[]args) throws IOException {
		  BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		  int n = Integer.parseInt(in.readLine());
		  String si = in.readLine();
		  //System.out.println(si);
		  String[]tokens = si.split(" ");
		  
		  long gcd = Long.parseLong(tokens[0]);
		  for(int i = 1; i < n; i++) {
			  gcd = gcd(gcd,Long.parseLong(tokens[i]));
		  }
		  if(gcd == 1) {
			  System.out.println("DNE");
			  return;
		  }
		  
		  ArrayList<Long>a = Primefactors(gcd);
		  long max = -1;
		  for(int i = 0; i < a.size(); i++) {
			  long nex = a.get(i);
			  max = Math.max(max, nex);
		  }
		  if(max != 1) {
			  System.out.println(max);
			  return;
		  }else {
			  System.out.println("DNE");
		  }
		  
		  
	  }
}

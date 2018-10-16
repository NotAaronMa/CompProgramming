package graphTheory;
import java.io.*;
public class Buka {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		
		int n = in.readLine().length()-1;
		String s = in.readLine();
		int n1 = in.readLine().length()-1;
		
		if(s.equals("*")){
			System.out.print(1);
			for(int i = 0; i < n1 + n; i++) {
				System.out.print(0);
			}
			return;
		}else {
			
			int max = Math.max(n, n1);
			int min = Math.min(n,n1);
			if(max == min) {
				System.out.print(2);
				for(int i = 0; i < n; i++) {
					System.out.print(0);
				}
			}else {
				System.out.print(1);
				for(int i = 0; i < max-min-1; i++) {
					System.out.print(0);
				}
				System.out.print(1);
				for(int i = 0; i < min; i++) {
					System.out.print(0);
				}
			}
		}
	}

}

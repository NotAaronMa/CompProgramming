import java.io.*;
public class NailedIt {
	@SuppressWarnings("unused")
	public static void main(String[]args) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(in.readLine());
		String[]tokens = in.readLine().split(" ");
		int[]boards = new int[2001];
		for(int i = 0; i < tokens.length; i++) {
			boards[Integer.parseInt(tokens[i])]++;
		}
		
		
		
		
		int[]perms = new int[4008];
		for(int i = 0; i < boards.length; i++) {
			if(boards[i] != 0){
				for(int j = i; j < boards.length; j++) {
					if(i == j) {
						perms[i + j] += boards[i]/2;
		
					}else if(boards[j] != 0) {
						perms[i+j] += Math.min(boards[i],boards[j]);
					}
				}
				
			}
		}
		int max = 0,numways= 0;
		for(int i = 0; i < perms.length; i++) {
			if(perms[i] > max) {
				max = perms[i];
				numways = 1;
			}else if(perms[i] == max) {
				numways++;
			}
		}
		System.out.println(max + " " + numways);
	}
	
}

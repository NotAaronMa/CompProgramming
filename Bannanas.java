import java.io.*;
public class Bannanas {

	public static boolean IsAWord(char[]c) {
		if(c.length == 0) {
			return false;
		}
		if(c.length == 1) {
			return(c[0] == 'A');
		} 
		if(c[0] == 'B' && c[c.length -1] == 'S' && IsAWord(c.toString().substring(1,c.length -1).toCharArray())) {
			return true;
		}
		return false;
	}
	public static boolean IsMonkeyWord(char[]c) {
		if(IsAWord(c))
			return true;
		for(int i = 0; i < c.length; i++) {
			if(c[i] == 'N') {
				if(IsAWord(new String(c).substring(0,i).toCharArray()) && IsAWord(new String(c).substring(i+1).toCharArray())) {
					return true;
				}
			}
		}
		return false;
	}

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		while(true) {
			String s = in.readLine();
			if(s.equals("X")) {
				break;
			}
			System.out.println(IsMonkeyWord(s.toCharArray())? "Yes": "No");
			
		}
	}

}
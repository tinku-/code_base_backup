import java.io.*;
class charin{
	public static void main(String args[]) throws IOException{
		char c;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		System.out.println("press q to exit");
		do{
			c = (char)br.read();
			System.out.println(c);
		}while(c != 'q');
	}
}

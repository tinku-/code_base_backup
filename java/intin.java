import java.io.*;
class intin{
	public static void main(String args[]) throws IOException{
		String c;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		System.out.println("press q to exit");
		do{
			c = br.readLine();
			System.out.println(c);
		}while(!c.equals("stop"));
	}
}

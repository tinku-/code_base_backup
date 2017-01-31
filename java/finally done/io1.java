import java.io.*;
class IODemo1
{
	public static void main(String args[])
	{
		try
		{
			BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
			System.out.println("ready to take ibnput from keyboard");
			System.out.println("Eneter stop to exit");
			String str;
			str=br.readLine();
			while( !(str.equals("stop")) )
			{
				System.out.println("you entered "+str);
				str=br.readLine();
			}
		}
		catch(IOException ie)
		{
			System.out.println("caught");
		}
	}
}

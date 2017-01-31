import java.util.*;
class STDemo
{
	public static void main(String args[])
	{
		String str = "Hello:world:how:are:you:doing";
		StringTokenizer st = new StringTokenizer(str,":");
		int tcount = st.countTokens();
		System.out.println("number of token generated "+ tcount);
		while(st.hasMoreTokens())
		{
			String s = st.nextToken();
			System.out.println(s);
		}
	}
}
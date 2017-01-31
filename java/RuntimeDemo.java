import java.util.*;
class RuntimeDemo
{
	public static void main(String args[])
	{
		Runtime r = Runtime.getRuntime();
		Process p = null;
		try
		{
			p = r.exec("google-chrome");
		}

		catch(Exception e){}
		System.out.println("hgj");
	}
}
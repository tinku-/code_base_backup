import java.util.*;
class date
{
	public static void main(String args[])
	{
		long time=System.currentTimeMillis();
		Date d = new Date(time);
		System.out.println("current date is "+ d);
		System.out.println("millisecs="+ time);
	}
}
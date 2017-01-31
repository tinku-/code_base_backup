import java.util.*;
class HTDemo11
{
	public static void main(String args[])
	{
		Hashtable<String,Integer> ht= new Hashtable<String,Integer>();
		ht.put("one",new Integer(100));
		ht.put("two",new Integer(200));
		ht.put("three",new Integer(300));
		
		Integer i = ht.get("two");
		int x = i.intValue();
		System.out.println("value of two is"+x);
		
		Enumeration<String> en = ht.keys();
		while(en.hasMoreElements())
		{
			String s = en.nextElement();
			System.out.println("integer value of key"+s +"is"+ht.get(s));
		}
	}
}
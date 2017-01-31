import java.util.*;

class ALDemo2
{
	public static void main(String args[])
	{
		ArrayList<Line> al = new ArrayList<Line>();
		
		System.out.println(" aray siz eis" + al.size());
		
		al.add(new Line(100));
		al.add(new Line(200));
		al.add(new Line(300));
		
		System.out.println("size now" + al.size());
		System.out.println("content" + al);
	
		Iterator<Line> lit = al.iterator();
		int i=0;
		while( lit.hasNext())
		{
			Line l = lit.next();
			System.out.println(" print the iter" + i + "of list" + l);
			i++;
		}
		Collections.reverse(al);
		System.out.println(" print the iter" + i + "of list" + al);
	}
}
class Line
{ 
	int length;
 	Line( int l)
	{
		length = l;
	}
	public String toString()
	{
		return "Line length is " + length;
	}
}

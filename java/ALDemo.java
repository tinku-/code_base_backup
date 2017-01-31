import java.util.*;
class ALDemo
{
	public static void main(String args[])
	{
		ArrayList<Line> al = new ArrayList<Line>();
		System.out.println("aray size is " + al.size());
		
		al.add(new Line(100));
		al.add(new Line(200));
		al.add(new Line(300));
		
		System.out.println("size now " + al.size());
		System.out.println("content :" + al);
	
		al.remove(1);

		System.out.println("size now "  + al.size());
		System.out.println("content :" + al);
	} 
}
class Line
{ 
	int length;
 	Line( int l)
	{
		length = l;
	}
	/*public String toString()
	{
		return "" + length;
	}*/
}
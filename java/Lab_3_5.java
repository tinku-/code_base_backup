class Line 
{
	int length ;
	Line(int l)
	{
		length = l;
	}
	public String toString() //here we are overriding the predefined method 
	{
		String s = "the length is " + length;
		return s;
	}	
}
class Lab_3_5{
	public static void main(String args[])
	{
		Line l1 = new Line(20);
		System.out.println("printing object... ");
		System.out.println(l1);
	}
}
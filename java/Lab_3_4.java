
class Line 
{
	int length;
	Line(int l)
	{
		length = l;
	}
	public boolean equals(Object obj)
	{
		Line l3 = (Line)obj;
		if(this.length == l3.length)
			return true;
		return false;
	}
}
class Lab_3_4{
	public static void main(String args[])
	{
		Line l1 = new Line(10);
		Line l2 = new Line(10);
		//l1 = l2; only this line will give the "equal" result;
		if(l1.length == l2.length)
			System.out.println("equal");
		else
			System.out.println("nope"); // will print this ;

		//this will clear out some doubts;
		if(l1.equals(l2))
			System.out.println("2equal");
		else
			System.out.println("2nope");
	}
}

// == locater check for the location not the content of the refernce

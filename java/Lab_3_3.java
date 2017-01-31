class Shape{
	void test()
	{
		System.out.println("in shape test method");
	}
	void print()
	{
		System.out.println("in shapes print method");
	}
}
class Rect extends Shape{
	void print()
	{
		//super.print();
		System.out.println("in rect print method");
	}
	void temp()
	{
		System.out.println("in rect temp method");
	}
}
class Lab_3_3{
	public static void main(String args[])
	{
		Shape s = new Shape();
		Rect r = new Rect();
		Shape s1;
		if(args[0].equals("cool"))
		{
			//System.out.println("kdsf");
			s1 = s;
			s1.test();
		}
		else
		{
			s1 = r;
			s1.print();
		}
	}
}
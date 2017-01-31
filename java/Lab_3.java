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
		System.out.println("in rect print method");
	}
	void temp()
	{
		System.out.println("in rect temp method");
	}
}
class Lab_3{
	public static void main(String args[])
	{
		Shape s = new Shape();
		Rect r = new Rect();
		//s.test();
		//s.print();
		r.print();
		//r.temp();

		//sr.test();
	}
}
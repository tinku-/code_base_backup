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
class Lab_3_2{
	public static void main(String args[])
	{
		Shape s = new Rect(); //super class reference pointng to sub class object 
		Rect r = new Rect();
		//s.test();
		//s.print();
		s.print(); //this type of reference can invoke inherited methods 
		s.test(); //and invoke superclass methods 
		//r.temp();
		//s.temp(); //this will give error
		//r.test();
	}
}
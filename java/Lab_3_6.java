class Line{
	void test(){
		System.out.println("inside test of Line");
	}
	final void temp()  //cannnot ocerridde final //final can be added at beg of class to make it leaf of the heirarchy;
	{
		System.out.println("inside temp of Line");
	}
}
class NewLine extends Line{
	void test(){
		System.out.println("inside test of NewLine");
	}
	void temp(){
		System.out.println("inside temp of NewLine");
	}
}
class Lab_3_6{
	public static void main(String args[])
	{
		Line l1 = new Line();
		NewLine l2 = new NewLine();
		l1.test();
		l1.temp();
		l2.temp();
		l2.test();
	}
}

//will give error 
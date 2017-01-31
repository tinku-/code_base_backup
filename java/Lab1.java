class Line
{
	int length = 10;
	String color = "static";

	void printProperties()
	{
		System.out.println("length is " + length);
		System.out.println("color is " + color);

	}		
}
class MyClass
	{
		public void meth()
		{
			System.out.println("cryatal meth");			
		}
	}
class Lab1{	
	public static void main(String args[])
	{
		int k=1;
		int arr[][] = new int[2][3];
		int z = 4;
		z = z<<1;
		System.out.println(z);
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<3;j++)
			{
				arr[i][j] = k;
				k++;
				System.out.print(arr[i][j] + " ");
			}
			System.out.println(); 
		}


		for(int i=0;i<args.length;i++)
		{
			System.out.println(args[i]);
		}

		MyClass mc = new MyClass();
		mc.meth();
		
		

		Line l1,l2;
		l1 = new Line();
		l2 = new Line();
		l1.length = 100;
		l2.length = 200;
		l1.printProperties();
		l2.printProperties();
		l1.color = "red";
		l2.color = "blue";
		l1.printProperties();
		l2.printProperties();

	}
}	
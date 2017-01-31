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
	}
}	
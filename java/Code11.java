 class Code11{
 	public static int factorial(int x){
	 if(x == 0 || x == 1)
 		return 1;
 	else
 		return x*factorial(x-1);
 	}
	public static void main(String arg[])
	{
		int n = 3;
		int arr[][] = new int[n][n];
		for(int i = 0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				arr[i][j] = i+j;
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				System.out.print(arr[i][j] + " ");
			}
			System.out.println();
		}
		System.out.println(factorial(5));
	}
}
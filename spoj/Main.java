import java.util.*;
import java.lang.*;
 
class Main
{
	public static void main (String[] args) throws java.lang.Exception
	{
		Scanner sc=new Scanner(System.in);
		int T=sc.nextInt();
		for(int i=0;i<T;i++)
		{
			int a=sc.nextInt()%10;
			int b=sc.nextInt();
			int c=b%4;
			if(b==0)
			System.out.println(1);
			else if(c==0)
			System.out.println((int)(Math.pow(a,4)%10));
			else
			System.out.println((int)(Math.pow(a,c)%10));		}
	}
} 
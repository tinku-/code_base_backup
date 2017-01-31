import java.io.*;
class IODemo6
{
	public static void main(String args[]) throws Exception
	{
		File f=new File("Desktop/tewst.dir");
		if(f.isFile())
			System.out.println(f.getName()+" is a file");
		else
		{
			System.out.println(f.getName()+" is a directory");
		}
		System.out.println("parent of "+ f.getName()+ " is "+ f.getParent());
		System.out.println("free space in "+ f.getName() + " is " + f.getFreeSpace());
	}

}
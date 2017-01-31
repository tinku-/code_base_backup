import java.io.*;
class IODemo5
{
	public static void main(String args[]) throws IOException
	{
		FileInputStream fis;
		FileOutputStream fos;
		int i;
		System.out.println("Starting copy opened");

		try
		{
			fis=new FileInputStream("sample.txt");
			fos=new FileOutputStream(args[0]);
			do
			{
				i=fis.read();
				if(i!=-1)
				{
					fos.write(i);
				}
			}while(i!=-1);
			System.out.println("Done copying");
			fis.close();
		}
		catch(FileNotFoundException e)
		{
			System.out.println("Problem reported");
		}
	}
}
		
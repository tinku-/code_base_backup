import java.io.*;
class IODemo7
{
	public static void main(String args[]) throws Exception
	{
		String files[];
		File f= new File("home/ridam/rid.dir/dir2.txt");
		files=f.list();
		for(int i=0;i<files.length;i++)
		{
			File ff= new File(files[i]);
			if(ff.isFile())
				System.out.println(ff.getName()+" is a file ! ");
			else
				System.out.println(ff.getName()+ " is a directory");
		}
	}
}
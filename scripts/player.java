import java.io.*;
class player
{
	public static void main(String args[])throws Exception 
	{
		/*try{
			for(int i=5;i>0;i--)
			{
				System.out.println("main thread ' " + i);
				Thread.sleep(1000);
			}
		}catch(InterruptedException e){
			System.out.println("error caught in main");
		}System.out.println("exiting main thread"); */
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		System.out.println("print no of iterations ,min to play,min to pause");
		int x = Integer.parseInt(br.readLine());
		int y = Integer.parseInt(br.readLine());
		y = y*60;
		int z = Integer.parseInt(br.readLine());
		z = z*60;
		new NewThread("algoridam player",x,y,z);

	}
}
class NewThread implements Runnable
{
	Thread t;
	String s;
	int a,b,c;
	NewThread(String name,int x,int y,int z)
	{
		s = name;
		t = new Thread(this,s);
		a = x;
		b = y;
		c = z;
		System.out.println("one thread" + t);
		t.start();
	}
	public void run()
	{
		try{
			for(int i=a;i>0;i--)
			{
				System.out.println("thread ' "+ s +" " + i);
				Runtime r = Runtime.getRuntime();
				Process p = null;
				try
				{
					p = r.exec("./you.sh");
					//p = r.exec("rhythmbox-client --play");
					System.out.println("playing");
				}
				catch(Exception e1){}
				t.sleep(b);
				try
				{
					p = r.exec("./you.sh");
					//p = r.exec("rhythmbox-client --pause");
					System.out.println("paused");
				}
				catch(Exception e1){}
				t.sleep(c);
			}
		}catch(InterruptedException e){
			System.out.println("error caught");
		}System.out.println("exiting child thread");
	}
}
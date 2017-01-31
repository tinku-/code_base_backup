class Thread1
{
	public static void main(String args[])
	{
		new NewThread("one");
		try{
			for(int i=5;i>0;i--)
			{
				System.out.println("main thread ' " + i);
				Thread.sleep(1000);
			}
		}catch(InterruptedException e){
			System.out.println("error caught in main");
		}System.out.println("exiting main thread");
	}
}
class NewThread implements Runnable
{
	Thread t;
	String s;
	NewThread(String name)
	{
		s = name;
		t = new Thread(this,s);
		System.out.println("one thread" + t);
		t.start();
	}
	public void run()
	{
		try{
			for(int i=5;i>0;i--)
			{
				System.out.println("thread ' "+ s +" " + i);
				t.sleep(500);
			}
		}catch(InterruptedException e){
			System.out.println("error caught");
		}System.out.println("exiting child thread");
	}
}
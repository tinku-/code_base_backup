class Callme
{
	synchronized void call(String msg)
	{
		System.out.print("["+msg);
		try
		{
			Thread.sleep(1000);
		}
		catch(InterruptedException e)
		{
			System.out.println("yo");
		}
		System.out.println("]");
	}
}
class NewThread extends Thread
{
	String p;
	Callme tar;
	Thread t;
	public NewThread(Callme ti,String k)
	{
		tar = ti;
		p = k;
		t = new Thread(this);
		t.start();
	}
	public void run()
	{
		tar.call(p);
	}
}
class Thread2
{
	public static void main(String args[])
	{
		Callme target = new Callme();
		NewThread ob1 = new NewThread(target,"one");
		NewThread ob2 = new NewThread(target,"two");
		NewThread ob3 = new NewThread(target,"three");
		try
		{
			Thread.sleep(4000);
		}
		catch (InterruptedException ie)
		{
			System.out.println("Handled");
		}

	}
}
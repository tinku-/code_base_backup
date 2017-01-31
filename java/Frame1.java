import java.awt.*;
import java.awt.event.*;
class Frame1 extends Frame
{
	Frame1(String s)
	{
		super(s);
		addWindowListener(new wl());
	}
	
	public static void main(String args[])
	{
		Frame f =new Frame1("cool");
		f.setSize(400,500);
		f.setVisible(true);
	}
	class wl extends WindowAdapter
	{
		public void windowClosing(WindowEvent e)
		{
			System.out.println("Window is closing");
			System.exit(0);
		}
	}
}
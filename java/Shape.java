import java.awt.*;
import java.awt.event.*;
class Shape extends Frame
{
	Font f;
	Shape()
	{		
		f=new Font("Arial",Font.BOLD+Font.ITALIC,20);
		setBackground(Color.yellow);
		addWindowListener(new wl());
	}
	public void paint(Graphics g)
	{
		g.setColor(Color.green);
		g.drawLine(80,80,150,150);
		g.drawRect(120,220,50,100);
		g.setColor(Color.blue);
		g.setFont(f);
		g.drawString("Hello world",10,180);
	}
	public static void main(String args[])
	{
		Frame f=new Shape();
		f.setSize(400,600);
		f.setVisible(true);
	}
	class wl extends WindowAdapter{
	public void windowClosing(WindowEvent e){
		System.out.println("Window Closing");
		System.exit(0);
		}
	}
}


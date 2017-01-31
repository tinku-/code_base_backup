import java.awt.*;
import java.applet.*;
/*
<applet code = "SampleApplet.class" width= 500 height= 600>
</applet>
*/
public class SampleApplet extends Applet
{
	public void paint(Graphics g)
	{
		g.drawString("welcome to this Applet", 10,200); //x,y initial pixil from left top
		showStatus("HAGO");//status bar 
	}
}
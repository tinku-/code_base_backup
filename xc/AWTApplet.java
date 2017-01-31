import java.awt.*;
import java.applet.*;
import java.awt.event.*;

public class AWTApplet extends Applet  implements ActionListener 
{
  TextField t1;
  TextField t2,t3;
  Button b1,b2;
  Label l1,l2,l3;
 
  public AWTApplet()
  {
    setLayout(new BorderLayout());
    Panel p1 = new Panel();
    Panel p2 = new Panel();
    p1.setLayout(new FlowLayout());
    p2.setLayout(new FlowLayout());
 
    t1 = new TextField(20);
    t2 = new TextField(20);
    t3 = new TextField(20);
    
    l1 = new Label("Value1");
    l2 = new Label("Value 2");
    l3 = new Label("Sum");
    
    b1 = new Button("add");
    b2 = new Button ("clear");
    
    b1.addActionListener(this);
    b2.addActionListener(this);
    
    p1.add(t1);p1.add(l1);
    p1.add(t2);p1.add(l2);
    p1.add(t3);p1.add(l3);
    add("Center",p1);
 
    p2.add(b1); p2.add(b2);
    add("South",p2);
  }
  
  public void actionPerformed(ActionEvent e)
  {
  	if(e.getSource()==b1)
  	{ 
      int a = Integer.parseInt(t1.getText());
  	  int b = Integer.parseInt(t2.getText());
  	  int c = a+b;
  	  t3.setText(Integer.toString(c));
  	}
    if(e.getSource()==b2)
    {
      t1.setText("");
      t2.setText("");
      t3.setText("");
    }
  }
  
  }
  /* <html>
	<head>
	<title> BPHC </title>
	</head>
	
<applet code = "AWTApplet" width= 500 height= 600>
</applet>
</body>
</html>
 */
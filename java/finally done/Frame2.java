import java.awt.*;
import java.awt.event.*;
class Frame2 extends Frame implements ActionListener
{
	TextField t1,t2;
	Button b1;
	Button b2;
	Label l1;
	Frame2()
	{
		super("hello");
		setLayout(new BorderLayout());
		Panel p=new Panel();
		Panel p1=new Panel();
		p.setLayout(new FlowLayout());
		p1.setLayout(new FlowLayout());
		t1=new TextField(20);
		t2=new TextField(20);
		l1=new Label("Enter Text");
		b1=new Button("Send");
		b2=new Button("Clear");
		b1.addActionListener(this);
		b2.addActionListener(this);
		p.add(l1);p.add(t1);p.add(t2);
		add("Center",p);
		p1.add(b1);p1.add(b2);
		add("South",p1);
		
		addWindowListener(new wl());	
	}
	public void actionPerformed(ActionEvent e)
	{
		if(e.getSource()==b1)
		{
			t2.setText(t1.getText());
			t1.setText("");
		}
		if(e.getSource()==b2)
		{
			t2.setText("");
			t1.setText("");
		}
	}
	public static void main(String args[])	
	{
		Frame f=new Frame2();
		f.setSize(300,200);
		f.setVisible(true);
	}
	class wl extends WindowAdapter
	{
		public void windowClosing(WindowEvent e)
		{
			System.out.println("Window Closing");
			System.exit(0);
		}
	}
}
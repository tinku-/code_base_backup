import java.awt.*;
import java.awt.event.*;
class one
{
	public static void main(String arg[])
	{
		Frame1 f = new Frame1("calc");
		f.setSize(500,100);
		f.setVisible(true);
	}
}
class Frame1 extends Frame implements ActionListener 
{
	TextField t1,t2,t3;
	Label l1,l2,l3;
	Button b1,b2,b3,b4,b5;
	Frame1(String s)
	{
		super(s);
		setLayout(new BorderLayout());
		Panel p1 = new Panel();
		Panel p2 = new Panel();
		p1.setLayout(new FlowLayout());
		p2.setLayout(new FlowLayout());

		t1 = new TextField(10);
		t2 = new TextField(10);
		t3 = new TextField(10);

		l1 = new Label("a");
		l2 = new Label("b");
		l3 = new Label("a operation b :");

		b1 = new Button("add");
		b2 = new Button("sub");
		b3 = new Button("mul");
		b4 = new Button("div");
		b5 = new Button("clc");

		b1.addActionListener(this);
		b2.addActionListener(this);
		b3.addActionListener(this);
		b4.addActionListener(this);
		b5.addActionListener(this);

		p1.add(l1);p1.add(t1);
		p1.add(l2);p1.add(t2);
		p1.add(l3);p1.add(t3);

		add("Center",p1);

		p2.add(b1);
		p2.add(b2);
		p2.add(b3);
		p2.add(b4);
		p2.add(b5);

		add("South",p2);
		addWindowListener(new Wl());
	}
	public void actionPerformed(ActionEvent e)
	{
		if(e.getSource() == b1)
		{
			int a = Integer.parseInt(t1.getText());
			int b = Integer.parseInt(t2.getText());
			int c = a+b;
			t3.setText(Integer.toString(c));
		}
		if(e.getSource() == b2)
		{
			int a = Integer.parseInt(t1.getText());
			int b = Integer.parseInt(t2.getText());
			int c = a-b;
			t3.setText(Integer.toString(c));
		}
		if(e.getSource() == b3)
		{
			int a = Integer.parseInt(t1.getText());
			int b = Integer.parseInt(t2.getText());
			int c = a*b;
			t3.setText(Integer.toString(c));
		}
		if(e.getSource() == b4)
		{
			int a = Integer.parseInt(t1.getText());
			int b = Integer.parseInt(t2.getText());
			int c = a/b;
			t3.setText(Integer.toString(c));
		}
		if(e.getSource() == b5)
		{
			t1.setText("");
			t2.setText("");
			t3.setText("");
		}
	}
	class Wl extends WindowAdapter
	{
		public void windowClosing(WindowEvent e)
		{
			System.exit(0);
		}
	}
}
import java.awt.*;
import java.awt.event.*;
class trial
{
	public static void main(String args[])
	{
		MyFrame1 of1=new MyFrame1("f1");
		of1.setSize(600,100);
		of1.setVisible(true);
		MyFrame2 of2=new MyFrame2("f2");
		of2.setSize(600,100);
		of2.setVisible(true);

		of1.getobjm(of2);
		of2.getobjn(of1);
	}

}
class MyFrame1 extends Frame implements ActionListener
{
	TextField t1;
	Button b1;
	Label l1;
	MyFrame2 m;
	void getobjm(MyFrame2 x)
	{
		m = x;
	}
	MyFrame1(String yes)
	{
		super(yes);
		setLayout(new BorderLayout());
		Panel p=new Panel();
		p.setLayout(new FlowLayout());
		t1=new TextField(20);
		l1=new Label("name");
		b1=new Button("send");
		b1.addActionListener(this);
		p.add(l1);p.add(t1);p.add(b1);
		add("Center",p);
		addWindowListener(new wl());	
	}
	public void actionPerformed(ActionEvent e)
	{
		if(e.getSource()==b1)
		{
			m.t.setText(t1.getText());
			t1.setText("");
		}
	}
	class wl extends WindowAdapter
	{
		public void windowClosing(WindowEvent e)
		{
			System.out.println("closing 1");
			System.exit(0);
		}
	}
}
class MyFrame2 extends Frame implements ActionListener{
	TextField t;
	Label l;
	Button b2;
	MyFrame1 n ;
	void getobjn(MyFrame1 y)
	{
		n = y;
	}
	MyFrame2(String yes)
	{
		super(yes);
		setLayout(new BorderLayout());
		Panel p=new Panel();
		p.setLayout(new FlowLayout());
		b2=new Button("send back");
		t=new TextField(20);
		l=new Label("name");
		b2.addActionListener(this);
		p.add(l);p.add(t);p.add(b2);
		add("Center",p);	
		addWindowListener(new wl());	

	}
	public void actionPerformed(ActionEvent e)
	{
		if(e.getSource()==b2)
		{
			n.t1.setText(t.getText());
			t.setText("");
		}
	}
	class wl extends WindowAdapter
	{
		public void windowClosing(WindowEvent e)
		{
			System.out.println("closing 2");
			System.exit(0);
		}
	}
}
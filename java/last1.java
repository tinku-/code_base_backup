import java.awt.*;
import java.awt.event.*;
class last1 extends Frame implements ActionListener
{
	TextField t1,t2,t3;
	Button b1;
	Button b2;
	Button b3;
	Label l1,l2,l3;
	last1(String yes)
	{
		super(yes);

		setLayout(new BorderLayout());
		Panel p=new Panel();
		Panel p1=new Panel();
		p.setLayout(new FlowLayout());
		p1.setLayout(new FlowLayout());
		
		t1=new TextField(20);
		t2=new TextField(20);
		t3=new TextField(20);
		
		l1=new Label("Value 1");
		l2=new Label("value 2");
		l3=new Label("Total");
		
		b1=new Button("Add");
		b2=new Button("Clear");
		b3=new Button("chrome");
		
		b1.addActionListener(this);
		b2.addActionListener(this);
		b3.addActionListener(this);

		p.add(l1);p.add(t1);p.add(l2);p.add(t2);p.add(l3);p.add(t3);
		add("Center",p);
		p1.add(b1);p1.add(b2);p1.add(b3);
		add("South",p1);
		
		addWindowListener(new wl());	
	}
	last1(int i,String yes)
	{
		super(yes);

		setLayout(new BorderLayout());
		Panel p=new Panel();
		Panel p1=new Panel();
		p.setLayout(new FlowLayout());
		p1.setLayout(new FlowLayout());
		
		t1=new TextField(20);
		t2=new TextField(20);
		t3=new TextField(20);
		
		l1=new Label("fadfa1");
		l2=new Label("vdfag");
		l3=new Label("good");
		
		b1=new Button("Add");
		b2=new Button("anothr");
		b3=new Button("chrome");
		
		b1.addActionListener(this);
		b2.addActionListener(this);
		b3.addActionListener(this);

		p.add(l1);p.add(t1);p.add(l2);p.add(t2);p.add(l3);p.add(t3);
		add("Center",p);
		p1.add(b1);p1.add(b2);p1.add(b3);
		add("South",p1);
		
		addWindowListener(new wl());	
	}
	public void actionPerformed(ActionEvent e)
	{
		if(e.getSource()==b1)
		{
			int a,b,c;
			a=Integer.parseInt(t1.getText());
			b=Integer.parseInt(t2.getText());  
			c=a+b;
			t3.setText(Integer.toString(c));
		}
		if(e.getSource()==b2)
		{
			t2.setText("");
			t1.setText("");
			t3.setText("");
			Frame f2 = new last1(1,"subtractor");
			f2.setSize(600,100);
			f2.setVisible(true);
		}
		if(e.getSource()==b3)
		{
			Runtime r = Runtime.getRuntime();
			Process p = null;
			try
			{
				p = r.exec("xbacklight -set 4");
			}
			catch(Exception e1){}
			System.out.println("hogaya");
		}
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

class pop
{
	public static void main(String args[]){
		Frame f=new last1("Adder");
		f.setSize(600,100);
		f.setVisible(true);
	}
}
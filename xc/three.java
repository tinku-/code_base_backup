import java.awt.*;
import java.awt.event.*;
class MyFrame extends Frame implements ActionListener
{
	TextField t1,t2,t3;
	Button b1;
	Button b2;
	Label l1,l2,l3;
	MyFrame(String yes)
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
		b1.addActionListener(this);
		b2.addActionListener(this);
		p.add(l1);p.add(t1);p.add(l2);p.add(t2);p.add(l3);p.add(t3);
		add("Center",p);
		p1.add(b1);p1.add(b2);
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
		 if(e.getSource()==b2){
		t2.setText("");
		t1.setText("");
		t3.setText("");
		}
	}
	public static void main(String args[]){
		Frame f=new MyFrame("Adder");
		f.setSize(600,100);
		f.setVisible(true);
	}
	class wl extends WindowAdapter{
	public void windowClosing(WindowEvent e){
		System.out.println("Window Closing");
		System.exit(0);
		}
	}
}

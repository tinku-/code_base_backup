//implementation using extends
import java.awt.*;
class Cousin extends Thread{
	public void run(){
		for(int i=0;i<10;i++){
		try{
			java.lang.Thread.sleep(2000);
			System.out.println((i+1)+"tock..");
		}catch(InterruptedException e){
			System.out.println("pooof");
		}}
	}
}
//implementation using runnable 
class Cousin2 implements Runnable{
	public void run(){
		for(int i=0;i<10;i++){
		try{
			java.lang.Thread.sleep(3000);
			System.out.println((i)+" tick..");
		}catch(InterruptedException e){
			System.out.println("pooof");
		}}		
	}
}
class CreatingThread{
	public static void main(String args[]){
		Cousin c1 = new Cousin();

		Cousin2 c2 = new Cousin2();
		Thread t = new Thread(c2);

		//c1.start();
		//t.start();
		Frame frame = new Frame();
		frame.setTitle("SimpleFrame Title");
		frame.setSize(350,100);
		frame.setVisible(true);

		//like two clocks running simeltaniously.
	}
}

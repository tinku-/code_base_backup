class CurrentThread{
	public static void main(String args[]){
		//throws InterruptedException {
		Thread t=Thread.currentThread();
		System.out.println("name the current thread:"+t.getName());
		try{
 		   Thread.sleep(1500);
 		}catch(InterruptedException e){
 		System.out.println("got interrupted!");
 		}
		System.out.println("wait for it...");
		try{
 		   Thread.sleep(3000);
 		}catch(InterruptedException e){
 		System.out.println("got interrupted!");
 		}
		System.out.println("wait for it ....");
		
		//	}
		for(int i=1;i<=20;i++){
			try{
				t.sleep(10000/i/i);
				System.out.println("Tick."+(20-i));
			}catch(InterruptedException e){
 		System.out.println("got interrupted!");
 		}
		}
		try{
 		   Thread.sleep(50);
 		}catch(InterruptedException e){
 		System.out.println("got interrupted!");
 		}
		System.out.println("KaaBoom");
	}
}
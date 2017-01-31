class prog2 {
	public static void main(String ags[]){
		System.out.println("yeppie kai-yay motherfucker");
		Box box1 = new Box();
		box1.width=100;
		box1.height=100;
		box1.depth=100;	
		double vol;
		vol=box1.height*box1.width*box1.depth;
		System.out.println("volume:"+vol);
	}
}
class Box {
	double width;
	double height;
	double depth;
}


import javax.swing.*;
import java.awt.*;
class CustomFrame extends JFrame {
CustomFrame(JPanel panel){
setTitle("Border Layout");
setSize(350,
100);
setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
add(panel);
setVisible(true);
}
}
class BorderLayoutPanel extends JPanel {
public BorderLayoutPanel() {
setLayout(new BorderLayout());

add(new JButton("This is across the top."), BorderLayout.NORTH);
add(new JLabel("The footer message might go here."), BorderLayout.SOUTH);
add(new JButton("Right"), BorderLayout.EAST);
add(new JButton("Left"),BorderLayout.WEST);
String msg = "Thereasonable man adapts " + "himself to the world;\n"
+"the unreasonable one persists in "
+"trying to adapt the world to himself.\n"
+"Therefore all progress depends "
+"on the unreasonable man.\n\n"
+"     - George Bernard Shaw\n\n";
add(new JTextArea(msg),BorderLayout.CENTER);
}
}
public class BorderLayoutDemo {
public static void main(String[] args) {
JPanel panel = new BorderLayoutPanel();
new CustomFrame(panel);
}
}

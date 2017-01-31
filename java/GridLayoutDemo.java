import javax.swing.*;
import java.awt.*;
class CustomFrame extends JFrame {
CustomFrame(JPanel panel){
setTitle("Grid Layout");
setSize(350,
100);
setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
add(panel);
setVisible(true);
}
}
class GridLayoutPanel extends JPanel {
static final int n = 4;
public GridLayoutPanel() {
setLayout(new GridLayout(n, n));
for (int i = 0; i < n; i++) {
for (int j = 0; j < n; j++) {
int k = i * n + j;
if (k > 0)
add(new JButton("" + k));
}
}
}
}
public class GridLayoutDemo {
public static void main(String[] args) {
JPanel panel = new GridLayoutPanel();
new CustomFrame(panel);
}
}
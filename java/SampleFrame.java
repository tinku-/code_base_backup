import java.awt.*;
import java.awt.event.*;
public class SampleFrame {
static TextField tfNum = null;
static Label lblResult = null;
public static void main(String[] args) {
Frame frame = new Frame();
frame.setTitle("SampleFrame Title");
frame.setSize(350,
100);
frame.setVisible(true);
FrameTerminator f = new FrameTerminator();
frame.addWindowListener(f);
Panel panel = new Panel();
Label lblUsrInput = new Label("Enter a number:");
panel.add(lblUsrInput);
tfNum = new TextField("", 10);
panel.add(tfNum);
Button btnCal = new Button("Enter");
btnCal.addActionListener((new SampleFrame()).new BtnHandler());
panel.add(btnCal);
lblResult = new Label();
panel.add(lblResult);
frame.add(panel);
}
class BtnHandler implements ActionListener {
public void actionPerformed(ActionEvent event) {
int n = 0;
String num = tfNum.getText();
n = Integer.parseInt(num);
lblResult.setText("Square of the number: " + (n*n));
}
}
}
class FrameTerminator extends WindowAdapter {
public void windowClosing(WindowEvent event) {
System.exit(0);
}
}
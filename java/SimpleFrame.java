import javax.swing.*;import java.awt.event.*;
class CustomFrame extends JFrame {
CustomFrame(){
setTitle("SimpleFrame Title");
setSize(350,
100);
setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
}
}
class CustomPanel extends JPanel {
JCheckBox sqrCheckBox = null;
JLabel lblResult = null;
CustomPanel() {
sqrCheckBox = new JCheckBox("Square");
lblResult = new JLabel();
sqrCheckBox.addItemListener(new ItemHandler());
add(sqrCheckBox);
add(lblResult);
}
class ItemHandler implements ItemListener {
public void itemStateChanged(ItemEvent event) {
JCheckBox cb = (JCheckBox)event.getItem();
if(cb.isSelected())
lblResult.setText("Square Checkbox is selected");
else
lblResult.setText("Square Checkbox is deselected");
}
}
}
class SimpleFrame {
public static void main(String[] args) {
JFrame frame = new CustomFrame();
JPanel panel = new CustomPanel();
frame.add(panel);
frame.setVisible(true);
}
}
import java.awt.*;
import java.awt.event.*;

public class RegistrationForm extends Frame implements ActionListener {
    private TextField firstName, lastName, email;
    private TextField password;
    private Button submitBtn, cancelBtn;
    private Label message;

    public RegistrationForm(){
        setTitle("Registration Form");
        setSize(600,300);
        setLayout(new GridLayout(6,2));

        add(new Label("First Name:"));
        firstName = new TextField();
        add(firstName);

        add(new Label("Last Name:"));
        lastName = new TextField();
        add(lastName);

        add(new Label("Email:"));
        email = new TextField();
        add(email);

        add(new Label("Password:"));
        password = new TextField();
        password.setEchoChar('*');
        add(password);

        submitBtn = new Button("Submit");
        submitBtn.addActionListener(this);
        add(submitBtn);

        cancelBtn = new Button("Cancel");
        cancelBtn.addActionListener(this);
        add(cancelBtn);

        message = new Label("");
        add(message);

        addWindowListener(new WindowAdapter(){
            public void windowClosing(WindowEvent we){
                dispose();
            }
        });

        setVisible(true);
    }

    public void actionPerformed(ActionEvent e){
        if(e.getSource() == submitBtn){
            String fName = firstName.getText();
            String lName = lastName.getText();
            String Email = email.getText();
            String pass = password.getText();
            message.setText("Registration Successful");          
        } else if(e.getSource() == cancelBtn){
            message.setText("Registration Cancelled"); 
        }
    }

    public static void main(String args[]){
        new RegistrationForm();
    }

} 


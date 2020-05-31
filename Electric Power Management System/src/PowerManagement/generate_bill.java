/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package PowerManagement;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.sql.*;
/**
 *
 * @author BELIEVER
 */
public class generate_bill extends JFrame implements ActionListener{
     JLabel l1;
    JTextArea t1;
    JButton b1;
    Choice c1,c2;
    JPanel p1;
    generate_bill(){
        setSize(500,650);
        setLayout(new BorderLayout());
        
        p1 = new JPanel();
        
        l1 = new JLabel("Generate Bill");
        
        c1 = new Choice();
        c2 = new Choice();
        
        c1.add("1001");
        c1.add("1002");
        c1.add("1003");
        c1.add("1004");
        c1.add("1005");
        c1.add("1006");
        c1.add("1007");
        c1.add("1008");
        c1.add("1009");
        c1.add("1010");
        
        
        c2.add("January");
        c2.add("February");
        c2.add("March");
        c2.add("April");
        c2.add("May");
        c2.add("June");
        c2.add("July");
        c2.add("August");
        c2.add("September");
        c2.add("October");
        c2.add("November");
        c2.add("December");

        
        t1 = new JTextArea(50,15);
        JScrollPane jsp = new JScrollPane(t1);
        t1.setFont(new Font("Senserif",Font.ITALIC,18));
        
        b1 = new JButton("Generate Bill");
        
        p1.add(l1);
        p1.add(c1);
        p1.add(c2);
        add(p1,"North");
        
        add(jsp,"Center");
        add(b1,"South");
        
        b1.addActionListener(this);
        
        setLocation(350,40);
    }
    public void actionPerformed(ActionEvent ae){
        try{
            connect c = new connect();
   
            String month = c2.getSelectedItem();
            t1.setText("\t    POWER DEVELOPMENT DEPARTMENT\n    ELECTRICITY BILL ");
            
            ResultSet rs = c.s.executeQuery("select * from emp where meter_number="+c1.getSelectedItem());
            
            if(rs.next()){
                t1.append("\n    Customer Name   -->  "+rs.getString("name"));
                t1.append("\n    Meter Number     -->  "+rs.getString("meter_number"));
                t1.append("\n    Address                -->  "+rs.getString("address"));
                t1.append("\n    State                     -->  "+rs.getString("state"));
                t1.append("\n    City                       -->  "+rs.getString("city"));
                t1.append("\n    Email                     -->  "+rs.getString("email"));
                t1.append("\n    Month                    --> "+month);
                
                t1.append("\n    Phone Number       --> "+rs.getString("phone"));
                t1.append("\n-------------------------------------------------------------");
                t1.append("\n");
            }

    
            rs = c.s.executeQuery("select * from bill where meter_number="+c1.getSelectedItem());
            
            if(rs.next()){
                t1.append("\n    Current Month :\t"+rs.getString("month"));
                t1.append("\n    Units Consumed:\t"+rs.getString("units"));
                t1.append("\n    Total Charges :\t"+rs.getString("amount"));
                t1.append("\n---------------------------------------------------------------");
                t1.append("\n    TOTAL PAYABLE :\t"+rs.getString("amount"));
            }
            
            
            
            
            
            
        }catch(Exception e){
            e.printStackTrace();
        }
    }
    
    public static void main(String[] args){
        new generate_bill().setVisible(true);
    }
}


    


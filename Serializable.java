import java.io.*;
class Myclass implements Serializable
{
    private String name;
    private int rollId;
    private transient String password;
    
    Myclass(String name,int id,String password)
    {
        this.name=name;
        this.rollId=id;
        this.password=password;
    }
    Myclass()
    {
        
    }
    
    String getName()
    {
        return this.name;
    }
    int getRoll()
    {
        return this.rollId;
    }
    String getPassword()
    {
        return this.password;
    }
    
}

public class Main{
    
    public static void main(String args[])
    {
        Myclass m=new Myclass("Shubham",36,"Pass@123");
        
        //serialization 
        try {
            FileOutputStream fout=new FileOutputStream("Student.txt");
            ObjectOutputStream oout=new ObjectOutputStream(fout);
            oout.writeObject(m);
            fout.close();
            oout.close();
        } catch(Exception e) {
            System.out.print("Exception Occured during serialization");
        }
        
        
        //Deserialization
        
        try {
            FileInputStream fin=new FileInputStream("Student.txt");
            ObjectInputStream oin=new ObjectInputStream(fin);
            
            Myclass m1=(Myclass)oin.readObject();
            fin.close();
            oin.close();
            System.out.println(m1.getName());
            System.out.println(m1.getRoll());
            System.out.print(m1.getPassword());
            
        } catch(Exception e) {
             System.out.print("Exception Occured in deserialization");
        }
        
        
        
    }
}
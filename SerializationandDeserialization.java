/*
Serielization and Deserialization

Serialization is the process of converting object into byte stream for the purpose of sending over the network or store in the file
 we can implement serializable interface from java.io package for Serialization
 If don't want a variable to convert into byte stream we can make it as transient
 
 Use FileOutputstream and ObjecctOutputstream for the conversion
 
Deserialization is opposite process of that of Serialization
Use FileInputStream and ObjectInputStream
*/
import java.io.Serializable;
import java.io.FileOutputStream;
import java.io.FileInputStream;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
class Student implements Serializable{
    private String name;
    private int age;
    private transient int sid;
    
    public Student(String name,int age,int sid)
    {
        this.name=name;
        this.age=age;
        this.sid=sid;
    }
    public String getName()
    {
        return this.name;
    }
    public int getAge()
    {
        return this.age;
        
    }
    public int getId()
    {
        return this.sid;
    }
    
}
public class Main
{
	public static void main(String[] args) {
	    //Serialize
		try(FileOutputStream fout=new FileOutputStream("Student.txt");
		    ObjectOutputStream oout=new ObjectOutputStream(fout))
		{
		    Student s=new Student("Harish",22,37);
		    oout.writeObject(s);
		    System.out.print("Student Serialized");
		    
		}catch(Exception e)
		{
		    System.out.print(e.getMessage());
		}
		
		
		//Deserialize
		
		try(FileInputStream fin=new FileInputStream("Student.txt");
		    ObjectInputStream oin=new ObjectInputStream(fin)) {
		        
		        Student s=(Student) oin.readObject();
		        System.out.println();
		        System.out.println("Name "+ s.getName());
		        System.out.println("Age "+s.getAge());
		        System.out.println("Id "+ s.getId());
		    
		} catch(Exception e) {
		    e.printStackTrace();
		}
	}
}

/*
Closeable: It's an interface used to  close resource object when the are no longer needed.
It has Close method. Which has to be implemented by the implementing class for closing resources
AutoCloneable interface is similar to closeable but it used to automatically close the resouce object.
It is used in try with resource block, close method is automatically called when try blaock ends.
*/
class MyResource implements AutoCloseable{

    public void dosomething()
    {
        System.out.print("Do Something-> 10:34:Library:2/9/2023:ABS Gone");
    }
    @Override
    public void close() throws Exception{
        System.out.print("Message");
    }
}
public class Main{
    
    public static void main (String[] args) {
        
    try(MyResource m=new MyResource()) {
        m.dosomething();
    } catch(Exception e) {
    }
    }
}

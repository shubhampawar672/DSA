/*
Synchronization in java
*/

public class Main
{
    private int count=0;
    
    synchronized void increment()
    {
        count++;
    }
    int getCount()
    {
        return count;
    }
	public static void main(String[] args) {
		Main m=new Main();
		
		Thread t1=new Thread(()->{
		   for(int i=0;i<1000;i++)
		   {
		       m.increment();
		   }
		});
		Thread t2=new Thread(()->{
		   for(int i=0;i<1000;i++)
		   {
		       m.increment();
		   }
		});
		
		t1.start();
		t2.start();
		try{
		    t1.join();
		    t2.join();
		}catch(Exception e)
		{
		    System.out.print("Exception Caught");
		}
		
		System.out.print(m.getCount());
	}
}

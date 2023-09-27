//Multithreading

public class Main
{
	public static void main(String[] args) {
		
		
		Thread thread1=new Thread(()->{
		    for(int i=0;i<=5;i++)
		    {
		        System.out.println("Thread : "+Thread.currentThread().getId()+" count = "+i);
		       try {
		            Thread.sleep(1);
		           
		       } catch(Exception e) {
		       }
		    }
		    
		});
		Thread thread2=new Thread(()->{
		    for(int i=0;i<=5;i++)
		    {
		        System.out.println("Thread : "+Thread.currentThread().getId()+" count = "+i);
		    }
		});
		
		
		thread1.start();
		thread2.start();
	}
}

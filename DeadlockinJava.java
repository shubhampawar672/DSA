//createing dedlock
//if locks are acquired un same order then deadlock does not happen
//we are using Thread.sleep() to observe the deadlock if not used, program execute //so fast that thread can acquire and relese lock instantly,thus no deadlock being //observed.

public class Main
{
	public static void main(String[] args) {
		System.out.print("Main Thread");
		
		Object lock1=new Object();
		Object lock2=new Object();
		Thread thread1=new Thread(()->{
		    synchronized(lock1)
		    {
		        try {
		            Thread.sleep(1);
		        } catch(Exception e) {
		        }
		        synchronized(lock2){
		            System.out.println("Thread1");
		        }
		    }
		},"thread1");
		
			Thread thread2=new Thread(()->{
		    synchronized(lock2)
		    {
		        try {
		            Thread.sleep(1);
		        } catch(Exception e) {
		        }
		        synchronized(lock1){
		            System.out.println("Thread2");
		        }
		    }
		},"thread2");
		
		thread1.start();
		thread2.start();
	}
}

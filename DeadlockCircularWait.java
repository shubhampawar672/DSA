//circular wait ->deadlock ->both threads are waiting for each other to release locks
public class Main{
    private Object lock1=new Object();
    private Object lock2=new Object();
    
    void m1()
    {
      synchronized(lock1)
      {
          try {
              Thread.sleep(1000);
          } catch(Exception e){
          }
              synchronized(lock2)
              {
                    try {
                        Thread.sleep(1000);
                    } catch(Exception e) {
                    }   
              }
      }
    }
    void m2()
    {
      synchronized(lock2)
      {
          try {
              Thread.sleep(1000);
          } catch(Exception e) {
          }
              synchronized(lock1)
              {
                  try {
                      Thread.sleep(1000);
                  } catch(Exception e) {
                  }
              }
      }
    }
    public static void main(String args[])
    {
        Main m=new Main();
        Thread t1=new Thread(()->{
            m.m1();
        });
        Thread t2=new Thread(()->{
            m.m2();
        });
        t1.start();
        t2.start();
        
    }
}
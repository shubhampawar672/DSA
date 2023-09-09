/*
Thread Synchronization
*/

public class BankAccount
{
    private float balance;
    private Object lock=new Object();
    public BankAccount(float balance)
    {
        this.balance=balance;
    }
    
    public BankAccount()
    {
        balance=0;
    }
        void deposit(int balance)
        {
            synchronized(lock){
                
            this.balance+=balance;
            try {
                
            Thread.sleep(1000);
            } catch(Exception e) {
            }
            }
        }

    
    float getBalance()
    {
        return balance;
    }
    
    public static void main(String args[])
    {
        BankAccount m=new BankAccount(800);
        
        Thread t1=new Thread(()->{
            System.out.println("Called t1 first");
           m.deposit(500); 
        });
        Thread t2=new Thread(()->{
            System.out.println("Called t2 first");
           m.deposit(300); 
        });
        t1.start();
        t2.start();
        
        try{
        t1.join();
        t2.join();}
        catch(Exception e)
        {
            
        }
        System.out.print(m.getBalance());
    }
}
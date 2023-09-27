/*
Exceptions in java
Throwable is the root class for exceptions and error in java
Error and Exception class are the subclasses of the Throwable class.

Exception are checked and unchecked exception: checked exception->developer has to write code to handle this Exception
code will not run if not handled eg. SQLException, InstantiationException

Unchecked Exception are the runtime exceptions .These are difficult to predict as they may occure at runtime
eg. of Unchecked exception are ArrayOutofBoundException, NullPointerException, AirthmeticException

Checked exceptions are handled using try, catch ,throw, finally,throws keywords. throws keyword is used with method to denote
that particular type of exception can occure or aries in the method

To create Custom Exception we need to extend the Exception class or any subclass of Exception class such as AirthmaticException

In the custom exception class we make call to superclass constructor
*/
class Myexception extends Exception{
    public Myexception(){
        super("Custom Exception Occured");
    }
    public Myexception(String msg)
    {
        super(msg);
    }
    
}
public class Main
{
	public static void main(String[] args) {
		try {
		    throw new Myexception();
		    
		} catch(Exception e) {
		    System.out.println(e.getMessage());
		}
	}
}

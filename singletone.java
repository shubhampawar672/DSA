//Singletone class is class whoese only one instance can be created.
//for creating singletone class make constructor private and have a field that is instance of the same class.
//provide static method which will return the same object.
public  class Singletone{
    
    private static Singletone singletone=new Singletone();
    private Singletone(){};
    
    public static Singletone getInstance()
    {
        return singletone;
    }
    
}
class Main{
    
    public static void main(String args[]){
    Singletone s1=Singletone.getInstance();
    Singletone s2=Singletone.getInstance();
    System.out.println(s1);
    System.out.println(s2);

    }
}




//Instance block-> executed every time an instance of class is created. Can be used to put the code that is common to the all 
//the constructors.

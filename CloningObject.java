/*
Clonable Interface: Used to create copy of Object
It has clone() method which has to be implemented by the implementing class.
*/
 interface Clonable<T> {
    T clone();
}
class Person implements Clonable<Person>
{
    private String name;
    private int age;
    
    public Person(String name, int age)
    {
        this.name=name;
        this.age=age;
    }
    public Person(){}
    
    public String getName()
    {
        return this.name;
    }
    public int getAge()
    {
        return this.age;
    }
    @Override
    public Person clone()
    {
        return new Person(this.name,this.age);
    }
}
public class Main
{
	public static void main(String[] args) {
		Person p1=new Person("Shubham",21);
		System.out.println("Original Object "+p1.getName()+" "+p1.getAge());
		Person p2=p1.clone();
		System.out.println("Cloned Object "+p2.getName()+" "+p2.getAge());
	}
}

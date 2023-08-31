/*
Comparable and Comparator:
This both are the interfaces in java.
Used to sort the object coolection in specific  order 
Comparable gives natural ordering, when using comparable we need to compulsory override the compareTo method which return negative 
value if object is less , 0 if equal and positive if greater than second object.
while comparator is used to write our custom sorting logic, for using comparator we need to override compare method
*/

//comparable

/*
import java.util.ArrayList;
import java.util.List;
import java.util.Collections;
class person implements Comparable<person>{
    private String name;
    private int age;
    
    public String getName()
    {
        return this.name;
    }
    public person(String name, int age)
    {
        this.name=name;
        this.age=age;
    }
    public person()
    {
        
    }
    @Override
    public int compareTo(person p)
    {
        return Integer.compare(this.age,p.age);
    }
}
class Main{
    public static void main(String args[])
    {
        List<person>persons=new ArrayList<>();
        persons.add(new person("Shubham",20));
        persons.add(new person("Onkar",19));
        persons.add(new person("Bhushan",18));
        persons.add(new person("Yogesh",10));
        //Before Sorting
        for(person p:persons)
        {
            System.out.println(p.getName());
        }
        
        //After Sorting
        Collections.sort(persons);
           for(person p:persons)
        {
            System.out.println(p.getName());
        }
    }
}
*/




//comparator

import java.util.Comparator;
import java.util.List;
import java.util.ArrayList;
import java.util.Collections;

class Personcomparator implements Comparator<Person>{
    @Override
    public int compare(Person p1,Person p2)
    {
        if(p1.getAge()>p2.getAge())
        return -1;
        else if(p1.getAge()<p2.getAge())
        return 1;
        else
        return 0;
    }
}
class Person{
     private String name;
    private int age;
    public Person(String name,int age)
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
}

class Main{
    
    public static void main(String args[])
    {
        List<Person>persons=new ArrayList<>();
        
        persons.add(new Person("Shubham",21));
        persons.add(new Person("Harish",20));
        persons.add(new Person("Yogesh",22));
        
        Collections.sort(persons,new Personcomparator());
        for(Person p:persons)
        {
            System.out.println(p.getName());
        }
    }
}


import java.util.*;
class Order{
String city1,city2,city3;
void set1(String city1)
{this.city1=city1;}
void set2(String city3)
{this.city3=city3;}
void set3(String city2)
{this.city2=city2;}
String get1()
{
return this.city1;
}
String get2()
{
return this.city2;
}
String get3()
{
return this.city3;
}
}
class Question15
{
public static void main(String args[])
{
Scanner scan=new Scanner(System.in);
String s1,s2,s3;

System.out.println("Enter the name of the three cities respectively");
s1=scan.next();
s2=scan.next();
s3=scan.next();
Order obj=new Order();
obj.set1(s1);
obj.set2(s2);
obj.set3(s3);
s1=obj.get1();
s2=obj.get2();
s3=obj.get3();

System.out.println("The String in sorted order is ");
if(s1.compareTo(s2)<0&&s1.compareTo(s3)<0)
{
System.out.println(s1);
if(s2.compareTo(s3)<0)
{
System.out.println(s2);
System.out.println(s3);
}
else
{
System.out.println(s3);
System.out.println(s2);
}
}

if(s2.compareTo(s1)<0&&s2.compareTo(s3)<0)
{
System.out.println(s2);
if(s1.compareTo(s3)<0)
{
System.out.println(s1);
System.out.println(s3);
}
else
{
System.out.println(s3);
System.out.println(s1);
}
}

if(s3.compareTo(s1)<0&&s3.compareTo(s2)<0)
{
System.out.println(s3);
if(s2.compareTo(s1)<0)
{
System.out.println(s2);
System.out.println(s1);
}
else
{
System.out.println(s1);
System.out.println(s2);
}
}
}
}
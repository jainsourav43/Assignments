import java.util.*;
class Triangle{
int a,b,c;
void seta(int a)
{
this.a=a;
}
void setb(int b)
{
this.b=b;
}
void setc(int c)
{
this.c=c;
}
int geta()
{
return this.a;
}
int getb()
{
return this.b;
}

int getc()
{
return this.c;
}
}
class Question13{

public static void main(String args[]){
int x;
Triangle obj=new Triangle();
System.out.println("Enter the three sides of the Triangle ");
Scanner scan=new Scanner(System.in);
x=scan.nextInt();
obj.seta(x);
x=scan.nextInt();
obj.setb(x);
x=scan.nextInt();
obj.setc(x);
if(obj.geta()+obj.getb()>obj.getc()&&obj.geta()+obj.getc()>obj.getb()&&obj.getb()+obj.getc()>obj.geta())
{
System.out.println("The perimeter of thE TriaNGLE IS = "+(obj.geta()+obj.getb()+obj.getc()));
}
else
{
System.out.println("Invalid Edges");
}
}
}
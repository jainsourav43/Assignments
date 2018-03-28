import java.util.*;
// Class to find the average
class Average{
public static int average(int [] array)
{
int sum=0;
int i=0;
for(i=0;i<10;i++)
sum+=array[i];
return sum/10;
}
public static double average(double [] array)
{
double sum=0.0;
int i=0;
for(i=0;i<10;i++)
sum+=array[i];
return sum/10;
}
}
class Question2{
public static void main(String args[])
{
   Average obj=new Average();
   int[] in=new int[10];
   int i; 
   double[] don=new double[10];
   Random scan=new Random();
// Integer Printing
    System.out.println("The Integers are ");
   for(i=0;i<10;i++)
   {
    in[i]=scan.nextInt(100);
    System.out.print(in[i]+" ");
   } System.out.println();
// Doubles Printing
 System.out.println("The Doubles are ");
   for( i=0;i<10;i++)
   {
    don[i]=scan.nextDouble()*50+1;
    System.out.printf("%.2f     ",don[i]);
    
   } System.out.println();
// Printing The Average of Integers 
    System.out.println("The average of int is  = "+obj.average(in)); 
// Printing The Average of Doubles 
    System.out.print("The average of Double is  = "); 
    System.out.printf("%.2f",obj.average(don)); 


}
 }
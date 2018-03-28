import java.io.*;
import java.util.*;
class Print{
public static void main(String args[])
{
int i,j,k,n,j1;
System.out.println("Enter the value of n  : ");
Scanner Bastard =new Scanner(System.in);
n=Bastard.nextInt();
k=n;
for(i=1;i<=n;i++)
{
if(i==1)
{
for(j=0;j<k-1;j++)
{
System.out.print(" ");
}
System.out.print(1);
}
else
{
    for(j=0;j<k-1;j++)
    {
   System.out.print(" ");
    }
     System.out.print(i);
    // System.out.println("2*n-3-(k-1) = "+ (2*n-3-2*(k-1)));
    for(j=1;j<=7-2*(k-1);j++)
    {
   System.out.print(" ");
    }     
    System.out.print(i);
}
System.out.println();
k--;
}
k=5;
for(i=1;i<n;i++)
{
if(i==n-1)
{
for(j=0;j<k-1;j++)
{
System.out.print(" ");
}
System.out.print(1);
}
else
{
    for(j=0;j<i;j++)
    {
   System.out.print(" ");
    }
     System.out.print(n-i);
    for(j=1;j<=7-2*i;j++)
    {
   System.out.print(" ");
    }     
    System.out.print(n-i);
}
System.out.println();

}
}
} 
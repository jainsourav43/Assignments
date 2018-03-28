import java.util.*;
class Loan
{
double principal;
double rate;
double interest;
double time;
double Amount;
void setAmount(double Amount)
{
	this.Amount=Amount;
}
double getAmount()
{
	return this.Amount;
}
void set_time(double time)
{
  this.time=time;
}
void set_interest(double interest)
{
 this .interest=interest;
}
void set_rate(double rate)
{
  this.rate=rate;
}
void set_principal(double principal)
{
this.principal=principal;
}
double get_principal()
{
return this.principal;
}
double get_rate()
{
return this.rate;
}
double get_inerest()
{
return this.interest;
}
double get_time()
{
return this.time;
}
double calculateInterest(double amount)
{
double in;
in=amount*get_rate()/(100*12);

return in;
}
double calaculateTotal(double amount)
{
double in,tmpAmount=amount,sum=0;
int i=0;

System.out.println("Payment       Interest       Principal     Balance ");
for(i=0;tmpAmount>0;i++)
{

  in=calculateInterest(tmpAmount);	
  
  sum+=in;
  tmpAmount=tmpAmount-get_principal()+in;if(tmpAmount<0)break;
  System.out.print((i+1)); System.out.printf("              %.2f          ",in);System.out.printf("%.2f        ",(get_principal()-in));System.out.printf("%.2f      ",tmpAmount);
  System.out.println();
	  
}
return sum;
}
}
class Question14{
	public static void main(String args[])
	{
		double temp;
		Loan obj=new Loan();
		@SuppressWarnings("resource")
		Scanner scan =new Scanner(System.in);
		System.out.println("Enter the Amount ");
		temp=scan.nextDouble();
		obj.setAmount(temp);
		System.out.println("Enter the principal ");
		temp=scan.nextDouble();
		obj.set_principal(temp);
		System.out.println("Enter the rate ");
		temp=scan.nextDouble();
		obj.set_rate(temp);
		System.out.println("Enter the Time ");
		temp=scan.nextDouble();
		obj.set_time(temp);
		System.out.println("Total Amount is "+(obj.calaculateTotal(obj.getAmount())+obj.getAmount()));
		
		
	}
}
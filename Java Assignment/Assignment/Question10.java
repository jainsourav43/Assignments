import java.util.Scanner;

class future
{
	int presentDay;
	int noOfDays;
	int futureDay;
	
	public int getPresentDay() {
		return presentDay;
	}
	
	public void setPresentDay(int presentDay) {
		this.presentDay = presentDay;
	}
	
	public int getNoOfDays() {
		return noOfDays;
	}
	
	public void setNoOfDays(int noOfDays) {
		this.noOfDays = noOfDays;
	}
	
	public int getFutureDay() {
		return futureDay;
	}
	
	public void setFutureDay(int futureDay) {
		this.futureDay = futureDay;
	}
	
	int calculateFutureDay()
	{
	  int temp=(getPresentDay()+getNoOfDays());
	  temp%=7;
	  setFutureDay(temp);
	  return temp;
	}
	
	void display()
	{
		System.out.print("Today is ");
		switch(getPresentDay())
		{
		case 0:System.out.print("Sunday");break;
		case 1:System.out.print("Monday");break;
		case 2:System.out.print("Tuesday");break;
		case 3:System.out.print("Wednesday");break;
		case 4:System.out.print("Thrusday");break;
		case 5:System.out.print("Friday");break;
		case 6:System.out.print("Saturday");
		}
		
		calculateFutureDay();
		System.out.print("  and Future day is ");
		switch(getFutureDay())
		{
		case 0:System.out.println("Sunday");break;
		case 1:System.out.println("Monday");break;
		case 2:System.out.println("Tuesday");break;
		case 3:System.out.println("Wednesday");break;
		case 4:System.out.println("Thrusday");break;
		case 5:System.out.println("Friday");break;
		case 6:System.out.println("Saturday");
		}
	}	
}

public class Question10 {
	@SuppressWarnings("resource")
	public static void main(String args[])
	{
	future obj = new future();
	System.out.print("Please Enter the present day code :");
	Scanner scan =new Scanner(System.in);
	int temp;
	temp=scan.nextInt();
	obj.setPresentDay(temp);
	System.out.println("Please Enter the Number of Days :");
	temp=scan.nextInt();
	obj.setNoOfDays(temp);
	obj.display();
	}

}

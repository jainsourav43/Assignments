import java.util.Scanner;
//Minute Class 
class Minutes{
	long minutes;// MInutes by user 
        long  year,days;// Days and Years 
         // Getter and Setter 
	public long getMinutes() {
		return minutes;
	}
	public void setMinutes(long minutes) {
		this.minutes = minutes;
	}
	public long getYear() {
		return year;
	}
	public void setYear() {
		this.year = getMinutes()/(365*60*24);
	}
	public long getDays() {
		return days;
	}
	public void setDays() {
		this.days = ((getMinutes())/(24*60))%(365);
	}
	
}
public class Question4 {
	@SuppressWarnings("resource")
	public static void main(String args[])
	{
		Minutes obj =new Minutes();
		System.out.println("Enter the Minutes:");
		Scanner scan =new Scanner(System.in);
		long temp;
		temp= scan.nextLong();
		obj.setMinutes(temp);
		obj.setDays();
		obj.setYear();
		// Printing Equivalent Days and Years 
		System.out.println(obj.getMinutes()+" is Appoximately " +obj.getYear()+"  Years and  "+ obj.getDays()+ "Days ");
		
	}

}

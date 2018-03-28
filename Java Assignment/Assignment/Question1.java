import java.util.*;
// Population Class 
class Population{
//Getter And Setter methods

int birthRate;
int deathRate;
int immigrantRate;
int currentPopulation;

int getb()
{
return this.birthRate;
}
int getc()
{
return this.currentPopulation;
}
int getd()
{
	return this.deathRate;
}
void  seti(int immigrantRate)
{
	this.immigrantRate=immigrantRate;
}
void  setb(int birthRate)
{
 this.birthRate=birthRate;
}
void  setd(int deathRate)
{
   this.deathRate=deathRate;
}
void setc(int currentPopulation)
{
   this.currentPopulation=currentPopulation;
}
int geti()
{
	return this.immigrantRate;
}
}
// Main Class 
class Question1{
public static void main(String args[])
{
int ans2;
	Population obj=new Population();
	    obj.setb(7);
		obj.setd(13);
		obj.seti(45);
		obj.setc(312032486);
			int i=0;
                     // Calculating Population
		     int ans=365*24*3600/(obj.getb())-365*24*3600/(obj.getd())+365*24*3600/(obj.geti());
			for(i=0;i<5;i++){
				ans2= (i+1)*ans+obj.getc();
				System.out.println("The Population of "+(i+1)+" year is = "+ ans2);
			}
	
}
}
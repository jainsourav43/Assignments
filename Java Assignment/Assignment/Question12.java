import java.util.*;
class Game{
int computer;
int paaji;
void setpaaji(int paaji)
{
this.paaji=paaji;
}
void setcomputer(int computer)
{
this.computer=computer;
}
int getpaaji()
{
return this.paaji;
}
int getcomputer()
{return this.computer;}

}
class Question12
{
public static void main(String args[])
{
	Game obj= new Game();
	Scanner scan =new Scanner(System.in);
	Random r=new Random();
	int x;
	x= r.nextInt(3);
	obj.setcomputer(x);//System.out.println("x = "+x);
	System.out.println("IT's tour turn paaji enter the Number  and test your luck Fuck may be 0 for scissor ,1 for Rock ,2  for Paper only ");
	x=scan.nextInt();
      System.out.println();  System.out.println();  System.out.println();
	obj.setpaaji(x);
	if(obj.getcomputer()==0)
	{
	if(obj.getpaaji()==1)
	System.out.println(" Computer is Scissor and you are rock Paaji you won!!");
	else if(obj.getpaaji()==2)
	System.out.println(" Computer is scissor and you are paper Paaji you lost!!");
	else if(obj.getpaaji()==0)
	System.out.println(" Computer is Scissor and you are scissor too DRAW!!");
	else
	System.out.println("Pajji is Fool!");
	}
        if(obj.getcomputer()==1)
	{
	if(obj.getpaaji()==2)
	System.out.println(" Computer is Rock and you are Paper Paaji you won!!");
	else if(obj.getpaaji()==0)
	System.out.println(" Computer is Rock and you are Scissor  Paaji you lost!!");
	else if(obj.getpaaji()==1)
	System.out.println(" Computer is Rock and you are Rock too DRAW!!");
	else
	System.out.println("Pajji is fool!!");
	
	}
       if(obj.getcomputer()==2)
	{
	if(obj.getpaaji()==1)
	System.out.println(" Computer is Paper and you are Rock  Paaji you lost!!");
	else if(obj.getpaaji()==0)
	System.out.println(" Computer is Paper  and you are Scissor  Paaji you won!!");
	else if(obj.getpaaji()==2)
	System.out.println(" Computer is Paper and you are Paper too DRAW!!");
	else
	System.out.println("Pajji is Fool!!");
	
	} 

}
}
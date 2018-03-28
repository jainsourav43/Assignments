// 5.(Phone Keypad)

import java.util.*;

class PhoneKeypad
{
	//numbers array is defined for getting number corresponding to interger value of an character entered after subtracting from 65(A)
	static int[][] numbers={{2,2},{3,5},{4,8},{5,11},{6,14},{7,18},{8,21},{9,25}};

	//defining function as suggested
	public static int getNumber(char uppercaseLetter)
	{
		int temp=(char)(uppercaseLetter)-65;
		for(int i=0;i<8;i++)
		{
			if(numbers[i][1]>=temp)
			{
				return numbers[i][0];
			}
		}
		return -1;
	}

}

class Keypad
{
	public static void main(String[] args)
	{
		System.out.print("\nEnter a string : ");
		String str=(new Scanner(System.in)).nextLine();
		System.out.println("\nOutput\n");
		for(int i=0;i<str.length();i++)
		{
			char c=str.charAt(i);
			if(c>=97)
				c=(char)((int)(c)-32);
			if((int)(c)>=65 && (int)(c)<=90)
			{
				System.out.print(PhoneKeypad.getNumber(c));
			}
			else
				System.out.print(str.charAt(i));
		}
		System.out.println();
	}

}

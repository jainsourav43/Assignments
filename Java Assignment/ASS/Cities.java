 //15. Order Three Cities

import java.util.*;

//main class
class CityClass
{
	String CityName;

	//constructors

	public CityClass()
	{
		this.CityName=null;
	}

	public CityClass(String city_name)
	{
		this.CityName=new String(city_name);
	}

	//get functions

	public String GetCityName()
	{
		return this.CityName;
	}

	//set functions

	public void SetCityName(String city_name)
	{
		this.CityName=new String(city_name);
	}

	//function to sort an array of cities' names
    public static void Sort(CityClass[] cities,int size)
    {
        if(size>0)
        {
            for(int i=0;i<size;i++)
            {
                for(int j=i+1;j<size;j++)
                {
                    if(cities[i].CityName.compareTo(cities[j].CityName)>0)
                    {
                        CityClass temp=new CityClass();
                        temp=cities[i];
                        cities[i]=cities[j];
                        cities[j]=temp;
                    }
                }
            }
        }
    }
}

class Cities
{
    public static void main(String[] args)
    {
    	CityClass[] cities=new CityClass[5];
    	System.out.println("\nEnter five cities names.\n");
    	for(int i=0;i<5;i++)
    	{
    		String str=new String();
    		str=(new Scanner(System.in)).nextLine();
    		cities[i]=new CityClass();
    		cities[i].SetCityName(str);
    	}
    	CityClass.Sort(cities,5);

    	System.out.println("\nAfter sorting cities are : ");

    	for(int i=0;i<5;i++)
    	{
    		System.out.println(cities[i].GetCityName());
    	}

    	System.out.println();
    }
}

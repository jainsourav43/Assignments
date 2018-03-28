//  1. Population Projection

//main class of the program

class PopulationProjectionClass
{
	//declaring private member variables
	float DeathRate;
	float BirthRate;
	float ImmigrationRate;
	long CurrentPopulation;

	//constructors

	public PopulationProjectionClass()
	{
		this.DeathRate=this.BirthRate=this.ImmigrationRate=0;
		this.CurrentPopulation=0;
	}

	public PopulationProjectionClass(float death_rate,float birth_rate,float immigration_rate)
	{
		this.DeathRate=death_rate;
		this.BirthRate=birth_rate;
		this.ImmigrationRate=immigration_rate;
	}
	
	public PopulationProjectionClass(float death_rate,float birth_rate,float immigration_rate,long current_population)
	{
		this.DeathRate=death_rate;
		this.BirthRate=birth_rate;
		this.ImmigrationRate=immigration_rate;
		this.CurrentPopulation=current_population;
	}

	//set functions

	public void SetDeathRate(float rate)
	{
		this.DeathRate=rate;
	}

	public void SetBirthRate(float rate)
	{
		this.BirthRate=rate;
	}

	public void SetImmigrationRate(float rate)
	{
		this.ImmigrationRate=rate;
	}

	public void SetCurrenPopulation(long population)
	{
		this.CurrentPopulation=population;
	}

	//get functions

	public float GetDeathRate()
	{
		return this.DeathRate;
	}

	public float GetBirthRate()
	{
		return this.BirthRate;
	}

	public float GetImmigrationRate()
	{
		return this.ImmigrationRate;
	}

	public long GetCurrentPopulation()
	{
		return this.CurrentPopulation;
	}

	//function for calculating population after k years
	public  long CaluculatePopulation(int k)
	{
		//calculating populationg after k years with given values 
		long population_increase=(long)(365*24*60*60*(this.BirthRate + this.ImmigrationRate - this.BirthRate));
		return population_increase*k+this.CurrentPopulation;
	}
}

class PopulationProjection
{
	public static void main(String[] args)
	{
		//creating an instance of PopulationProjectonClass class
		PopulationProjectionClass obj=new PopulationProjectionClass(13,7,45,312032486);
		for(int i=0;i<5;i++)
		{
			System.out.println("\nPopulation after "+(i+1)+" years "+obj.CaluculatePopulation(i+1)+"\n");
		}

	}
}
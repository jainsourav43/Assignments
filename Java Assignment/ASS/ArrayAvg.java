/*
 2. Array Average 
*/


//main class
class ArrayAvgClass
{  
    
    // a static funcion for getting average of a double array
    public static double average(double[] d,int size)
    {
        double temp=0;
        for(int i=0;i<size;i++)
        {
            temp=temp+d[i];
        }
        return temp/size;
    }

    // a static function for getting average of a integer array
    public static float average(int[] d,int size)
    {
        int temp=0;
        for(int i=0;i<size;i++)
        {
            temp=temp+d[i];
        }
        return (float)((float)(temp)/size);
    }
}

class ArrayAvg
{
    public static void main(String[] args)
    {
        int[] ArrInt=new int[10];
        double[] ArrDoub=new double[10];

        //generating 10 random integers and storing in array
        System.out.print("\nRandomly generated integers are : ");
        for(int i=0;i<10;i++)
        {
            ArrInt[i]=((int)(Math.random()*10)+1);
            System.out.print(ArrInt[i]+"  ");
        }

        //generating 10 random double numbers and storing them in array
        System.out.print("\nRandomly generated double numbers are : ");
        for(int i=0;i<10;i++)
        {
            ArrDoub[i]=Math.random()*10+1;
            System.out.printf("%.2f   ",ArrDoub[i]);
        }
        System.out.println();
        //prining average of both arrays
        System.out.println("\nAverage of integer array = "+ArrayAvgClass.average(ArrInt,10));
        System.out.printf("\nAverage of double array = %.2f \n ",ArrayAvgClass.average(ArrDoub,10));
    }
}

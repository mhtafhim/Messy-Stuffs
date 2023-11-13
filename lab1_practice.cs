using System;

class Program
{
    static void Main()
    {
       
        int firstNumber = Convert.ToInt32(Console.ReadLine());

      
        int secondNumber = Convert.ToInt32(Console.ReadLine());

      
        if (firstNumber > secondNumber)
        {
            Console.WriteLine("It is right");
        }
        else
        {
            int result = firstNumber * secondNumber;
            Console.WriteLine($"{result}");
        }
    }
}

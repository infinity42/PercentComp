#include <iostream>
using namespace std;

int Exponent(int Base, int Exponent)
{
   int ReturnValue = 1;
   while(Exponent != 0)
  {
		ReturnValue = ReturnValue*Base;
		Exponent--;
	}
	return ReturnValue;
}

int BinaryConverter(int BaseTenValue)
{
	int ReturnValue, CounterValue, ModValue, ExponentCounter, NegativeTest, Binary;
	ModValue = 1;
	ExponentCounter = 0;
   ReturnValue = 0;
	while(BaseTenValue % ModValue != BaseTenValue)
	{
		ModValue = ModValue * 2;
		ExponentCounter++;
	}
	ModValue = ModValue/2;
   ExponentCounter--;
	CounterValue = BaseTenValue;
   while(CounterValue > 0)
	{
		NegativeTest = CounterValue - ModValue; 
		if(NegativeTest >= 0)
		{
			Binary = Exponent(10, ExponentCounter);
			CounterValue = CounterValue - ModValue;
			ReturnValue = ReturnValue + Binary;
		}
		ModValue = ModValue/2;
      ExponentCounter--;
   }
	return ReturnValue;
}

int FactorialConverter(int BaseTenValue)
{
   int ReturnValue, CounterValue, ModValue, ExponentCounter, NegativeTest, Binary;
	ModValue = 1;
	ExponentCounter = 0;
   ReturnValue = 0;
	while(BaseTenValue % ModValue != BaseTenValue)
	{
   	ExponentCounter++;
		ModValue = ModValue * ExponentCounter;
	}
	ModValue = ModValue/ExponentCounter;
   ExponentCounter--;
	CounterValue = BaseTenValue;
   while(CounterValue > 0)
	{
		NegativeTest = CounterValue - ModValue; 
		if(NegativeTest >= 0)
		{
			Binary = Exponent(10, ExponentCounter);
         Binary = Binary/10;
			CounterValue = CounterValue - ModValue;
			ReturnValue = ReturnValue + Binary;
		}
      else
      {
		   ModValue = ModValue/ExponentCounter;
         ExponentCounter--;
      }
   }
	return ReturnValue;
}

void Display(int StartPoint, int EndPoint)
{
   int Counter = StartPoint;
   cout << "BASE TEN \t BINARY \t FACTORIAL" << endl;
   while (Counter <= EndPoint)
   {
      cout << Counter << "\t \t" << BinaryConverter(Counter) << "\t \t" << FactorialConverter(Counter) << endl;
      Counter++;
   }
}

int main ()
{
   Display(1, 24);
   return 0;
}

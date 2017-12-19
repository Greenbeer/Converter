#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convert_c(float value);
void convert_f(float value);
void convert_k(float value);

int main(int argc, char* argv[])
{
  float temp;
  
  temp = atof(argv[1]); 
  
  if (argc == 2)
	{       
    convert_c(temp);
    convert_f(temp);
    convert_k(temp);
  }
  else if (argc == 3) 
	{
    if (strcmp(argv[2], "C") == 0 || strcmp(argv[2], "c") == 0) 
		{
      convert_c(temp);
    }
    else if (strcmp(argv[2], "F") == 0 || strcmp(argv[2], "f") == 0) 
		{
      convert_f(temp);
    }
    else if (strcmp(argv[2], "K") == 0 || strcmp(argv[2], "k") == 0) 
		{
      convert_k(temp);
    }
    else 
		{
      printf("Invalid input value scale (%s) received.\nTry:\n'C' for Celsius,\n'F' for Fahrenheit,\n'K' for Kelvin.\n", argv[2]);
    }
  }
  else 
	{
    printf("No data received.\nUsage: 'tconvert <Temp> <Input value scale (C, F, K)>'\nor 'tconvert <Temp>' to convert from Celsius, Fahrenheit, Kelvin at once.");
  }
  return 0;
}

void convert_c(float value)
{
  float fahrenheit = value * 9.0 / 5.0 + 32;
  float kelvin = value + 273.15;
  if (kelvin < 0) 
	{
    printf("Input value is lower than absolute zero. (%.2f C/%.2f K)\n", value, kelvin);
  }
  else printf("%.2f C:\n%.2f F\n%.2f K\n\n", value, fahrenheit, kelvin);
}

void convert_f(float value)
{
  float celsius = (value - 32) * 5.0 / 9.0;
  float kelvin = celsius + 273.15;
  if (kelvin < 0) 
	{
    printf("Input value is lower than absolute zero. (%.2f F/%.2f K)\n", value, kelvin);
  }
  else printf("%.2f F:\n%.2f C\n%.2f K\n\n", value, celsius, kelvin);
}

void convert_k(float value)
{
  float celsius = value - 273.15;
  float fahrenheit = celsius * 9.0 / 5.0 + 32;
  if (value < 0) 
	{
    printf("Input value is lower than absolute zero. (%.2f K)\n", value);
  }
  else printf("%.2f K:\n%.2f C\n%.2f F\n\n", value, celsius, fahrenheit);
}

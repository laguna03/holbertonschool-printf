#include "main.h"

/**
* printChar - Writes one char to the standard output.
* @c: just a character
* Return: the value of write.
*/
int printChar(int c)
{
	return (write(1, &c, 1));
}

/**
* printStr - Writes a string to the standard output.
* @str: just a string
* Return: the count.
*/
int printStr(char *str)
{
	int count = 0;

	while (*str)
	{
		count = printChar(*str++);
	}
	return (count);
}

/**
* printDigit - Recursively writes a digit to the standard output.
* @n: number to write
* @base: 10
* Return: the count.
*/
int printDigit(long n, int base)
{
	int count = 0;
	char *digits = "0123456789";

	if (n < 0)
	{
		write(1, "-", 1);
		return (printDigit(-n, base));
	}
	else if (n < base)
	{
		return (printChar(digits[n]));
	}
	else
	{
		count = printDigit(n / base, base);
		return (count + printDigit(n % base, base));
	}
}

/**
* specChecker - Checks which specifier is used and redirects to a function.
* @spec: the character to compare.
* @ap: the argument pointer
* Return: the count.
*/
int specChecker(char spec, va_list ap)
{
	int count = 0;

	if (spec == 'c')
	{
		count = printChar(va_arg(ap, int));
	}
	else if (spec == 's')
	{
		count = printStr(va_arg(ap, char *));
	}
	else if (spec == 'i' || spec == 'd')
	{
		count = printDigit((long)va_arg(ap, int), 10);
	}
	else
	{
		count = write(1, &spec, 1);
	}
	return (count);
}

/**
* _printf - Prints what you need it to.
* @format: the string
* @..: the arguments
* Return: the count.
*/
int _printf(const char *format, ...)
{
	int count = 0;
	va_list ap;

	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			count += specChecker(*++format, ap);
		}
		else
		{
			count += write(1, format, 1);
		}
		format++;
	}
	va_end(ap);
	return (count);
}

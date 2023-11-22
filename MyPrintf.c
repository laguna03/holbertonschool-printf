#include "main.h"

int printChar(int c)
{
	return (write(1, &c, 1));
}

int printStr(char *str)
{
	int count = 0;

	while (*str)
	{
		count = printChar(*str++);
	}
	return (count);
}

int printDigit(int n, int base)
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
		count = printDigit(va_arg(ap, int), 10);
	}
	else
	{
		count = write(1, &spec, 1);
	}
	return (count);
}

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

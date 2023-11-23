#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"
/**
* _printf - Prints what you need it to.
* format: the string
* @..: the arguments
* Return: the count.
*/
int _printf(const char *format, ...)
{
    va_list ap;
    int count = 0;

    va_start(ap, format);
    count = 0;
    while (*format != '\0')
    {
        if (*format == '%')
        {
            count += specChecker(*(++format), ap);
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
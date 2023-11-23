#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>

char _putchar(char);
int _printf(const char *format, ...);
int specChecker(char spec, va_list ap);
int printChar(int);
int printStr(char *str);
int printDigit(long n, int base);

#endif

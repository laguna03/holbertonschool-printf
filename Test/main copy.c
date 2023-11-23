#include "main copy.h"

/**
* main - Entry point
*
* Return: Always 0
*/
int main(void)
{
    int len;
    int len2;
    unsigned int ui;
    void *addr;

    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    _printf("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    _printf("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    _printf("Unknown:[%r]\n");
    return (0);
    //  int result;
    
    // Test cases
    //  result = _printf("%c\n", 'A');
    //  printf("Result: %d\n\n", result);
    //  
    //  result = _printf("%s\n", "Hello, World!");
    //  printf("Result: %d\n\n", result);
    //  
    //  result = _printf("%d\n", 12345);
    //  printf("Result: %d\n\n", result);
    //  
    //  result = _printf("%i\n", -6789);
    //  printf("Result: %d\n\n", result);
    //  
    //  result = _printf("%%\n");
    //  printf("Result: %d\n\n", result);
    //  
    //  result = _printf("This is a test: %c, %s, %d, %i\n", 'X', "Test String", 9876, -5432);
    //  printf("Result: %d\n\n", result);
    //  
    //  return (0);
    //  
}

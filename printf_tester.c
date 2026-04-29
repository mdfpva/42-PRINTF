#include "include/ft_printf.h"
#include <limits.h>
#include <stdio.h>

int		print_result(int real, int fake);
void	print_final_result(int res);

int main(void)
{
	int		real = 0;
	int		fake = 0;
	int		res = 0;
	char	*str = NULL;

	real = printf("Character: %c\n", 'A');
	fake = ft_printf("Character: %c\n", 'A');
	res += print_result(real, fake);

	real = printf("Null character: %c\n", '\0');
	fake = ft_printf("Null character: %c\n", '\0');
	res += print_result(real, fake);

	real = printf("Empty string: %s\n", "");
	fake = ft_printf("Empty string: %s\n", "");
	res += print_result(real, fake);

	real = printf("Null string: %s\n", str);
	fake = ft_printf("Null string: %s\n", str);
	res += print_result(real, fake);

	real = printf("Regular string: %s\n", "Hello, World!");
	fake = ft_printf("Regular string: %s\n", "Hello, World!");
	res += print_result(real, fake);

	real = printf("Null pointer: %p\n", &str);
	fake = ft_printf("Null pointer: %p\n", &str);
	res += print_result(real, fake);

	real = printf("No pointer: %p\n", NULL);
	fake = ft_printf("No pointer: %p\n", NULL);
	res += print_result(real, fake);

	real = printf("Valid pointer: %p\n", &ft_printf);
	fake = ft_printf("Valid pointer: %p\n", &ft_printf);
	res += print_result(real, fake);

	real = printf("Positive integer: %d\n", 42);
	fake = ft_printf("Positive integer: %d\n", 42);
	res += print_result(real, fake);

	real = printf("Negative integer: %d\n", -42);
	fake = ft_printf("Negative integer: %d\n", -42);
	res += print_result(real, fake);

	real = printf("Zero integer: %d\n", 0);
	fake = ft_printf("Zero integer: %d\n", 0);
	res += print_result(real, fake);

	real = printf("Minimum integer: %d\n", INT_MIN);
	fake = ft_printf("Minimum integer: %d\n", INT_MIN);
	res += print_result(real, fake);

	real = printf("Maximum integer: %d\n", INT_MAX);
	fake = ft_printf("Maximum integer: %d\n", INT_MAX);
	res += print_result(real, fake);

	real = printf("Zero unsigned: %u\n", 0);
	fake = ft_printf("Zero unsigned: %u\n", 0);
	res += print_result(real, fake);

	real = printf("Positive unsigned: %u\n", 42);
	fake = ft_printf("Positive unsigned: %u\n", 42);
	res += print_result(real, fake);

	real = printf("Negative unsigned: %u\n", -42);
	fake = ft_printf("Negative unsigned: %u\n", -42);
	res += print_result(real, fake);

	real = printf("Maximum unsigned: %u\n", UINT_MAX);
	fake = ft_printf("Maximum unsigned: %u\n", UINT_MAX);
	res += print_result(real, fake);

	real = printf("Zero hex: %x\n", 0);
	fake = ft_printf("Zero hex: %x\n", 0);
	res += print_result(real, fake);

	real = printf("Positive hex: %x\n", 42);
	fake = ft_printf("Positive hex: %x\n", 42);
	res += print_result(real, fake);

	real = printf("Maximum unsigned hex: %x\n", UINT_MAX);
	fake = ft_printf("Maximum unsigned hex: %x\n", UINT_MAX);
	res += print_result(real, fake);

	real = printf("Negative number hex: %x\n", -1);
	fake = ft_printf("Negative number hex: %x\n", -1);
	res += print_result(real, fake);

	real = printf("Zero HEX: %X\n", 0);
	fake = ft_printf("Zero HEX: %X\n", 0);
	res += print_result(real, fake);

	real = printf("Positive HEX: %X\n", 42);
	fake = ft_printf("Positive HEX: %X\n", 42);
	res += print_result(real, fake);

	real = printf("Maximum unsigned HEX: %X\n", UINT_MAX);
	fake = ft_printf("Maximum unsigned HEX: %X\n", UINT_MAX);
	res += print_result(real, fake);

	real = printf("Negative number HEX: %X\n", -1);
	fake = ft_printf("Negative number HEX: %X\n", -1);
	res += print_result(real, fake);

	real = printf("Percent sign: %%\n");
	fake = ft_printf("Percent sign: %%\n");
	res += print_result(real, fake);

	real = printf("Multiple percent signs: %% %% %%\n");
	fake = ft_printf("Multiple percent signs: %% %% %%\n");
	res += print_result(real, fake);

	real = printf("Mixed types: %d %s %c %x %p\n",
	42, "Hello", 'A', 255, &ft_printf);
	fake = ft_printf("Mixed types: %d %s %c %x %p\n",
	42, "Hello", 'A', 255, &ft_printf);
	res += print_result(real, fake);
	
	print_final_result(res);
} 

int	print_result(int real, int fake)
{
	if (real == fake)
	{
		printf("\033[32m[OK]\033[0m\n\n");
		return (0);
	}
	else
	{
		printf("\033[31m[KO] (expected %d and got %d)\033[0m\n\n", real, fake);
		return (1);
	}
}

void	print_final_result(int res)
{
	if (res == 0)
		printf("\033[1;32mYou passed all tests!\033[0m\n");
	else if (res == 1)
		printf("\033[1;31mYou failed 1 test.\033[0m\n");
	else
		printf("\033[1;31mYou failed %d tests.\033[0m\n", res);
}

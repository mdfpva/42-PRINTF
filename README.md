*This project has been created as part of the 42 curriculum by mide-fre.*

# ft_printf

## Description

`ft_printf` is a reimplementation of the C standard library function `printf()`. The goal of this project is to understand how variadic functions work in C, and to build a robust, extensible output formatting library from scratch.

The function handles the following conversions:

| Specifier | Description |
|-----------|-------------|
| `%c` | Prints a single character |
| `%s` | Prints a string |
| `%p` | Prints a pointer address in hexadecimal format |
| `%d` | Prints a decimal (base 10) number |
| `%i` | Prints an integer in base 10 |
| `%u` | Prints an unsigned decimal (base 10) number |
| `%x` | Prints a number in hexadecimal lowercase format |
| `%X` | Prints a number in hexadecimal uppercase format |
| `%%` | Prints a percent sign |

The function returns the total number of characters printed, just like the original `printf()`.

---

## Instructions

### Compilation

To compile the library, run:

```bash
make
```

This will produce `libftprintf.a` at the root of the repository.

### Usage

Include the header in your source file:

```c
#include "ft_printf.h"
```

Then link the library when compiling:

```bash
cc your_file.c libftprintf.a -o your_program
```

### Makefile rules

| Rule | Description |
|------|-------------|
| `make` / `make all` | Compiles the library |
| `make clean` | Removes object files |
| `make fclean` | Removes object files and the library |
| `make re` | Runs fclean then all |

---

## Algorithm and Data Structure

### Overall structure

The function reads through the format string character by character. When it encounters a `%`, it reads the next character to determine the conversion specifier and dispatches to the appropriate helper function. Each helper function returns the number of characters it printed, which `ft_printf` accumulates and returns at the end.

### Integer and hexadecimal printing — recursive approach

Rather than using a buffer to store digits and reversing them, all numeric output functions (`ft_putnbr`, `ft_putui`, `ft_puthex`) use **recursion** to print digits in the correct order.

The key insight is: divide the number by the base recursively until you reach a single digit, then print digits **on the way back up** the call stack. This naturally produces the correct left-to-right order without needing any intermediate storage.

Example for base 10 (`n = 123`):
```
ft_putnbr(123) → calls ft_putnbr(12), then prints '3'
ft_putnbr(12)  → calls ft_putnbr(1),  then prints '2'
ft_putnbr(1)   → prints '1'  (base case: n < 10)
```
Output: `1`, `2`, `3` — correct order, no buffer needed.

The same logic applies to hexadecimal with base 16.

### Pointer printing

Pointers are cast to `uintptr_t` (from `<stdint.h>`) to safely represent a memory address as an integer on both 32-bit and 64-bit systems. A dedicated recursive function handles the hexadecimal conversion, prefixed by `"0x"`.

### Negative numbers

`ft_putnbr` casts the `int` to a `long` before negating, to safely handle `INT_MIN` (`-2147483648`), whose positive value overflows a regular `int`.

### NULL string handling

`ft_putstr` checks for a `NULL` pointer and prints `"(null)"` in that case, matching the behavior of the original `printf()`.

---

## Resources

- *The C Programming Language* — Brian W. Kernighan and Dennis M. Ritchie
- [C Standard Library — printf man page](https://man7.org/linux/man-pages/man3/printf.3.html)
- [Variadic functions in C — cppreference](https://en.cppreference.com/w/c/variadic)
- [stdint.h and uintptr_t](https://en.cppreference.com/w/c/types/integer)
- [42 Norm](https://github.com/42School/norminette)

### Use of AI

Claude (claude.ai) was used during this project as a learning support tool, in accordance with the 42 guidelines on AI usage. Specifically, AI was consulted to:

- Clarify concepts around variadic functions (`va_list`, `va_arg`, etc.)
- Understand the difference between pointer types (`void *`, `uintptr_t`) and why `uintptr_t` is needed for safe pointer-to-integer conversion
- Debug compiler errors and understand their root cause
- Discuss tradeoffs between implementation approaches (e.g. buffer vs recursion for digit printing)

In all cases, AI was used to understand concepts and debug errors — not to generate the final code directly.

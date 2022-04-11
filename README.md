# Printf recoding
This project is based on recoding the *printf* function, which allows the printing of strings, as well as translating the value
of variables to be printed as well. Thanks to this project, it was possible to learn how to implement variadic functions and what
their use is.

## How to use it:

To create that library, follow these steps:
```
	git clone https://github.com/daalmeid/printf.git
	cd printf
	make
```
  You should create a file called **libftprintf.a**. In your projects, make a call to ft_printf to use it, just as you would use
  the original printf. Avaliable conversions:
  - **%d or %i** - The *int* argument is converted to its signed decimal notation;
  - **%c** - The *int* argument is converted to an unsigned char and is printed;
  - **%s** - the *const char \** argument is expected to be a pointer  to  a  string. Characters from the array are written up to 
  (but not including) a terminating null byte ('\0');
  - **%p** - The *void \** pointer argument is printed in hexadecimal;
  - **%u** - The *int* argument is converted to its unsigned decimal notation;
  - **%x** - The *int* argument is converted to its hexadecimal notation with ;
  - **%X** - The *int* argument is converted to its hexadecimal notation with capital letters;
  - **%%** - Prints a *%* character.
  
  When compiling, use the flags -L(directory where libftprintf is) and -lftprintf.
  I hope my work can be of use to you!

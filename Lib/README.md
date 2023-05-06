# libft

## Description

Libft is an individual project at 42 that aims to build a library of useful functions that we will be allowed to use in all of our future projects.

## Getting Started

To get started with the libft.a library, you need to have the following files in your project directory:

- `libft.h`: header file containing function prototypes and macro definitions
- `libft.a`: static library file containing compiled object code of the library functions
- `ft_*.c`: source files containing the implementation of the library functions

You can compile the `libft.a` library by running the `make` command in the project directory. This will generate the `libft.a` file that you can link to your project.

## Makefile

The Makefile included in the project provides the following targets:

- `all`: compiles the library
- `clean`: removes object files
- `fclean`: removes object files and the library file
- `re`: removes object files and the library file, then compiles the library again

You can run these targets by typing `make` followed by the target name in the terminal.

## Functions

The `libft.a` library contains the following functions:

### Libc Functions

- `ft_atoi`: converts a string to an integer
- `ft_bzero`: sets a memory area to zero
- `ft_calloc`: allocates memory for an array and initializes it to zero
- `ft_isascii`: checks if a character is a valid ASCII character
- `ft_isalnum`: checks if a character is an alphabetic or a digit
- `ft_isalpha`: checks if a character is an alphabetic character
- `ft_isdigit`: checks if a character is a digit
- `ft_isprint`: checks if a character is a printable character
- `ft_memchr`: searches for a specific character in a memory area
- `ft_memcmp`: compares two memory areas
- `ft_memcpy`: copies a memory area from source to destination
<!-- - `ft_memccpy`: copies a memory area from source to destination until a specific character is found -->
- `ft_memmove`: copies a memory area from source to destination, handling overlapping areas
- `ft_memset`: sets a memory area to a specific value
- `ft_strchr`: searches for a specific character in a string
- `ft_strdup`: duplicates a string
- `ft_strlcat`: appends a string to a destination buffer, with a specified maximum size
- `ft_strlcpy`: copies a string to a destination buffer, with a specified maximum size
- `ft_strlen`: calculates the length of a string
- `ft_strncmp`: compares two strings, up to a specified maximum length
- `ft_strnstr`: searches for a substring in a string, with a specified maximum length
- `ft_strrchr`: searches for a specific character in a string, starting from the end
- `ft_tolower`: converts a character to lowercase
- `ft_toupper`: converts a character to uppercase

### String Manipulation

- `ft_itoa`: Converts an integer to a string.
- `ft_putchar_fd`: Outputs a character to a file descriptor.
- `ft_putendl_fd`: Outputs a string followed by a newline to a file descriptor.
- `ft_putnbr_fd`: Outputs an integer to a file descriptor.
- `ft_putstr_fd`: Outputs a string to a file descriptor.
- `ft_split`: Splits a string into an array of substrings based on a delimiter character.
- `ft_striteri`: Applies a function to each character of a string.
- `ft_strjoin`: Concatenates two strings.
- `ft_strmapi`: Applies a function to each character of a string with its index.
- `ft_strtrim`: Removes specified characters from the beginning and end of a string.
- `ft_substr`: Returns a substring of a string starting at a specified index with a specified length.

### Bonus functions

- `ft_lstadd_back`: Adds a new element to the end of a linked list.
- `ft_lstadd_front`: Adds a new element to the beginning of a linked list.
- `ft_lstclear`: Deletes all elements of a linked list and frees their memory.
- `ft_lstdelone`: Deletes an element of a linked list and frees its memory.
- `ft_lstlast`: Returns the last element of a linked list.
- `ft_lstmap`: Applies a function to each element of a linked list and creates a new list with the results.
- `ft_lstnew`: Creates a new element for a linked list.
- `ft_lstsize`: Returns the number of elements in a linked list.
- `ft_lstiter`: Applies a function to each element of a linked list.

## Credits

This project was completed as part of the curriculum at [19](https://campus19.be/)

# libft
A C-library of usual functions

## Library content

### Part 1 - libc

##### Functions from `<ctype.h>` library

* [`ft_isalnum`](srcs/ctype/ft_isalnum.c)
* [`ft_isalpha`](srcs/ctype/ft_isalpha.c)
* [`ft_isascii`](srcs/ctype/ft_isascii.c)
* [`ft_isdigit`](srcs/ctype/ft_isdigit.c)
* [`ft_islower`](srcs/ctype/ft_islower.c)
* [`ft_isprint`](srcs/ctype/ft_isprint.c)
* [`ft_isupper`](srcs/ctype/ft_isupper.c)
* [`ft_tolower`](srcs/ctype/ft_tolower.c)
* [`ft_toupper`](srcs/ctype/ft_toupper.c)

##### Functions from `<stdlib.h>` library

* [`ft_atoi`](srcs/conv/ft_atoi.c)
* [`ft_calloc`](srcs/memory/ft_calloc.c)

##### Functions from `<strings.h>` library

* [`ft_bzero`](srcs/memory/ft_bzero.c)
* [`ft_memchr`](srcs/memory/ft_memchr.c)
* [`ft_memcmp`](srcs/memory/ft_memcmp.c)
* [`ft_memcpy`](srcs/memory/ft_memcpy.c)
* [`ft_memmove`](srcs/memory/ft_memmove.c)
* [`ft_memset`](srcs/memory/ft_memset.c)

##### Functions from `<string.h>` library

* [`ft_strchr`](srcs/strings/ft_strchr.c)
* [`ft_strcmp`](srcs/strings/ft_strcmp.c)
* [`ft_strcpy`](srcs/strings/ft_strcpy.c)
* [`ft_strdup`](srcs/strings/ft_strdup.c)
* [`ft_strlen`](srcs/strings/ft_strlen.c)
* [`ft_strlcat`](srcs/strings/ft_strlcat.c)
* [`ft_strlcpy`](srcs/strings/ft_strlcpy.c)
* [`ft_strncmp`](srcs/strings/ft_strncmp.c)
* [`ft_strncpy`](srcs/strings/ft_strncpy.c)
* [`ft_strndup`](srcs/strings/ft_strndup.c)
* [`ft_strnstr`](srcs/strings/ft_strnstr.c)
* [`ft_strrchr`](srcs/strings/ft_strrchr.c)

### Part 2 - Additional functions

#### [`free_strs`](srcs/free/free_strs.c)
> Free all the strings in the string array then free the array pointer.

#### [`ft_itoa`](srcs/conv/ft_itoa.c)
> Allocates (with malloc(3)) and returns a string
> representing the input integer.
> Negative numbers are supported.
> Returns NULL if allocation fails.

#### [`ft_lstadd_back`](srcs/list/ft_lstadd_back.c)
> Adds a new element at the end of the list.

#### [`ft_lstadd_front`](srcs/list/ft_lstadd_front.c)
> Adds a new element to the beginning of the list.

#### [`ft_lstclear`](srcs/list/ft_lstclear.c)
> Frees the list (each element of the list is freed thanks to [ft_lstdelone](srcs/list/ft_lstdelone.c)).
> Then all element pointers are set to NULL.

#### [`ft_lstdelone`](srcs/list/ft_lstdelone.c)
> Frees the element's contents with del (passed as an argument),
> then frees the element with free(3).

#### [`ft_lstiter`](srcs/list/ft_lstiter.c)
> Iterates over the list and applies the input function to each element.

#### [`ft_lstlast`](srcs/list/ft_lstlast.c)
> Returns the last element of the list.

#### [`ft_lstmap`](srcs/list/ft_lstmap.c)
> Allocates (with malloc(3)) and returns a duplicate of the list,
> but f has been applied to each element of this new list.
> Release the duplicate (using [ft_lstclear](srcs/list/ft_lstclear.c))
> if the allocation fails and returns NULL.

#### [`ft_lstnew`](srcs/list/ft_lstnew.c)
> Allocates (with malloc(3)) and returns a list which takes
> as content the input content.
> Returns NULL if allocation fails.

#### [`ft_lstsize`](srcs/list/ft_lstsize.c)
> Returns the size of the list.
#### [`ft_putchar_fd`](srcs/output/ft_putchar_fd.c)
> Writes a character on the input file descriptor.

#### [`ft_putendl_fd`](srcs/output/ft_putendl_fd.c)
> Writes a string on the input file descriptor followed by a newline.

#### [`ft_putnbr_fd`](srcs/output/ft_putnbr_fd.c)
> Writes a integer on the input file descriptor.

#### [`ft_putstr_fd`](srcs/output/ft_putstr_fd.c)
> Writes a string on the input file descriptor.

#### [`ft_split`](srcs/strings/ft_split.c)
> Allocates (with malloc(3)) and returns an array of strings obtained by
> separating the input string with the input character used as the delimiter.
> The resulting array is terminated with a NULL pointer.
> Returns NULL if allocation fails.

#### [`ft_split_set`](srcs/strings/ft_split_set.c)
> Allocates (with malloc(3)) and returns an array of strings obtained by
> separating the input string with the input charset used as the delimiter.
> The resulting array is terminated with a NULL pointer.
> Returns NULL if allocation fails.

#### [`ft_striteri`](srcs/strings/ft_striteri.c)
> Allocates (with malloc(3)) and returns a duplicate string each character
> of which has been modified by the input function
> (which takes as argument the input string and its index).
> Returns NULL if the allocation fails.

#### [`ft_strjoin`](srcs/strings/ft_strjoin.c)
> Allocates (with malloc(3)) and returns a new string resulting from
> the concatenation of two strings.
> Returns NULL if allocation fails.

#### [`ft_strmapi`](srcs/strings/ft_strmapi.c)
> Allocates (with malloc(3)) and returns a duplicate string each character
> of which has been modified by the input function
> (which takes as argument each character of the input string and its index).
> Returns NULL if the allocation fails.

#### [`ft_strnjoin`](srcs/strings/ft_strnjoin.c)
> Allocates (with malloc(3)) and returns a concatenation of two strings.
> The first string is freed.
> If a string is NULL, it will be treated as empty string
> Returns NULL if allocation fails.

#### [`ft_strtrim`](srcs/strings/ft_strtrim.c)
> Allocates (with malloc(3)) and returns a copy of the input string without
> the set's characters at the beginning and at the end.
> Returns NULL if allocation fails.

#### [`ft_substr`](srcs/strings/ft_substr.c)
> Allocates (with malloc(3)) and returns a substring from the original string.
> This new string starts at the input index.
> Returns NULL if allocation fails.

#### [`get_abs`](srcs/math/get_abs.c)
> Returns the absolute value of an integer.

#### [`get_max`](srcs/math/get_max.c)
> Returns the biggest number between two integers.

#### [`index_of`](srcs/strings/index_of.c)
> Returns the index of the first matching character occurence.
> If the character isn't found, it returns -1.

#### [`abs_index`](srcs/strings/abs_index.c)
> Returns the index of the first matching character occurence in a null-terminated string.
> If the character isn't found, it returns the length of the string.

#### [`ft_log`](srcs/math/ft_log.c)
> The log function.

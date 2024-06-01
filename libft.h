/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcaro-lo <jcaro-lo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 18:38:16 by jcaro-lo          #+#    #+#             */
/*   Updated: 2024/06/01 19:10:17 by jcaro-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/* ft_isapha check if the character is alphabetic */
int		ft_isalpha(int c);

/* ft_isdigit check if the character is a number */
int		ft_isdigit(int c);

/* ft_isalnum heck if the character is alphanumeric */
int		ft_isalnum(int c);

/*The isascii() function tests for an ASCII character, which is any charac-
	ter between 0 and octal 0177 inclusive.*/
int		ft_isascii(int c);

/*The isprint() function tests for any printing character, including space.
	The value of the argument must be representable as an unsigned char or 
	the value of EOF.*/
int		ft_isprint(int c);

/* ft_streln returns the lenth of the string */
int		ft_strlen(const char *s);

/*The memset() function writes len bytes of value c (converted to an unsigned
	char) to the string b. The memset() function returns its first argument*/
void	*ft_memset(void *b, int c, size_t len);

/*The bzero() function writes n zeroed bytes to the string s.  If n is
	zero, bzero() does nothing.*/
void	ft_bzero(void *s, size_t n);

/*The memcpy() function copies n bytes from memory area src to memory area dst.
    If dst and src overlap, behavior is undefined.  Applications in which dst
    and src might overlap should use memmove(3) instead.*/
void	*ft_memcpy(void *dst, const void *src, size_t n);

/*The memmove() function copies len bytes from string src to string dst.  
    The two strings may overlap; the copy is always done in a non-destructive
    manner. The memmove() function returns the original value of dst.*/
void	*ft_memmove(void *dest, const void *src, size_t n);

/*strlcpy() copies up to dstsize - 1 characters from the string src to dst, 
	NUL-terminating the result if dstsize is not 0.*/
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

/*strlcat() appends string src to the end of dst.  It will append at most 
    dstsize - strlen(dst) - 1 characters.  It will then NUL-terminate, 
    unless dstsize is 0 or the original dst string was longer than dstsize
    (in practice this should not happen as it means that either dstsize 
    is incorrect or that dst is not a*/
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

/* ft_toupper convert a character from lowercase to uppercase */
int		ft_toupper(int c);

/* ft_tolower convert a character from uppercase to lowercase */
int		ft_tolower(int c);

/*The strchr() function locates the first occurrence of c (converted to a
	char) in the string pointed to by s.*/
char	*ft_strchr(const char *s, int c);

/*The strrchr() function is 
	identical to strchr(), except it locates the last occurrence of c.*/
char	*ft_strrchr(const char *s, int c);

/*The strcmp() and strncmp() functions lexicographically compare the 
	null-terminated strings s1 and s2.*/
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/*The memchr() function locates the first occurrence of c (converted 
	to an unsigned char) in string s.*/
void	*ft_memchr(const void *s, int c, size_t n);

/*The memcmp() function compares byte string s1 against byte string s2.  
	Both strings are assumed to be n bytes long.*/
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/*The strnstr() function locates the first occurrence of the null-termi-
	nated string needle in the string haystack, where not more than len char-
	acters are searched.  Characters that appear after a `\0' character are
	not searched.*/
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

/*The atoi() function converts the initial portion of the string pointed to
	by str to int representation.*/
int		ft_atoi(const char *str);

/*The calloc() function contiguously allocates enough space for count objects 
 	that are size bytes of memory each and returns a pointer to the allocated
	memory.  The allocated memory is filled with bytes of value zero. This 
	function return a pointer to allocated memory.*/
void	*ft_calloc(size_t count, size_t size);

/*The strdup() function allocates enough memory for a copy of the string
	s1, does the copy, and returns a pointer to it.*/
char	*ft_strdup(const char *s1);

/*Reserve (with malloc(3)) and return a substring of the string 's'.
	The substring starts from the index 'start' and has a maximum length 
	'len'.*/
char	*ft_substr(const char *s, unsigned int start, size_t len);

/*Reserve (with malloc(3)) and return a new string, formed by the 
	concatenation of 's1' and 's2'. 
	's1': the first string.
	's2': the string to add to 's1'.
	Return: the new string 'res' or 'NULL' if memory reservation fails.*/
char	*ft_strjoin(const char *s1, const char *s2);

/*Remove all characters of the string set
	from the beginning and from the end of s1. It returns a copy of
	the resulting string*/
char	*ft_strtrim(const char *s1, const char *set);

/*Using malloc(3), generate a string that represent the integer value 
	received as an argument. Negative numbers have to be managed. 
	n: the integer to convert. Return value: the string representing the 
	number or NULL if the memory reservation fails.*/
char	*ft_itoa(int n);

/*To each character of the string 's', apply the function 'f' giving as 
	parameters the index of each character inside 's' and the character
	itself. Generate a new string with the result of successive use
	of 'f'. Parameters -> s: The string to iterate, f: The function to 
	apply on each character. Return value: the string created after the
	correct use of 'f' over each character or NULL if memory reservation
	fails.*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/*Applies the function f to each character of the string passed as argument, 
    and passing its index as first argument. Each character is passed by 
    address to f to be modified if necessary.*/
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

/*Outputs the character c to the given file descriptor.*/
void	ft_putchar_fd(char c, int fd);

/*Outputs the string s to the given file descriptor.*/
void	ft_putstr_fd(char *s, int fd);

/*Send the string 's' to the given file descriptor, followed by a line break.*/
void	ft_putendl_fd(char *s, int fd);

/*Outputs the integer 'n' to the given file descriptor.*/
void	ft_putnbr_fd(int n, int fd);

/*Reserve (using malloc(3)) an array of strings resulting from separating 
	the string 's' into substrings using the character 'c' as a delimiter. 
	the array must be terminated with a NULL pointer.*/
char	**ft_split(char const *s, char c);

/*Create a new node using malloc(3). The member variable 'content' is 
	initialized with the content of the 'content' parameter. The variable
	'next', with NULL. Content parameter: the content with which to create 
	the node. Return value: the new node*/
t_list	*ft_lstnew(void *content);

/*Add the 'new' node to the beginning of the 'lst' list.
	lst: the address of a pointer to the first node a list. 
	new: a pointer to the node to add to the beginning of the list.*/
void	ft_lstadd_front(t_list **list, t_list *new);

/*Counts the number of nodes in a list. 
	lst parameters: the beginning of the list. 
	Return value: The length of the list.*/
int		ft_lstsize(t_list *lst);

/*Returns the last node in the list.
	lst parameters: the beginning of the list.
	Return value: Last node in the list.*/
t_list	*ft_lstlast(t_list *lst);

/*Add the 'new' node to the end of the 'lst' list.
	lst: The pointer to the first node in a list.
	new: The pointer to a node to add to the list.
	Return value Nothing*/
void	ft_lstadd_back(t_list **lst, t_list *new);

/*This function takes a list element as parameter and deletes
	its content as well as free the allocated memory using the
	del function passed as parameter too*/
void	ft_lstdelone(t_list *lst, void (*del)(void *));

/*This function works similarly as the ft_lstelone function,
	but instead of removing only one element, it removes the
	element passed as parameter as well as all the following elements.*/
void	ft_lstclear(t_list **lst, void (*del)(void *));

/*This function iterates over the whole list and applies the fucntion f
	to the content of each element*/
void	ft_lstiter(t_list *lst, void (*f)(void *));

/*This function works similartly as the ft_lstiter function,
	but it creates a new list resulting of the succesive applications
	of f on each element's content*/
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
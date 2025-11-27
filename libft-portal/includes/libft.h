/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdestruh <rdestruh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 18:49:49 by rdestruh          #+#    #+#             */
/*   Updated: 2025/11/27 15:01:06 by rdestruh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include "other.h"
# include "ft_math.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

// ----------------------------- Mandatory part -------------------------------
/**
 * @brief Convert a string to an integer.
 * 
 * @param nptr String to convert
 * 
 * @return The converted integer
 */
int		ft_atoi(const char *nptr);
/**
 * @brief Set N bytes of S to 0.
 * 
 * @param s Memory space to fill
 * @param n Quantity of bytes to fill
 * 
 * @return Nothing
 */
void	ft_bzero(void *s, size_t n);
/**
 * @brief Allocate NMEMB elements of SIZE bytes each, all initialized to 0.
 * 
 * @param nmemb Quantity of elements to allocate
 * @param size Size of the elements to allocate
 * 
 * @return Pointer to the allocated memory
 */
void	*ft_calloc(size_t nmemb, size_t size);
/**
 * @brief Checks if the int passed is in the ascii range for alphanumerical 
 * characters.
 * 
 * @param c The int to check
 * 
 * @return 1 if c is in the range, 0 otherwise
 */
int		ft_isalnum(int c);
/**
 * @brief Checks if the int passed is in the ascii range for alphabetical 
 * characters.
 * 
 * @param c The int to check
 * 
 * @return 1 if c is in the range, 0 otherwise
 */
int		ft_isalpha(int c);
/**
 * @brief Checks if the int passed is in the ascii range.
 * 
 * @param c The int to check
 * 
 * @return 1 if c is in the range, 0 otherwise
 */
int		ft_isascii(int c);
/**
 * @brief Checks if the int passed is in the ascii range for numbers.
 * 
 * @param c The int to check
 * 
 * @return 1 if c is in the range, 0 otherwise
 */
int		ft_isdigit(int c);
/**
 * @brief Checks if the int passed is in the ascii range for printable 
 * characters.
 * 
 * @param c The int to check
 * 
 * @return 1 if c is in the range, 0 otherwise
 */
int		ft_isprint(int c);
/**
 * @brief Convert an integer to a string.
 * 
 * @param n The int to convert
 * 
 * @return The converted string
 */
char	*ft_itoa(int n);
/**
 * @brief Scans the initial N bytes of the memory area pointed by S for the 
 * first instance of C.
 * 
 * @param s The memory area to scan
 * @param c The value to search
 * @param n Quantity of bytes to search
 * 
 * @return Pointer to the first instance of C, or NULL
 */
void	*ft_memchr(const void *s, int c, size_t n);
/**
 * @brief Compares the first N bytes of the memory areas S1 and S2.
 * 
 * @param s1 First memory area to compare
 * @param s2 Second memory area to compare
 * @param n Quantity of bytes to compare
 * 
 * @return Difference between the first differing byte in s1 and s2, or 0.
 */
int		ft_memcmp(const void *s1, const void *s2, size_t n);
/**
 * @brief Copies N bytes from memory area SRC to memory area DEST.
 * @warning The memory area must not overlap
 * 
 * @param dest Memory area that takes the copy
 * @param src Memory area that is copied
 * @param n Quantity of bytes to copy
 * 
 * @return Pointer to dest
 */
void	*ft_memcpy(void *dest, const void *src, size_t n);
/**
 * @brief Copies N bytes from memory area SRC to memory area DEST.
 * 
 * @param dest Memory area that takes the copy
 * @param src Memory area that is copied
 * @param n Quantity of bytes to copy
 * 
 * @return Pointer to dest
 */
void	*ft_memmove(void *dest, const void *src, size_t n);
/**
 * @brief Fills the first n bytes of the memory area pointed to by S with the 
 * constant byte C.
 * 
 * @param s Memory area to fill
 * @param c Value to fill the memory with
 * @param n Quantity of bytes to fill
 * 
 * @brief Pointer to s
 */
void	*ft_memset(void *s, int c, size_t n);
/**
 * @brief Put a char C in the fd FD
 * 
 * @param c Char to put in the fd
 * @param fd Fd that will take c
 * 
 * @return Nothing
 */
void	ft_putchar_fd(char c, int fd);
/**
 * @brief Put a string S and a \n in the fd FD
 * 
 * @param s String to put in the fd
 * @param fd Fd that will take s and the \n
 * 
 * @return Nothing
 */
void	ft_putendl_fd(char *s, int fd);
/**
 * @brief Put a number n in the fd FD
 * 
 * @param n String to put in the fd
 * @param fd Fd that will take n
 * 
 * @return Nothing
 */
void	ft_putnbr_fd(int n, int fd);
/**
 * @brief Put a string S in the fd FD
 * 
 * @param s String to put in the fd
 * @param fd Fd that will take s
 * 
 * @return Nothing
 */
void	ft_putstr_fd(char *s, int fd);
/**
 * @brief Splits a string S into multiple substrings with C as a separator.
 * 
 * @param s string to split
 * @param c separator
 * 
 * @return Allocated array of strings
 */
char	**ft_split(char const *s, char c);
/**
 * @brief Returns a pointer to the first occurence of the character C in the 
 * string S.
 * 
 * @param s The string to scan
 * @param c The value to search
 * 
 * @return Pointer to the first occurence of C, or NULL
 */
char	*ft_strchr(const char *s, int c);
/**
 * @brief Returns a pointer to a new string which is a duplicate of the 
 * string S.
 * 
 * @param s String to duplicate
 * 
 * @return Pointer to the duplicated string
 */
char	*ft_strdup(const char *s);
/**
 * @brief Applies the function F on each character of the string S, passing 
 * its index as first argument.
 * 
 * @param s String to be modified
 * @param f Function to apply to S
 * 
 * @return Nothing
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
/**
 * @brief Concatenates S1 and S2 into a new string.
 * 
 * @param s1 First string to concatenate
 * @param s2 Second string to concatenate
 * 
 * @return Pointer to the concatenated string
 */
char	*ft_strjoin(char const *s1, char const *s2);
/**
 * @brief Concatenates DST and SRC into DST, assuring that DST is NULL-
 * terminated.
 * 
 * @param dst String to concatenate to
 * @param src String to concatenate in DST
 * @param size Size of DST
 * 
 * @return Size of the concatenated string
 */
size_t	ft_strlcat(char *dst, const char *src, size_t size);
/**
 * @brief Copies SRC in DST, assuring that DST is NULL-terminated.
 * 
 * @param dst String to copy to
 * @param src String to copy in DST
 * @param size Size of DST
 * 
 * @return Size of the copied string
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
/**
 * @brief Calculates the length of the string S.
 * 
 * @param s String to mesure
 * 
 * @return Length of S
 */
size_t	ft_strlen(const char *s);
/**
 * @brief Applies the function F to each character of the string S, putting 
 * the result in a new allocated string;
 * 
 * @param s String to be read
 * @param f Function to apply to S
 * 
 * @return Pointer to the new allocated string
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
/**
 * @brief Compares the first N characters of two strings S1 and S2.
 * 
 * @param s1 First string to compare
 * @param s2 Second string to compare
 * @param n Quantity of characters to compare
 * 
 * @return Difference between the first differing character in s1 and s2, or 0.
 */
int		ft_strncmp(const char *s1, const char *s2, size_t n);
/**
 * @brief Locates the first occurence of LITTLE in BIG, where not more than 
 * LEN characters are searched.
 * 
 * @param big String to scan
 * @param little String to search in BIG
 * @param len Max quantity of characters to scan
 * 
 * @return Pointer to the first occurence of LITTLE in BIG, or NULL
 */
char	*ft_strnstr(const char *big, const char *little, size_t len);
/**
 * @brief Returns a pointer to the last occurence of the character C in the 
 * string S.
 * 
 * @param s The string to scan
 * @param c The value to search
 * 
 * @return Pointer to the last occurence of C, or NULL
 */
char	*ft_strrchr(const char *s, int c);
/**
 * @brief Allocates and returns a copy of S1 with the characters specified in 
 * SET removed from the beginning and the end of the string.
 * 
 * @param s1 String to copy and trim
 * @param set String containing the charset to trim
 * 
 * @return Pointer to the allocated trimmed copy of s1
 */
char	*ft_strtrim(char const *s1, char const *set);
/**
 * @brief Allocates and returns a substring from the string S. The substring 
 * begins at index START and is of maximum size LEN.
 * 
 * @param s String to get a substring from
 * @param start Start index of the substring
 * @param len Max length of the substring
 * 
 * @return Pointer to the allocated substring
 */
char	*ft_substr(char const *s, unsigned int start, size_t len);
/**
 * @brief Returns the lowercase version of C.
 * 
 * @param c Value to get in lowercase
 * 
 * @return Lowercase version of C
 */
int		ft_tolower(int c);
/**
 * @brief Returns the uppercase version of C.
 * 
 * @param c Value to get in uppercase
 * 
 * @return Uppercase version of C
 */
int		ft_toupper(int c);
/**
 * @brief Copies the string pointed by src to the buffer pointed by dest.
 * 
 * @param dst String to copy to
 * @param src String to copy in dst
 * 
 * @return Pointer to dest
 */
char	*strcpy(char *dest, const char *src);

// ------------------------------- Bonus part -------------------------------

/**
 * @brief Allocates and returns a new node.
 * 
 * The member variable CONTENT is initialized with the value of the parameter 
 * CONTENT. The variable NEXT is initialized to NULL.
 * 
 * @param content Variable to assign to the content of the new node
 * 
 * @return Pointer to the new node
 */
t_list	*ft_lstnew(void *content);
/**
 * @brief Adds the node NEW at the begining of the list LST.
 * 
 * @param lst List that will take the node NEW
 * @param new Node to add to the list LST
 * 
 * @return Nothing
 */
void	ft_lstadd_front(t_list **lst, t_list *new);
/**
 * @brief Counts the number of nodes in the list LST
 * 
 * @param lst List to mesure
 * 
 * @return Number of nodes in LST
 */
int		ft_lstsize(t_list *lst);
/**
 * @brief Returns the last node of the list LST
 * 
 * @param lst List to get the last node from
 * 
 * @return Pointer to the last node of the list
 */
t_list	*ft_lstlast(t_list *lst);
/**
 * @brief Adds the node NEW at the end of the list LST.
 * 
 * @param lst List that will take the node NEW
 * @param new Node to add to the list LST
 * 
 * @return Nothing
 */
void	ft_lstadd_back(t_list **lst, t_list *new);
/**
 * @brief Frees the memory of the node's LST content using DEL and frees the 
 * node.
 * 
 * @param lst Node to free
 * @param del Function used to delete the content of the node
 * 
 * @return Nothing
 */
void	ft_lstdelone(t_list *lst, void (*del)(void *));
/**
 * @brief Deletes and frees the given node LST and every successor of that 
 * node, using DEL and free(3).
 * 
 * @param lst First node to free
 * @param del Function used to delete the content of the node
 * 
 * @return Nothing
 */
void	ft_lstclear(t_list **lst, void (*del)(void *));
/**
 * @brief Iterates the list LST and applies the function F on the content 
 * of each node.
 * 
 * @param lst First node of the list to iterate on
 * @param f Function used to iterate on LST
 * 
 * @return Nothing
 */
void	ft_lstiter(t_list *lst, void (*f)(void *));
/**
 * @brief Iterates the list LST and applies the function F on the content 
 * of each node.
 * 
 * Creates a new list resulting of the successive applications of F. The 
 * DEL function is used to delete the ocntent of a node if needed.
 * 
 * @param lst First node of the list to iterate on
 * @param f Function used to iterate on LST
 * @param del Function used to delete the content of a node
 * 
 * @return The new list, or NULL
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/**
 * @brief Prints a formatted string in a chosen file descriptor.
 * 
 * @param fd File descriptor
 * @param s Main string
 * @param ... Arguments to use and format into the string
 * 
 * @return Number of characters printed
 */
int		ft_dprintf(int fd, const char *s, ...);

/**
 * @brief Prints a formatted string in the stdout.
 * 
 * @param s Main string
 * @param ... Arguments to use and format into the string
 * 
 * @return Number of characters printed
 */
int		ft_printf(const char *s, ...);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

/**
 * @brief Returns a line read from a file descriptor FD.
 * 
 * @brief fd file descriptor to read from
 * 
 * @return Pointer to the read line, or NULL
 */
char	*get_next_line(int fd);

#endif
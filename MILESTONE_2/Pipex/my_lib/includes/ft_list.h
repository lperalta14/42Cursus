#ifndef FT_LIST_H
# define FT_LIST_H

# include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/****************************************/
/*				ft_list					*/
/****************************************/

/**
 * @brief Adds the element 'new' at the end of the list.
 *
 * @param lst The address of a pointer to the first link of a list.
 * @param new The address of a pointer to the element to be added to the list.
 */
void	ft_lstadd_back(t_list **lst, t_list *new);

/**
 * @brief Adds the element 'new' at the beginning of the list.
 *
 * @param lst The address of a pointer to the first link of a list.
 * @param new The address of a pointer to the element to be added to the list.
 */
void	ft_lstadd_front(t_list **lst, t_list *new);

/**
 * @brief Deletes and frees the given element and every successor of that element,
 * using the function 'del' and free().
 *
 * @param lst The address of a pointer to an element.
 * @param del The address of the function used to delete the content.
 */
void	ft_lstclear(t_list **lst, void (*del)(void *));

/**
 * @brief Takes as a parameter an element and frees the memory of the element’s
 * content using the function 'del' given as a parameter and free().
 *
 * @param lst The element to free.
 * @param del The address of the function used to delete the content.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void*));

/**
 * @brief Iterates the list 'lst' and applies the function 'f' to the content of each element.
 *
 * @param lst The address of a pointer to an element.
 * @param f The address of the function used to iterate on the list.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *));

/**
 * @brief Returns the last element of the list.
 *
 * @param lst The beginning of the list.
 * @return t_list* The last element of the list, or NULL if the list is empty.
 */
t_list	*ft_lstlast(t_list *lst);

/**
 * @brief Iterates the list 'lst' and applies the function 'f' to the content of each element.
 * Creates a new list resulting from the successive applications of 'f'. The 'del' function
 * is used to delete the content of an element if needed.
 *
 * @param lst The address of a pointer to an element.
 * @param f The address of the function used to iterate on the list.
 * @param del The address of the function used to delete the content if needed.
 * @return t_list* The new list, or NULL if the allocation fails.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/**
 * @brief Allocates (with malloc) and returns a new element. The variable 'content'
 * is initialized with the value of the parameter 'content'. The variable 'next' is initialized to NULL.
 *
 * @param content The content to create the new element with.
 * @return t_list* The new element.
 */
t_list	*ft_lstnew(void *content);

/**
 * @brief Counts the number of elements in a list.
 *
 * @param lst The beginning of the list.
 * @return int The length of the list.
 */
int		ft_lstsize(t_list *lst);

#endif
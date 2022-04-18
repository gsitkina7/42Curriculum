/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahertha <ahertha@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 00:43:41 by ahertha           #+#    #+#             */
/*   Updated: 2022/04/07 19:52:09 by ahertha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_list
{
	int				num;
	struct s_list	*next;
}	t_list;

int			ft_isdigit(int c);
long int	ft_atoi(const char *str);
char		**ft_split(char const *s, char c);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstnew(int content);
void		ft_lstdelone(t_list *lst);
void		ft_lstclear(t_list **lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*get_next_line(int fd);
char		*read_into_buffer(int fd, char *remainder);
char		*find_line_to_return(char *remainder);
char		*update_remainder(char *remainder);
char		*ft_strchr(char *s, char c);
char		*ft_strjoin(char *s1, char *s2);
size_t		ft_strlen(const char *s);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaythaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 12:19:57 by mmaythaw          #+#    #+#             */
/*   Updated: 2023/02/11 12:50:17 by mmaythaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../ft_printf/ft_printf_bonus.h"
# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 5
# define INT_MAX 2147483647

typedef struct s_stack
{
	int				num;
	int				chunk;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

t_stack	**stack_init(int len);

void	o_p(t_stack **src, t_stack **dst);
void	o_s(t_stack *top);
void	o_r(t_stack	**top);
void	o_rr(t_stack **new_top);
void	free_stack(t_stack **s);
void	free_arr(char **arr);
void	format_error(char **arr, int flag);
void	stack_error(t_stack **s, char *line, int flag);
void	check_result(t_stack **a, t_stack **b, char *line);

char	*get_next_line(int fd);
char	*gnlstrchr(char *s, int c);
char	*gnlstrjoin(char *str, char *buffer);
char	*remove_prev_line(char *s);
char	*ft_readline(int fd, char *str);
char	*ft_getline(char *s);

long	ft_atol(const char *str);

int		is_sorted(t_stack *s);
int		stack_len(t_stack *s);
int		is_dup(char **arr, int flag);

#endif

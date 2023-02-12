/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaythaw <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 13:39:49 by mmaythaw          #+#    #+#             */
/*   Updated: 2023/02/11 13:29:22 by mmaythaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../ft_printf/ft_printf_bonus.h"
# include "../ft_printf/libft/libft.h"

# define INT_MAX 2147483647
# define CHUNKONE 10
# define CHUNKFIVE 13

typedef struct s_stack
{
	int				num;
	int				chunk;
	struct s_stack	*next;
	struct s_stack	*prev;
}			t_stack;

t_stack	**stack_init(int len);
t_stack	*find_max(t_stack **s);
t_stack	*find_min(t_stack **s);
t_stack	*find_bottom(t_stack **s);

void	o_p(t_stack **src, t_stack **dst);
void	o_s(t_stack *top);
void	o_r(t_stack **top);
void	o_rr(t_stack **new_top);
void	free_stack(t_stack **s);
void	free_arr(char **arr);
void	format_error(char **arr, int flag);
void	stack_error(void);
void	quick_sort_arr(char **arr, int start, int end, int i);
void	parse_chunk(t_stack **a, char **arr, int len, int start);
void	sort_stack(t_stack **a, int len);
void	hundred_sort(t_stack **a, int len_a);
void	sort_onehund(t_stack **a, t_stack **b, int len_a, int chunknum);
void	sort_fivehund(t_stack **a, t_stack **b, int len_a, int chunknum);
void	place(t_stack **a, t_stack **b, t_stack *marker, int len_a);
void	same_rotate(t_stack **a, t_stack **b, int da, int db);
void	same_rrotate(t_stack **a, t_stack **b, int da, int db);
void	aubl_rotate(t_stack **a, t_stack **b, int da, int db);
void	albu_rotate(t_stack **a, t_stack **b, int da, int db);

long	ft_atol(const char *str);

int		ft_isspace(char c);
int		is_sorted(t_stack *s);
int		stack_len(t_stack *s);
int		is_dup(char **arr, int flag);
int		get_da(t_stack *a);
int		get_db(t_stack *b, int a_num, int len_b);

#endif

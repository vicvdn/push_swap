/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvaudain <vvaudain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:57:36 by vvaudain          #+#    #+#             */
/*   Updated: 2024/02/06 12:30:08 by vvaudain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_ops
{
	int	sa;
	int	sb;
	int	ss;
	int	pa;
	int	pb;
	int	ra;
	int	rb;
	int	rr;
	int	rra;
	int	rrb;
	int	rrr;
	int	total;
}		t_ops;

typedef struct s_dist
{
	int	data;
	int	distance;
}		t_dist;

typedef struct s_node
{
	int				data;
	struct s_node	*pivot;
	t_ops			*op_count;
	t_dist			*dist;
	struct s_node	*prev;
	struct s_node	*next;
}			t_node;

typedef struct s_dlist
{
	size_t	len;
	t_node	*tail;
	t_node	*head;
}			t_dlist;

typedef struct s_data
{
	t_dlist	*stack_a;
	t_dlist	*stack_b;
	char	**values;
	int		splitted;
}			t_data;

/*TO REMOVE*/

// void	print_list(t_node **head);
// void	print_node(t_node *node);
// void	print_struct(t_ops *ops);

/*Cleaning functions*/

void	ft_free_tab(char **tab);
void	free_node(t_node *node);
void	ft_free_all(t_data *data);

/*List utils*/

t_node	*find_last_node(t_node **head);
void	ft_free_stack(t_node **head, t_node **tail);
t_node	*create_node(int nb, t_data *data);
void	insert_end(t_node **head, t_node **tail, int nb, t_data *data);
void	create_stacks(t_data *data);

/*Operations*/

void	ra(t_data *data);
void	rb(t_data *data);
void	rr(t_data *data);
void	rotate(t_dlist *stack, t_node **head, t_node **tail, t_data *data);
void	rra(t_data *data);
void	rrb(t_data *data);
void	rrr(t_data *data);
void	rev_rotate(t_dlist *stack, t_node **head, t_node **tail, t_data *data);
void	pa(t_data *data);
void	pb(t_data *data);
void	push(t_node **head_from, t_node **head_to, t_data *data);
void	sa(t_data *data);
void	sb(t_data *data);
void	ss(t_data *data);
void	swap(t_node **head);

/*Algorithm utils*/

/*cost functions - algorithm utils*/

void	update_rr(t_node *node);
void	update_rrr(t_node *node);
void	update_ss(t_node *node);
void	update_total(t_node *node);
t_node	*find_cheapest_cost(t_node **head);

/*utils 3*/

int		ft_abs(int nb);
int		get_max(t_node **head);
int		compute_min(t_node **head);

/*utils 2*/

int		is_min(int node_data, t_node **head);
int		ft_min(int nb1, int nb2);
void	make_rotations(t_node *cheapest_node, t_data *data);
void	make_rev_rotations(t_node *cheapest_node, t_data *data);
void	make_push(t_node *cheapest_node, t_data *data);

/*utils 1*/
void	init_op_count(t_ops *op_count);
void	update_cost(t_node *node, t_node *pivot);
t_node	*get_pivot(t_dlist *stack, int nb);
int		get_pos(t_node **head, t_node *node);
int		get_middle(int len);

/*push back*/

void	max_to_top(t_node *max, t_data *data);
void	find_target(t_dlist *stack_a, t_dlist *stack_b, t_node *node);
// void	max_in_a(t_data *data, t_node **tail);
// void	max_in_b(t_data *data);
void	target_to_top(t_node *node, t_data *data);
void	push_back(t_node **head, t_data *data);

/*Algorithm functions*/

void	compute_distance(t_node *node, t_data *data);
void	cost_to_head(t_node *node, int pos, t_dlist *stack, t_data *data);
void	compute_cost(t_node *node, t_data *data);
void	push_cheapest(t_node **head, t_data *data);
void	ft_sorting_algo(t_data *data);

/*Sorting*/

int		is_sorted(t_node **head);
int		find_min(t_node **head);
int		find_max(t_node **head);
void	mini_sort(t_dlist *stack, t_node **head, t_data *data);
void	ft_sort(t_data *data);

/*Parsing*/

void	ft_error(int error_num);
int		ft_atol(const char *nptr);
int		nb_elements(char **values);
int		is_double(char **av, t_data *data);
int		nb_len(int nb);
int		ft_parse(int len, char **values, t_data *data, int i);
int		ft_parsing(int ac, char **av, t_data *data);

/*Main function*/

int		main(int ac, char **av);

#endif
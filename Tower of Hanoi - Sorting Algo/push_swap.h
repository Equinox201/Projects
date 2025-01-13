
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

/*****************************************************************************/
/*                                  STRUCTURE                                */
/*****************************************************************************/

typedef struct s_stack
{
	struct s_stack	*previous;
	int				number;
	int				position;
	int				sorted;
	int				c_rot;
	int				c_rev;
	int				big_t;
	int				trgt;
	int				t_dir;
	int				t_com;
	int				cost;
	int				nts;
	struct s_stack	*next;
}					t_stk;

/*****************************************************************************/
/*                                  FUNCTIONS                                */
/*****************************************************************************/

// Parsing & Data validation
int					ft_isdigit(char a, char b);
long				ft_atol(const char *str);
t_stk				*ft_data_validation(char **arguments, t_stk *a_head,
						int size);
t_stk				*ft_init_stack_a(char **arguments, int size);
int					ft_strlen(char *str);

// Find Order
void				ft_sort_list(t_stk *head);
void				ft_sorted_order(t_stk *head, int *array, int size);
void				ft_bubble_sort(int *array, int size);
void				ft_bbswap(int *a, int *b);

// Assign values
void				ft_position(t_stk *head);
void				ft_initial_order(t_stk *head);
void				ft_sort_list(t_stk *head);
void				ft_assign_cost(t_stk *head);
void				ft_big_three(t_stk *head);
void				ft_refresh_pc(t_stk *a_stack, t_stk *b_stack);

// Linked List Related
int					ft_lstsize(t_stk *lst);
void				ft_lstclear(t_stk **lst);
void				ft_delnode(t_stk *node);
t_stk				*ft_lstnew(int number);
void				ft_add_new_node(t_stk **head, int number);

// Operations
void				ft_sort_two(t_stk *a_stack);
void				ft_sort_three_num(t_stk **a_stack, t_stk **b_stack);
void				ft_invert_three_num(t_stk **a_stack, t_stk **b_stack);
void				ft_push_all_save_three(t_stk **a_stack, t_stk **b_stack);
void				ft_common_moves(t_stk *current, int c_cur, int c_src,
						int trigger);
int					ft_comp(t_stk *current);
void				ft_targeting(t_stk **a_stack, t_stk **b_stack);
void				ft_set_target(t_stk **head, t_stk **other);
void				ft_set_cost(t_stk *current, t_stk **other);
void				ft_find(t_stk **a_stack, t_stk **b_stack, int sorted,
						int c);
t_stk				*ft_cost_com_ratio(t_stk **head);
void				ft_optimized_push(t_stk **a_stack, t_stk **b_stack);
t_stk				*ft_find_target(t_stk **head, int target);
int					ft_high(t_stk **head);
void				ft_push_back(t_stk **a_stack, t_stk **b_stack);
void				ft_first(t_stk *temp, t_stk **other);

// Basic Moves
void				push(t_stk **a_stack, t_stk **b_stack, int i, int c);
void				pa(t_stk **a_head, t_stk **b_head);
void				pb(t_stk **a_head, t_stk **b_head);

void				reverse_rotate(t_stk **a_stack, t_stk **b_stack, int i,
						int c);
void				rra(t_stk **head);
void				rrb(t_stk **head);
void				rrr(t_stk **a_stack, t_stk **b_stack);

void				rotate(t_stk **a_stack, t_stk **b_stack, int i, int c);
void				ra(t_stk **head);
void				rb(t_stk **head);
void				rr(t_stk **a_stack, t_stk **b_stack);

void				swap(t_stk **a_stack, t_stk **b_stack, int c);
void				sa(t_stk **head);
void				sb(t_stk **head);
void				ss(t_stk **a_head, t_stk **b_head);

#endif

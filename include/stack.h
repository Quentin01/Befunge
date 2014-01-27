
/*
** stack.h for befunge in /home/buathi_q/Github/Befunge
** 
** Made by BUATHIER Quentin
** Login   <buathi_q@epitech.net>
** 
** Started on  Mon Jan 27 13:25:43 2014 BUATHIER Quentin
** Last update Mon Jan 27 17:33:07 2014 BUATHIER Quentin
*/

#ifndef STACK_H_
# define STACK_H_

typedef struct	s_stack	t_stack;

# include "befunge.h"

struct		s_stack
{
  TYPE_STACK	value;
  t_stack	*next;
};

int		push(t_stack **stack, TYPE_STACK value);
TYPE_STACK	pop(t_stack **stack);

#endif /* !STACK_H_ */

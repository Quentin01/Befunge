/*
** stack.h for befunge in /home/buathi_q/Github/Befunge
** 
** Made by BUATHIER Quentin
** Login   <buathi_q@epitech.net>
** 
** Started on  Mon Jan 27 13:25:43 2014 BUATHIER Quentin
** Last update Mon Jan 27 13:28:22 2014 BUATHIER Quentin
*/

#ifndef STACK_H_
# define STACK_H_

typedef struct	s_stack	t_stack;

struct		s_stack
{
  unsigned char	value;
  t_stack	*next;
};

int		push(t_stack **stack, unsigned char value);
unsigned char	pop(t_stack **stack);

#endif /* !STACK_H_ */

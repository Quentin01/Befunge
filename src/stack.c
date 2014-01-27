/*
** stack.c for befunge in /home/buathi_q/Github/Befunge
** 
** Made by BUATHIER Quentin
** Login   <buathi_q@epitech.net>
** 
** Started on  Mon Jan 27 13:27:54 2014 BUATHIER Quentin
** Last update Mon Jan 27 17:54:48 2014 BUATHIER Quentin
*/

#include <stdlib.h>
#include "stack.h"

int		push(t_stack **stack, TYPE_STACK value)
{
  t_stack	*new;

  if ((new = malloc(sizeof(*new))) == NULL)
    return (1);
  new->value = value;
  new->next = *stack;
  *stack = new;
  return (0);
}

TYPE_STACK	pop(t_stack **stack)
{
  t_stack	*temp;
  TYPE_STACK	value;

  if (!(*stack))
    return (0);
  temp = (*stack);
  value = temp->value;
  *stack = temp->next;
  free(temp);
  return (value);
}

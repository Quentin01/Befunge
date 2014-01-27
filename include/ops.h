/*
** ops.h for befunge in /home/buathi_q/Github/Befunge
** 
** Made by BUATHIER Quentin
** Login   <buathi_q@epitech.net>
** 
** Started on  Mon Jan 27 16:14:16 2014 BUATHIER Quentin
** Last update Mon Jan 27 16:52:04 2014 BUATHIER Quentin
*/

#ifndef OPS_H_
# define OPS_H_

# include "stack.h"
# include "grid.h"
# include "cursor.h"

typedef struct	s_op
{
  char		c;
  int		(*function)(t_stack **stack, t_grid *grid, t_cursor *cursor);
}		t_op;

int	add(t_stack**, t_grid*, t_cursor*);
int     sub(t_stack**, t_grid*, t_cursor*);
int     mul(t_stack**, t_grid*, t_cursor*);
int     divi(t_stack**, t_grid*, t_cursor*);
int     mod(t_stack**, t_grid*, t_cursor*);
int     not(t_stack**, t_grid*, t_cursor*);
int     gt(t_stack**, t_grid*, t_cursor*);
int     mvr(t_stack**, t_grid*, t_cursor*);
int     mvl(t_stack**, t_grid*, t_cursor*);
int     mvt(t_stack**, t_grid*, t_cursor*);
int     mvb(t_stack**, t_grid*, t_cursor*);
int     mva(t_stack**, t_grid*, t_cursor*);
int     condv(t_stack**, t_grid*, t_cursor*);
int     condh(t_stack**, t_grid*, t_cursor*);
int     dupl(t_stack**, t_grid*, t_cursor*);
int     swap(t_stack**, t_grid*, t_cursor*);
int     popv(t_stack**, t_grid*, t_cursor*);
int     display_int(t_stack**, t_grid*, t_cursor*);
int     display_char(t_stack**, t_grid*, t_cursor*);
int     load(t_stack**, t_grid*, t_cursor*);
int     store(t_stack**, t_grid*, t_cursor*);
int     input_int(t_stack**, t_grid*, t_cursor*);
int     input_char(t_stack**, t_grid*, t_cursor*);

#endif

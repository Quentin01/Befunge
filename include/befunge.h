/*
** befunge.h for befunge in /home/buathi_q/Github/Befunge
** 
** Made by BUATHIER Quentin
** Login   <buathi_q@epitech.net>
** 
** Started on  Mon Jan 27 13:53:50 2014 BUATHIER Quentin
** Last update Mon Jan 27 17:34:57 2014 BUATHIER Quentin
*/

#ifndef BEFUNGE_H_
# define BEFUNGE_H_

# define TYPE_STACK	long int
# define CUR_CHAR	grid->grid[cursor->y][cursor->x]

# include "stack.h"
# include "grid.h"
# include "cursor.h"

int	befunge(t_stack **stack, t_grid *grid, t_cursor *cursor);

#endif

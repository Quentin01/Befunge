/*
** befunge.c for befunge in /home/buathi_q/Github/Befunge
** 
** Made by BUATHIER Quentin
** Login   <buathi_q@epitech.net>
** 
** Started on  Mon Jan 27 13:43:13 2014 BUATHIER Quentin
** Last update Mon Jan 27 18:01:25 2014 BUATHIER Quentin
*/

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include "befunge.h"
#include "ops.h"

t_op    g_ops[] = {
  { '+', &add },
  { '-', &sub },
  { '*', &mul },
  { '/', &divi },
  { '%', &mod },
  { '!', &not },
  { '`', &gt },
  { '>', &mvr },
  { '<', &mvl },
  { '^', &mvt },
  { 'v', &mvb },
  { '?', &mva },
  { '_', &condv },
  { '|', &condh },
  { ':', &dupl },
  { '\\', &swap },
  { '$', &popv },
  { '.', &display_int },
  { ',', &display_char },
  { 'p', &load },
  { 'g', &store },
  { '&', &input_int },
  { '~', &input_char }
};

int	execute_op(char c, t_stack **stack, t_grid *grid, t_cursor *cursor)
{
  int	i;
  int	len;

  i = 0;
  len = sizeof(g_ops) / sizeof(t_op);
  while (i < len)
    {
      if (c == g_ops[i].c)
	return (g_ops[i].function(stack, grid, cursor));
      ++i;
    }
  printf("Error : Unknow op '%c' at %d, %d\n", c, cursor->x, cursor->y);
  return (1);
}

int		execute(t_stack **stack, t_grid *grid, t_cursor *cursor, int *in_string)
{
  static int	jump = 0;

  if (jump)
    jump = 0;
  else if (*in_string)
    {
      if (CUR_CHAR == '"')
	*in_string = 0;
      else
	push(stack, CUR_CHAR);
    }
  else
    {
      if (CUR_CHAR == '@')
	return (1);
      else if (CUR_CHAR >= '0' && CUR_CHAR <= '9')
	push(stack, CUR_CHAR - '0');
      else if (CUR_CHAR == '"')
	*in_string = 1;
      else if (CUR_CHAR == '#')
	jump = 1;
      else
	return (execute_op(CUR_CHAR, stack, grid, cursor));
    }
  return (0);
}

void		move_cursor(t_grid *grid, t_cursor *cursor, int in_string)
{
  int		diffx;
  int		diffy;

  diffx = diffy = 0;
  if (cursor->dir == BOTTOM)
    diffy = 1;
  else if (cursor->dir == TOP)
    diffy = -1;
  else if (cursor->dir == LEFT)
    diffx = -1;
  else if (cursor->dir == RIGHT)
    diffx = 1;
  do
    {
      if (diffx == -1 && cursor->x == 0)
	cursor->x = grid->width - 1;
      else if (diffx == 1 && cursor->x == grid->width - 1)
	cursor->x = 0;
      else if (diffy == -1 && cursor->y == 0)
	cursor->y = grid->height - 1;
      else if (diffy == 1 && cursor->y == grid->height - 1)
	cursor->y = 0;
      else
	{
	  cursor->x += diffx;
	  cursor->y += diffy;
	}
    } while ((CUR_CHAR == ' ' && !in_string) || CUR_CHAR == '\0');
}

int	befunge(t_stack **stack, t_grid *grid, t_cursor *cursor)
{
  int	in_string;

  in_string = 0;
  srand(time(NULL));
  if (!grid->grid[0][0] || grid->grid[0][0] == ' ')
    {
      printf("Error : No begin char at 0,0\n");
      return (1);
    }
  while (42)
    {
      if (execute(stack, grid, cursor, &in_string))
	return (1);
      move_cursor(grid, cursor, in_string);
    }
  return (0);
}

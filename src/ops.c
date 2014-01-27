/*
** ops.c for befunge in /home/buathi_q/Github/Befunge
** 
** Made by BUATHIER Quentin
** Login   <buathi_q@epitech.net>
** 
** Started on  Mon Jan 27 16:29:25 2014 BUATHIER Quentin
** Last update Mon Jan 27 17:56:34 2014 BUATHIER Quentin
*/

#include <stdlib.h>
#include <stdio.h>
#include "befunge.h"
#include "ops.h"

int		add(t_stack **stack, t_grid *grid, t_cursor *cursor) { push(stack, pop(stack) + pop(stack)); return (0); }

int		sub(t_stack **stack, t_grid *grid, t_cursor *cursor)
{
  TYPE_STACK	a, b;

  a = pop(stack);
  b = pop(stack);
  push(stack, b - a);
  return (0);
}

int		mul(t_stack **stack, t_grid *grid, t_cursor *cursor) { push(stack, pop(stack) * pop(stack)); return (0); }

int		divi(t_stack **stack, t_grid *grid, t_cursor *cursor)
{
  TYPE_STACK a, b;

  a = pop(stack);
  b = pop(stack);
  push(stack, b / a);
  return (0);
}

int		mod(t_stack **stack, t_grid *grid, t_cursor *cursor)
{
  TYPE_STACK	a, b;

  a = pop(stack);
  b = pop(stack);
  push(stack, b % a);
  return (0);
}

int		not(t_stack **stack, t_grid *grid, t_cursor *cursor) { push(stack, !pop(stack)); return (0); }

int		gt(t_stack **stack, t_grid *grid, t_cursor *cursor)
{
  TYPE_STACK	a, b;

  a = pop(stack);
  b = pop(stack);
  push(stack, (b > a));
  return (0);
}

int		mvr(t_stack **stack, t_grid *grid, t_cursor *cursor) { cursor->dir = RIGHT; return (0); }
int		mvl(t_stack **stack, t_grid *grid, t_cursor *cursor) { cursor->dir = LEFT; return (0); }
int		mvt(t_stack **stack, t_grid *grid, t_cursor *cursor) { cursor->dir = TOP; return (0); }
int		mvb(t_stack **stack, t_grid *grid, t_cursor *cursor) { cursor->dir = BOTTOM; return (0); }
int		mva(t_stack **stack, t_grid *grid, t_cursor *cursor) { cursor->dir = rand() % 4; return (0); }

int		condv(t_stack **stack, t_grid *grid, t_cursor *cursor)
{
  if (!pop(stack))
    mvr(stack, grid, cursor);
  else
    mvl(stack, grid, cursor);
  return (0);
}

int		condh(t_stack **stack, t_grid *grid, t_cursor *cursor)
{
  if (!pop(stack))
    mvb(stack, grid, cursor);
  else
    mvt(stack, grid, cursor);
  return (0);
}

int		dupl(t_stack **stack, t_grid *grid, t_cursor *cursor)
{
  TYPE_STACK	a;

  a = pop(stack);
  push(stack, a);
  push(stack, a);
  return (0);
}

int		swap(t_stack **stack, t_grid *grid, t_cursor *cursor)
{
  TYPE_STACK	a, b;

  a = pop(stack);
  b = pop(stack);
  push(stack, a);
  push(stack, b);
  return (0);
}

int		popv(t_stack **stack, t_grid *grid, t_cursor *cursor) { pop(stack); return (0); }

int		display_int(t_stack **stack, t_grid *grid, t_cursor *cursor)
{
  printf("%ld", pop(stack));
  fflush(stdout);
  return (0);
}

int		display_char(t_stack **stack, t_grid *grid, t_cursor *cursor)
{
  printf("%c", (char) pop(stack));
  fflush(stdout);
  return (0);
}

int		load(t_stack **stack, t_grid *grid, t_cursor *cursor)
{
  TYPE_STACK	x, y, v;

  y = pop(stack);
  x = pop(stack);
  v = pop(stack);
  if (x >= grid->width || y >= grid->height || x < 0 || y < 0)
    {
      printf("Error : Can't use 'p' with %d, %d\n", (int) x, (int) y);
      return (1);
    }
  grid->grid[y][x] = v;
  return (0);
}

int		store(t_stack **stack, t_grid *grid, t_cursor *cursor)
{
  TYPE_STACK	x, y;

  y = pop(stack);
  x = pop(stack);
  if (x >= grid->width || y >= grid->height || x < 0 || y < 0)
    {
      printf("Error : Can't use 'g' with %d, %d\n", (int) x, (int) y);
      return (1);
    }
  push(stack, (TYPE_STACK) grid->grid[y][x]);
  return (0);
}

int		input_int(t_stack **stack, t_grid *grid, t_cursor *cursor)
{
  int		a;

  scanf("%d", &a);
  push(stack, (TYPE_STACK) a);
  return (0);
}

int		input_char(t_stack **stack, t_grid *grid, t_cursor *cursor)
{
  char		a;

  a = getchar();
  push(stack, a);
  return (0);
}

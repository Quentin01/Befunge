/*
** main.c for befunge in /home/buathi_q/Github/Befunge
** 
** Made by BUATHIER Quentin
** Login   <buathi_q@epitech.net>
** 
** Started on  Mon Jan 27 13:24:19 2014 BUATHIER Quentin
** Last update Mon Jan 27 17:44:42 2014 BUATHIER Quentin
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "befunge.h"

int		parse_file(char *filename, t_grid *grid)
{
  unsigned int	i;
  FILE		*file;
  char		*buffer;
  size_t	len;

  i = 0;
  file = fopen(filename, "r");
  if (!file)
    return (1);
  if (fscanf(file, "%u %u\n", &(grid->width), &(grid->height)) != 2)
    {
      printf("Error : Bad first line in file\n");
      return (1);
    }
  if((grid->grid = malloc(sizeof(*grid->grid) * grid->height)) == NULL)
    {
      printf("Error : Cannot allocate memory\n");
      return (1);
    }
  buffer = NULL;
  len = 0;
  while (i < grid->height)
    {
      if ((grid->grid[i] = calloc(grid->width + 1, 1)) == NULL)
	{
	  printf("Error : Cannot allocate memory\n");
	  return (1);
	}
      if(getline(&buffer, &len, file) != -1)
	strncpy(grid->grid[i], buffer, grid->width);
      ++i;
    }
  free(buffer);
  fclose(file);
  return (0);
}

int		main(int ac, char **av)
{
  unsigned int	i;
  t_stack	*stack;
  t_grid	grid;
  t_cursor	cursor;

  if (ac == 2)
    {
      stack = NULL;
      cursor.x = 0;
      cursor.y = 0;
      cursor.dir = RIGHT;
      if (parse_file(av[1], &grid))
	return (1);
      befunge(&stack, &grid, &cursor);
      while (stack)
	pop(&stack);
      i = 0;
      while (i < grid.height)
	{
	  free(grid.grid[i]);
	  ++i;
	}
      free(grid.grid);
    }
  else
    printf("Usage : ./befunge file.bef\n");
  return (0);
}

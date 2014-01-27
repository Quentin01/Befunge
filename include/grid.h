/*
** grid.h for befunge in /home/buathi_q/Github/Befunge
** 
** Made by BUATHIER Quentin
** Login   <buathi_q@epitech.net>
** 
** Started on  Mon Jan 27 13:42:06 2014 BUATHIER Quentin
** Last update Mon Jan 27 14:35:38 2014 BUATHIER Quentin
*/

#ifndef GRID_H_
# define GRID_H_

typedef struct	s_grid
{
  unsigned int	width;
  unsigned int	height;
  char		**grid;
}		t_grid;

#endif /* !GRID_H_ */

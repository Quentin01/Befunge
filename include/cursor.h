/*
** cursor.h for befunge in /home/buathi_q/Github/Befunge
** 
** Made by BUATHIER Quentin
** Login   <buathi_q@epitech.net>
** 
** Started on  Mon Jan 27 13:39:44 2014 BUATHIER Quentin
** Last update Mon Jan 27 16:53:55 2014 BUATHIER Quentin
*/

#ifndef CURSOR_H_
# define CURSOR_H_

typedef enum e_dir { TOP = 0, BOTTOM = 1, LEFT = 2, RIGHT = 3 } t_dir;

typedef struct	s_cursor
{
  unsigned int	x;
  unsigned int	y;
  t_dir		dir;
}		t_cursor;

#endif /* !CURSOR_H_ */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blax <blax@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 11:13:47 by blax              #+#    #+#             */
/*   Updated: 2023/04/11 16:28:13 by blax             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct node
{
	char			*content;
	struct node *next;
} node;

typedef struct map
{
	char **tab;
	int nb_lines;
	int nb_columns;
	struct player *the_player;
} map;

typedef struct player
{
	int x;
	int y;
} player;

enum direction {
    UP = 1,
    RIGHT = 2,
    DOWN = 3,
	LEFT = 4
};

void ft_parse(char **map, int fd);
void ft_get_map();
void ft_free(char **map);
int is_map(char **tab, int lines, int colums);
void ft_error();

// (PARSING) FONCTIONS DE VALIDATION DE LA MAP
//ft_valid_map.c
int is_valid_elems(char **tab, int lines, int colums);
int is_exist_elem(char **tab, int lines, int colums, char letter);
int is_map_rectangle(char **tab, int lines, int colums);
int is_map_duplicates(char **tab, int lines, int colums, char letter);
int is_map_close(char **tab, int lines, int colums, char letter);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blax <blax@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 11:18:49 by blax              #+#    #+#             */
/*   Updated: 2023/04/02 17:54:26 by blax             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void ft_error(char *msg)
{
    ft_printf("Error\n");
    ft_printf(msg);
    return (EXIT_FAILURE);
}

void ft_parse(char **map, int fd)
{
    ft_get_map();
}

void ft_get_map()
{
    char **tab;
    int i;
    int j;

    i = 0;
    while (read != 0) //voir quelle condition mettre
    {
        tab[i] = get_next_line(fd);
        i++;
    }
    map = (char **) malloc(sizeof(char *) * i);
    j = 0;
    while (tab[0][j] != '\0')
        j++;
    if (is_map(tab, i, j))
    {
        map->lines = i;
        map->colums = j;
    }
    else
        ft_error();
}

void ft_free(char **map)
{
    int i;

    i = 0;
    while (i < map->lines)
    {
        free(map[i]);
        map[i] = NULL;
        i++;
    }
    free(map);
    map = NULL;
}

int is_map(char **tab, int lines, int colums)
{
    char msg[];

    msg = "";
    if (!is_map_rectangle(tab, lines, colums))
        msg = "Map is not rectangular !\n";
    if (!is_valid_elems(tab, lines, colums))
        msg = "Elements in the map is not correct !\n";
    if (!is_exist_elem(tab, lines, colums, 'E'))
        msg = "Element E is missing from the map !\n";
    if (!is_exist_elem(tab, lines, colums, 'P'))
        msg = "Element P is missing from the map !\n";
    if (!is_exist_elem(tab, lines, colums, 'C'))
        msg = "Element C is missing from the map !\n";
    if (is_map_doublons(tab, lines, colums, 'P'))
        msg = "Element P is double in the map !\n";
    if (!is_map_doublons(tab, lines, colums, 'E'))
        msg = "Element E is double in the map !\n";
    if (!is_map_close(tab, lines, colums, '1'))
        msg = "The map is not close !\n";
    if (msg != "")
    {
        ft_free(map);
        ft_error(msg);
    }
}


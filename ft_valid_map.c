/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blax <blax@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:45:06 by blax              #+#    #+#             */
/*   Updated: 2023/04/02 18:14:43 by blax             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int is_valid_elems(char **tab, int lines, int colums)
{
    int i;
    int j;


    i = 0;
    j = 0;
    while (i < lines)
    {
        while (j < colums)
        {
            if (tab[i][j] != '0' && tab[i][j] != '1' \
                && tab[i][j] != 'C' && tab[i][j] != 'E' \
                tab[i][j] != 'P')
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

int is_exist_elem(char **tab, int lines, int colums, char letter)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < lines)
    {
        while (j < colums)
        {
            if (tab[i][j] == letter)
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

int is_map_rectangle(char **tab, int lines, int colums)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < lines)
    {
        while (tab[i][j] != '\0')
            j++;
        if (j != colums)
            return (0);
        i++;
        j = 0;
    }
    return (1);
}

int is_map_duplicates(char **tab, int lines, int colums, char letter)
{
    int i;
    int j;
    int cpt;

    i = 0;
    j = 0;
    cpt = 0;
    while (i < lines)
    {
        while (j < colums)
        {
            if (tab[i][j] == letter)
            {
                cpt++;
                if (cpt == 2)
                    return (0);
            }
            j++;
        }
        i++;
    }
    return (1);
}

int is_map_close(char **tab, int lines, int colums, char letter)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < lines)
    {
        while (j < colums)
        {
            if ((i == 0 || i == lines) && tab[i][j] != letter)
                return (0);
            if ((j == 0 || j == lines) && tab[i][j] != letter)
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blax <blax@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 11:13:03 by blax              #+#    #+#             */
/*   Updated: 2023/04/11 16:27:56 by blax             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int argc, char *argv[])
{
    map the_map;
    int fd;

    fd = open("map.ber", 'r');
    ft_parse(the_map->tab, fd);

    return (0);
}
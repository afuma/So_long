/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blax <blax@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 19:36:44 by abrabant          #+#    #+#             */
/*   Updated: 2023/04/06 13:26:48 by blax             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

int main()
{
    void *mlx_ptr;
    void *win_ptr;
    void *img_ptr;
    int width, height;

    // Initialisation de la bibliothèque graphique
    mlx_ptr = mlx_init();

    // Création de la fenêtre
    win_ptr = mlx_new_window(mlx_ptr, 800, 600, "Ma fenêtre");

    // Chargement de l'image
    img_ptr = mlx_xpm_file_to_image(mlx_ptr, "dauphin.xpm", &width, &height);

    // Affichage de l'image
    mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);

    // Boucle d'événements pour maintenir la fenêtre ouverte
    mlx_loop(mlx_ptr);

    return 0;
}
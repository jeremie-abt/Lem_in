/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 16:14:04 by galemair          #+#    #+#             */
/*   Updated: 2018/06/20 12:50:38 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

int		main(int argc, char **argv)
{
	SDL_Window *p_window;
	SDL_Event	event;
	int			end;
	//t_sommet	*sommet[HASH_SIZE];

//	ft_bzero(sommet, HASH_SIZE * sizeof(t_sommet *));
//	if ((lm_parseur(sommet)) == -1)
//	{
//		write(1, "ERROR\n", 6);
//		lm_free_hashtable(sommet);
//		ft_bzero(sommet, HASH_SIZE * sizeof(t_sommet *));	
//		return (0);
//	}
	end = 0;
	if (SDL_Init(SDL_INIT_VIDEO) == -1)
	{
		printf("SDL WINDOW FAILED TO OPEN\n");
		return (-1);
	}
	if (!(p_window = SDL_CreateWindow(WINDOW_NAME, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_LENGTH, SDL_WINDOW_SHOWN)))
	{
		printf("SDL FAILED TO CREATE A WINDOW\n");
		return (-1);
	}
	while (end == FALSE)
	{
		SDL_WaitEvent(&event);
		if (event.window.event == SDL_WINDOWEVENT_CLOSE)	
			end = TRUE;
	}
	//SDL_SetWindowIcon(); DEFINI ICONDE DE FENETRE;
	SDL_DestroyWindow(p_window);
	SDL_Quit();
	return (0);
}

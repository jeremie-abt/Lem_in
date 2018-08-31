/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 16:14:04 by galemair          #+#    #+#             */
/*   Updated: 2018/07/17 15:14:33 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

int		main(int argc, char **argv)
{
	SDL_Window		*win;
	SDL_Renderer	*ren;
	SDL_Surface		*tmp;
	SDL_Texture		*background;
	SDL_Texture		*ant;
	SDL_Event		event;
	int			end;

	end = 0;
	if (SDL_Init(SDL_INIT_VIDEO) == -1)
	{
		printf("SDL WINDOW FAILED TO OPEN\n");
		return (-1);
	}
	SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, SDL_WINDOW_RESIZABLE, &win, &ren); // SDL_WINDOW_SHOWN|SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC,&win,&ren);
	if (!win || !ren)
	{
		printf("SDL FAILED TO CREATE A WINDOW\n");
		return (-1);
	}
	//tmp = IMG_Load("resources/background_lemin.jpg");
	tmp = IMG_Load("resources/ant_walk_2.png");
	ant = SDL_CreateTextureFromSurface(ren, tmp);
	unsigned int	format;
	int				access = 0;
	int				largeur = 0;
	int				hauteur	= 0;
	SDL_QueryTexture(ant, &format, &access, &largeur, &hauteur);
	tmp = IMG_Load("resources/background_lemin.jpg");
	background = SDL_CreateTextureFromSurface(ren, tmp);
	unsigned int	b_format;
	int				b_access = 0;
	int				b_largeur = 0;
	int				b_hauteur	= 0;
	SDL_QueryTexture(background, &b_format, &b_access, &b_largeur, &b_hauteur);
	int i = 0;

	while (end == FALSE)
	{
		SDL_WaitEvent(&event);
		if (event.window.event == SDL_WINDOWEVENT_CLOSE)	
			end = TRUE;
		while (i < 1000)
		{
			SDL_Rect cool = {0, 0, b_largeur, b_hauteur};
			SDL_RenderCopy(ren, background, NULL, &cool);
			SDL_Rect dest = {i, i, largeur * 3, hauteur * 3};
			SDL_Rect dest1 = {i + 100, i + 30, largeur / 2, hauteur / 2};
			SDL_RenderCopy(ren, ant, NULL,&dest);
			SDL_RenderCopy(ren, ant, NULL,&dest1);
			SDL_RenderPresent(ren);
			SDL_Delay(10);
			SDL_RenderClear(ren);
			i += 3;
		}
	}
	//SDL_SetWindowIcon(); DEFINI ICONDE DE FENETRE;
	SDL_DestroyWindow(win);
	SDL_Quit();
	return (0);
}

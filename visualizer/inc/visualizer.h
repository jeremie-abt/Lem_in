/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galemair <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 16:12:04 by galemair          #+#    #+#             */
/*   Updated: 2018/06/25 18:24:19 by galemair         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZER_H
# define VISUALIZER_H

//#include "stdlib.h"
//#include "libft.h"
//#include "get_next_line.h"
#include "const.h"
#include "SDL.h"
#include "SDL_image.h"
#include <stdio.h>

//SDL_RECT
//{
//	int x;
//	int y;
//	int w;
//	int h;
//}
typedef	struct s_SDL_env
{
	SDL_Window		*win;
	SDL_Renderer	*ren;
	SDL_Event		event;
	int				end;
}				t_SLD_env;
#endif

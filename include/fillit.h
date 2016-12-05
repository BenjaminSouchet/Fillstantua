/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmonein <gmonein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/20 07:14:20 by gmonein           #+#    #+#             */
/*   Updated: 2016/12/03 01:31:19 by gmonein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define US		unsigned short
# define UI		unsigned int
# define INVALID_MAP	"error\n"

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct			s_ligne
{
	unsigned long	tab[64];
	int				start[64];
	int				end[64];
}						t_ligne;

typedef struct				s_data
{
	unsigned short			x1;
	unsigned short			y1;
	unsigned short			x2;
	unsigned short			y2;
	unsigned short			x3;
	unsigned short			y3;
	unsigned short			x4;
	unsigned short			y4;
	unsigned short			len;
	unsigned short			height;
}							t_data;

typedef struct				s_list
{
	unsigned short			tetri;
	unsigned int			*itetri;
	int						x;
	int						y;
	struct s_data			data;
	char					id;
	int						last_pos;
	int						placed;
	struct s_list			*next;
	struct s_list			*past;
	struct s_list			*begin;
}							t_list;

typedef struct				s_list_valid
{
	unsigned short			tetri;
	struct s_list_valid		*next;
}							t_list_valid;

t_data						ft_xy_s(void);
t_data						ft_xy_r(void);
t_data						ft_xy_q(void);
t_data						ft_xy_p(void);
t_data						ft_xy_o(void);
t_data						ft_xy_n(void);
t_data						ft_xy_m(void);
t_data						ft_xy_l(void);
t_data						ft_xy_k(void);
t_data						ft_xy_j(void);
t_data						ft_xy_i(void);
t_data						ft_xy_h(void);
t_data						ft_xy_g(void);
t_data						ft_xy_f(void);
t_data						ft_xy_e(void);
t_data						ft_xy_d(void);
t_data						ft_xy_c(void);
t_data						ft_xy_b(void);
t_data						ft_xy_a(void);
void						ft_set_data_one(t_list *list);
void						ft_set_data_two(t_list *list);
unsigned int				*ft_short_to_ul(unsigned short tetris);
void						ft_make_ul(t_list *lst);
unsigned int				*ft_setmap(void);
void						ft_make_past(t_list *lst);
int							ft_check_list(t_list *lst);
int							main(int argc, char **argv);
int							ft_error(int error_nb);
unsigned short				ft_bits(char *s);
t_list						*ft_new_fill(char *file);
int							solver(unsigned int *tab, t_list *lst, int size, t_ligne sct);
void						ft_print_map(t_list *lst, int size, t_ligne sct);
int							ft_strlen(char *str);
void						ft_list_init(t_list *lst);
unsigned int				*ft_del_tetris(unsigned int *tab, t_list *lst);
unsigned int				*ft_erase_map(unsigned int *tab);
int							ft_map_min(t_list *lst);
void						ft_bzero(void *s, size_t n);
t_ligne		make_sas_mask(int num);
int		*get_nb_floors(int num, int min, int resti);
int		len_last(int *tab, int num);

#endif

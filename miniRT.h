/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasoubai <lasoubai@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 07:35:24 by lasoubai          #+#    #+#             */
/*   Updated: 2026/01/22 21:25:14 by lasoubai         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "./libft/libft.h"
# include "gnl/get_next_line.h"
# include "mlx.h"
# include <math.h>
# include <stdio.h>

# define H 800
# define W 800
# define UN __FLT_MAX__

typedef struct s_img
{
	void		*imgs;
	void		*pixel;
	int			bp;
	int			line_len;
	int			endian;
}				t_img;

typedef struct s_vect
{
	float		x;
	float		y;
	float		z;
}				t_vect;

typedef struct s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct s_coord
{
	t_vect		right;
	t_vect		up;
	t_vect		forward;

}				t_coord;

typedef struct s_ray
{
	t_vect		direct;
	t_vect		origine;
	float		t;
}				t_ray;

typedef struct s_ambient
{
	float		ratio;
	t_color		color;
}				t_ambient;

typedef struct s_camera
{
	t_vect		posit;
	t_vect		forward;
	int			h;
	int			w;
	float		fov;
}				t_camera;

typedef struct s_light
{
	t_vect		posit;
	t_vect		forward;
	float		ratio;
	t_color		color;
}				t_light;

typedef struct s_sp
{
	t_vect		center;
	float		ray;
	float		t;
	t_color		color;
	struct s_sp	*next;
}				t_sp;

typedef struct s_pl
{
	t_vect		posit;
	t_vect		normal_v;
	t_color		color;
	float		t;
	struct s_pl	*next;
}				t_pl;

typedef struct s_cy
{
	t_vect		center;
	t_vect		axis_v;
	t_color		color;
	float		ray;
	float		t;
	float		height;
	t_vect		cap_centr;
	struct s_cy	*next;
}				t_cy;

typedef struct s_info
{
	t_ambient	ambient;
	t_camera	camera;
	t_light		light;
	t_sp		*sp;
	t_pl		*pl;
	t_cy		*cy;
	void		*ptr;
}				t_info;

typedef struct s_mlx
{
	t_info		*info;
	char		*name;
	void		*mlx_c;
	void		*mlx_w;
	int			color;
	t_img		img;
}				t_mlx;

typedef struct s_hit
{
	float		t;
	t_vect		normal;
	t_color		color;
}				t_hit;

typedef struct s_fcolor
{
	float		r;
	float		g;
	float		b;
}				t_fcolor;

typedef struct init
{
	float		a;
	float		b;
	float		c;
	float		delta;
	float		t1;
	float		t2;
	float		t;
	float		h;

}				t_init;

//  ************ parssing ************

int				pars(char *line, t_info **scene_inf, int **flag, int **nobj);
int				read_file(char *file, t_info **scene_info);
float			ft_atof(char *nbr);
int				check_num(char *str);
int				check_nb_arg(char **line, int m);
int				check_color(float r, float g, float b);
int				check_coord(float x, float y, float z);

//--------check store----------
int				check_store_a(char **sp_line, t_info **scene_inf);
int				check_stor_c(char **sp_line, t_info **scene_inf);
int				check_store_l(char **sp_line, t_info **scene_inf);
int				check_store_sp(char **sp_line, t_info **scene_inf);
int				check_store_pl(char **sp_line, t_info **scene_inf);
int				check_store_cy(char **sp_line, t_info **scene_inf);

//--------store----------------
int				store_ambient(char **sp_clor, t_info **scene_inf,
					char **sp_line);
int				stor_camera(char **sp_n_v, char **sp_coord, t_info **scene_inf);
int				store_light(char **sp_light_p, char **sp_color,
					t_info **scene_inf, char **sp_line);
int				store_info_sp(t_sp *sp, char **sp_coord, char **sp_color);
int				store_light_info(char **sp_light_p, char **sp_color,
					t_info **scene_inf);
int				store_camera_info(t_info **scene_inf, char **sp_coord,
					char **sp_n_v);
int				store_cy_info(t_cy *cy, char **sp_coord, char **sp_nrml_v,
					char **sp_color);
int				store_pl_info(t_pl *pl, char **sp_coord, char **sp_nrml_v,
					char **sp_color);

//------multiple object---------
t_sp			*new_sp_node(t_sp sp_);
t_pl			*new_pl_node(t_pl pl);
t_cy			*new_cy_node(t_cy cy);
void			add_back_sp(t_info **scene_inf, t_sp sp);
void			add_back_pl(t_info **scene_inf, t_pl pl);
void			add_back_cy(t_info **scene_inf, t_cy cy);
//=========================== Free memory========================
void			ft_free_ptr_array(char **arr);
void			ft_free_info(t_info **info);
// ============== send ray =========
t_ray			send_ray(float x, float y, t_info *info);
float			check_cy_inters(t_cy *cy, t_ray ray);
void			int_it(t_init *v);
void			cy_quadratic(t_cy *cy, t_ray ray, t_vect oc, t_init *v);
// ---------------------------------------------------------

t_vect			add_vect(t_vect v1, t_vect v2);
t_vect			sub_vect(t_vect v1, t_vect v2);
t_vect			scalar(t_vect v, float k);
t_vect			normalization(t_vect v);
t_vect			cross(t_vect v, t_vect w);
float			magnaitude(t_vect v);
float			dot(t_vect v, t_vect w);

void			ft_init(t_mlx *mx);
void			check_objects(t_info *info, t_ray ray, t_hit *hit);
void			ft_put(t_mlx *mx, t_info *scene_info);
void			ft_evant(t_mlx *mx);
int				ft_close(t_mlx *mx);

t_vect			ray_equation(t_vect origin, t_vect dir, float t);
float			sphere(t_sp s, t_ray ray);
float			plan(t_pl pl, t_ray ray);

int				check_shadow(t_info *info, t_vect hit_point, t_vect normal);
t_color			shdow(t_ray ray, t_info *info, t_hit hit);
t_vect			get_sphere_normal(t_sp sphere, t_vect hit_point);
t_vect			get_cylinder_normal(t_cy cylinder, t_vect hit_point);
t_vect			get_plane_normal(t_pl plane);

#endif
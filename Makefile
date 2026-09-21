NAME = miniRT

CC = cc 

CFLAGS = -Wall -Wextra -Werror

LMATH = -lm
LMLX = -I/usr/include/minilibx-linux -L/usr/include/minilibx-linux -lmlx_Linux -lX11 -lXext 


SRC= send_ray/main.c parssing/read_file.c parssing/utils.c parssing/check_elem.c \
	parssing/pars.c parssing/store_obj_utils.c parssing/check_obj_utils.c parssing/store_elem_uils.c \
	gnl/get_next_line.c gnl/get_next_line_utils.c \
	parssing/check_obj.c send_ray/send_ray.c send_ray/vector.c  send_ray/cylindre.c\
	send_ray/ray.c send_ray/hook.c send_ray/put.c send_ray/init.c send_ray/shadow.c\
	send_ray/check_objects.c send_ray/check_shadow.c send_ray/vect_rest.c \
	send_ray/shadow_rest.c free_memory.c send_ray/cylinder_rest.c parssing/atof.c


OBJ= $(SRC:.c=.o)

LIB = libft/libft.a

all: $(LIB) $(NAME)

$(LIB):
	$(MAKE) -C libft 

$(NAME): $(OBJ) 
		$(CC) $(CFLAGS) $(OBJ) $(LIB) $(LMLX) $(LMATH) -o $(NAME)

%.o: %.c miniRT.h
	$(CC) $(CFLAGS) $(LMLX) $(LMATH) -c $< -o $@

clean :
	rm -f  $(OBJ)
	$(MAKE) -C libft clean

fclean :
	rm -f  $(OBJ) $(NAME)
	$(MAKE) -C libft fclean

re : clean fclean all

.PHONY: all clean fclean re
NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS =	main.c\
		check_map.c\
		get_map_info.c\
		set_map_to_solong.c\
		initialize.c\
		check_playable.c\
		draw_objs.c\
		dfs.c\
		callback.c\
		move.c\
		print.c\
		error.c\
		utils.c\
		utils2.c\

OBJCS = $(SRCS:.c=.o)

PRINTFDIR = ./library/ft_printf

GNLDIR = ./library/get_next_line

FT_PRINTF = -L$(PRINTFDIR) -lftprintf

GNL = -L$(GNLDIR) -lgnl

MLX = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJCS)
	$(MAKE) -C ${PRINTFDIR}
	$(MAKE) -C ${GNLDIR}
	$(CC) $(CFLAGS) -o $@ $(OBJCS) $(FT_PRINTF) $(GNL) $(MLX) 

clean:
	rm -f $(OBJCS)
	$(MAKE) -C ${PRINTFDIR} clean
	$(MAKE) -C ${GNLDIR} clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ${PRINTFDIR} fclean
	$(MAKE) -C ${GNLDIR} fclean

re: fclean all

.PHONY: all clean fclean re
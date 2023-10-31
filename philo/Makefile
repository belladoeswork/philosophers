
NAME    =   philo
# PRINT_PATH  =   ./minilibx-linux
# PRINT_NAME  =   ./minilibx-linux/libmlx.a
# GETNEXTLINE := GNL/*c
# LIBFT := Libft/*c
# LIBRARY := -Iminilibx-linux -lXext -lX11 -lm -lz
CC      =   @clang
CFLAGS  =   -g -Wall -Wextra -Werror
RM = @rm -f
VALGRIND = valgrind --leak-check=full
SRC =   ft_monitor.c\
        ft_philo.c\
        ft_routine.c\
        ft_supervise.c\
		ft_actions.c\
		ft_forks.c\
		main.c\
		utils/ft_init.c\
		utils/ft_checks.c\
		utils/ft_helpers.c\
		utils/ft_errors.c


OBJ = $(SRC:.c=.o)
all: $(PRINT_NAME) $(NAME)
$(NAME): $(OBJ)
	$(CC) $(OBJ) $(PRINT_NAME) $(LIBFT) -o $(NAME)
#	$(PRINT_NAME):
#	@make -C $(PRINT_PATH)
valgrind: all
	$(VALGRIND) ./$(NAME)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	@make clean 
	$(RM) $(OBJ)
fclean : clean
	# @make fclean 
	$(RM) $(NAME)
re : fclean all
.PHONY: re fclean clean all re
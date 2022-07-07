NAME = philo_bonus

SRC =	main.c  \
        ft_atoi.c \
        actions.c \
        time.c \
        init_structs.c \
        utils.c \
        create_processes.c \
        ft_calloc.c \
        errors.c \

FLAGS = -Wall -Wextra -Werror -g# -fsanitize=thread
OBJ = $(patsubst %.c,%.o,$(SRC))
HEADER = philo_bonus.h

all : $(NAME) $(SRC)

$(NAME) : $(OBJ) $(HEADER)
	gcc $(FLAGS) $(OBJ) -o $@

$(OBJ) : %.o : %.c
	gcc $(FLAGS) -c  $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re :  fclean all

.PHONY : all clean fclean re
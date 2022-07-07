NAME = philo

SRC =	main.c  \
        ft_atoi.c \
        actions.c \
        time.c \
        init_structs.c \
        utils.c \
        create_threads.c \
        take_forks.c\
        ft_calloc.c \

FLAGS = -Wall -Wextra -Werror -g# -fsanitize=thread
OBJ = $(patsubst %.c,%.o,$(SRC))
HEADER = philo.h

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
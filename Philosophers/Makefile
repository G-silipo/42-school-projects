NAME	=	philosophers

SRCS	=	philo.c \
			stampa.c \
			routine.c \
			check.c \
			time.c

OBJS	=	$(SRCS:.c=.o)
CC		=	gcc
FLAGS 	= 	-Wall -Wextra -Werror -lpthread -o

%.o 	:	%.c
			$(CC) -c $< -o $@

$(NAME) :	$(OBJS)
			$(CC) $(FLAGS) $(NAME) $(OBJS) 
			rm -f $(OBJS)

clean	:	
			rm -f $(OBJS)

fclean	:	clean
			rm -f $(NAME)

re		:	fclean $(NAME)

.PHONY	:	all	clean fclean re run
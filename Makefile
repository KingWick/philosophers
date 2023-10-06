SRCS		= srcs/main.c srcs/parsing.c srcs/init.c \
			srcs/toolbox.c srcs/activity.c srcs/toolbox1.c 

OBJS		= ${SRCS:.c=.o}

INCLUDES	= includes/
NAME  		= philo
CC 			= gcc
CFLAGS		= -Wall -Wextra -Werror 
RM			= rm -f

GREY=\033[0;37m
RED=\033[0;31m
GREEN= \033[92m
YELLOW=\033[1;33m
BLUE=\033[0;34m
PURPLE=\033[0;35m
ORANGE = \033[0;33m
CYAN=\033[0;36m
WHITE=\033[1;37m
BIRed=\033[1;91m
END=\033[0m

all: $(NAME)

%.o: %.c ./includes/philo.h
	${CC} ${CFLAGS} -I$(INCLUDES) -c $< -o ${<:.c=.o}
	
$(NAME): $(OBJS)
	${CC} -o $(NAME) $(OBJS)
	@echo "${BLUE}successfully${YELLOW} compiled $(NAME) ${GREEN}is ready !${END}"

clean:
	${RM} ${OBJS}
	@echo "${WHITE}.o files ${BIRed}were successfully ${RED}deleted !${END}"
	
fclean: clean
	${RM} ${NAME}

re: fclean all
#SETUP
NAME		= push_swap
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

#FILES
FLS			= push_swap.c utils.c
SRCS_DIR	= sources/
HEADER		= $(SRCS_DIR)push_swap.h
SRCS		= $(addprefix $(SRCS_DIR), $(FLS))
OBJS		= $(SRCS:.c=.o)

#COMMANDS
all:		$(NAME)

$(NAME):	$(OBJS)
			@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
			@echo "$(GREEN)$(NAME) created!$(DEFAULT)"

$(OBJS):	$(HEADER)

clean:
			@$(RM) $(OBJS)
			@echo "$(YELLOW)$(NAME) cleaned!$(DEFAULT)"

fclean:		clean
			@$(RM) $(NAME)
			@echo "$(RED)$(NAME) deleted!$(DEFAULT)"

re:			fclean all

#EXTRA
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
CYAN = \033[1;36m
WHITE = \033[1;37m
DEFAULT = \033[0m

.PHONY:		all clean fclean re
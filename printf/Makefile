NAME = libftprintf
CC = cc
CFLAGS = -Wall -Werror -Wextra

HEADER = ft_printf.h
CFILES = $(wildcard *.c)
OFILES = $(CFILES:.c=.o)

all: $(NAME)

$%.o: $(CFILES) $(HEADER)
	@$(CC) $(CFLAGS) -c $< -0 $@
	@echo "Creating o files"

$(NAME): $(OFILES) $(HEADER)
	@ar rcs $@ $^
	@echo "creating libftprintf library"

clean:
	@rm -f $(OFILES)
	@echo "cleaning -o files"

fclean: clean
	@rm -f $(NAME)
	@echo "cleaning all files inlcude library"

re: fclean all
	@echo "cleaning all + new library"

.PHONY: all clean fclean re

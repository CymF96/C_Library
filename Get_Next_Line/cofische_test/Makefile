NAME = Gnl_m
NAME2 = Gnl_b
NAME3 = Gnl_b2
NAME4 = Gnl_n
UNAME = $(shell uname)

CC = cc
CFLAGS = -Wall -Werror -Wextra -DBUFFER_SIZE=42
HEADER = ../get_next_line.h
HEADERB = ../get_next_line_bonus.h

CFILES = ../get_next_line.c ../get_next_line_utils.c test.c
CBONUS = ../get_next_line_bonus.c ../get_next_line_utils_bonus.c
CTEST = test_2.c
CTESTM = test_multiple_files.c
CTESTN = test_nothing.c

OFILES = $(CFILES:.c=.o)
OBONUS = $(CBONUS:.c=.o)
OTEST = $(CTEST:.c=.o)
OTESTM = $(CTESTM:.c=.o)
OTESTN = $(CTESTN:.c=.o)

ifeq ($(UNAME), Linux)
    VALGRIND = valgrind -s --leak-check=full --show-leak-kinds=all
endif

m: $(NAME)
b: $(NAME2)
c: $(NAME3)
d: $(NAME4)

$(NAME): $(OFILES)
		@$(CC) $(CFLAGS) -o $@ $^
		@chmod 777 $@

$(NAME2): $(OBONUS) $(OTEST)
		@$(CC) $(CFLAGS) -o $@ $^
		@chmod 777 $@

$(NAME3): $(OBONUS) $(OTESTM)
		@$(CC) $(CFLAGS) -o $@ $^
		@chmod 777 $@

$(NAME4): $(OBONUS) $(OTESTN)
		@$(CC) $(CFLAGS) -o $@ $^
		@chmod 777 $@

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

%_bonus.o: %_bonus.c $(HEADERB)
	@$(CC) $(CFLAGS) -c $< -o $@

%_2.o: %_2.c
	@$(CC) $(CFLAGS) -c $< -o $@

%_multiple_files.o: %_multiple_files.c
	@$(CC) $(CFLAGS) -c $< -o $@

%_nothing.o: %_nothing.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OFILES) $(OBONUS) $(OBONUSM) $(OTEST) $(OTESTM) $(OTESTN)

fclean: clean
	rm -f $(NAME) $(NAME2) $(NAME3) $(NAME4)

re: fclean all

valgrind-m: $(NAME)
	$(VALGRIND) ./$(NAME)

valgrind-b: $(NAME2)
	$(VALGRIND) ./$(NAME2)

valgrind-b2: $(NAME3)
	$(VALGRIND) ./$(NAME3)

valgrind-n: $(NAME4)
	$(VALGRIND) ./$(NAME4)

.PHONY: m b c clean fclean re valgrind-m valgrind-b valgrind-b2 valgrind-n

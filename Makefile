# ------------ Makefile ------------ #

NAME 			:= push_swap

# ------------ Ingredients ------------ #

SRCS			:= main.c sorting_utils.c stack_init.c errors.c commands.c small_sorts.c big_sort.c init_nodes_a.c init_nodes_b.c
OBJS			:= main.o sorting_utils.o stack_init.o errors.o commands.o small_sorts.o big_sort.o init_nodes_a.o init_nodes_b.o

LIBS			:= ftprintf
LIBS_TARGET		:= external_lib/libftprintf.a

# ------------ Utensils ------------ #

CFLAGS			:= -Wall -Wextra -Werror -g -fsanitize=address
RM				:= rm -f

# ------------ Recipes ------------ #

all: $(NAME)

$(NAME): $(OBJS) $(LIBS_TARGET)
	cc $(CFLAGS) $(OBJS) -L $(dir $(LIBS_TARGET)) -l $(LIBS) -o $(NAME)

%.o:%.c
	cc $(CFLAGS) -c $< -o $@

$(LIBS_TARGET):
	$(MAKE) -C $(dir $(LIBS_TARGET))

clean:
	$(MAKE) clean -C $(dir $(LIBS_TARGET))
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(dir $(LIBS_TARGET))
	$(RM) $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

print-%:
	$(info $($*))

# ------------ Specifications ------------ #

.PHONY: clean fclean re new all

# ------------ Makefile ------------ #

NAME 			:= push_swap

# ------------ Ingredients ------------ #

SRCS			:= main.c sorting_utils_1.c sorting_utils_2.c stack_init.c errors.c reverse_rotate.c \
				   push.c rotate.c swap.c small_sorts.c big_sort.c init_nodes_a.c init_nodes_b.c
OBJS			:= main.o sorting_utils_1.o sorting_utils_2.o stack_init.o errors.o reverse_rotate.o \
				   push.o rotate.o swap.o small_sorts.o big_sort.o init_nodes_a.o init_nodes_b.o

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

bonus:
	cd ../checker && make

clean:
	$(MAKE) clean -C $(dir $(LIBS_TARGET))
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C $(dir $(LIBS_TARGET))
	$(RM) $(NAME)
	cd ../checer && make fclean

re:
	$(MAKE) fclean
	$(MAKE) all

print-%:
	$(info $($*))

# ------------ Specifications ------------ #

.PHONY: clean fclean re new all

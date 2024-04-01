# ------------ Makefile ------------ #

NAME 			:= push_swap
B_NAME			:= checker

# ------------ Ingredients ------------ #

SRCS			:= main.c sorting_utils_1.c sorting_utils_2.c stack_init.c errors.c reverse_rotate.c \
				   push.c rotate.c swap.c small_sorts.c big_sort.c init_nodes_a.c init_nodes_b.c
OBJS			:= main.o sorting_utils_1.o sorting_utils_2.o stack_init.o errors.o reverse_rotate.o \
				   push.o rotate.o swap.o small_sorts.o big_sort.o init_nodes_a.o init_nodes_b.o

B_SRC			:= checker.c
B_OBJ			:= checker.o

LIBS			:= ftprintfgnl
LIBS_TARGET		:= external_lib/libftprintfgnl.a

# ------------ Utensils ------------ #

CFLAGS			:= -Wall -Wextra -Werror -g -fsanitize=address
RM				:= rm -f

# ------------ Recipes ------------ #

all: $(NAME)

bonus: $(B_NAME)

$(NAME): $(OBJS) $(LIBS_TARGET)
	cc $(CFLAGS) $(OBJS) -L $(dir $(LIBS_TARGET)) -l $(LIBS) -o $(NAME)

$(B_NAME): $(B_OBJ) $(OBJS) $(LIBS_TARGET)
	cc $(CFLAGS) $(OBJS) $(B_OBJ) -L $(dir $(LIBS_TARGET)) -l $(LIBS) -o $(B_NAME)

%.o:%.c
	cc $(CFLAGS) -c $< -o $@

# // IS THIS THE ISSUE???
$(B_OBJ).o: $(B_SRC).c
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

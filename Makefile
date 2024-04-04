# ------------ Makefile ------------ #

NAME 			:= push_swap
B_NAME			:= bonus/checker

# ------------ Ingredients ------------ #

SRCS			:= push_swap.c sorting_utils_1.c sorting_utils_2.c stack_init.c errors.c reverse_rotate.c \
				   push.c rotate.c swap.c small_sorts.c big_sort.c init_nodes_a.c init_nodes_b.c
OBJS			:= $(SRCS:.c=.o)

B_SRC			:= bonus/checker.c bonus/checker_utils.c sorting_utils_1.c sorting_utils_2.c stack_init.c errors.c reverse_rotate.c \
				   push.c rotate.c swap.c small_sorts.c big_sort.c init_nodes_a.c init_nodes_b.c
B_OBJ			:= $(B_SRC:.c=.o)

LIBS			:= ftprintfgnl
LIBS_TARGET		:= external_lib/libftprintfgnl.a

# ------------ Utensils ------------ #

CFLAGS			:= -Wall -Wextra -Werror #-g -fsanitize=address
RM				:= rm -f

# ------------ Recipes ------------ #

all: $(NAME)

bonus: $(B_NAME)

$(NAME): $(OBJS) $(LIBS_TARGET)
	cc $(CFLAGS) $(OBJS) -L $(dir $(LIBS_TARGET)) -l $(LIBS) -o $(NAME)

$(B_NAME): $(B_OBJ) $(LIBS_TARGET)
	cc $(CFLAGS) $(B_OBJ) -L $(dir $(LIBS_TARGET)) -l $(LIBS) -o $(B_NAME)

%.o:%.c
	cc $(CFLAGS) -c $< -o $@

#$(B_OBJ): $(B_SRC)
#	cc $(CFLAGS) -c $< -o $@

$(LIBS_TARGET):
	$(MAKE) -C $(dir $(LIBS_TARGET))

clean:
	$(MAKE) clean -C $(dir $(LIBS_TARGET))
	$(RM) $(OBJS)
	$(RM) $(B_OBJ)

fclean: clean
	$(MAKE) fclean -C $(dir $(LIBS_TARGET))
	$(RM) $(NAME) 
	$(RM) bonus/$(B_NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

print-%:
	$(info $($*))

# ------------ Specifications ------------ #

.PHONY: clean fclean re new all

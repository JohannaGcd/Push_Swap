
# ------------ Makefile ------------ #

NAME 			:= checker


# ------------ Ingredients ------------ #

SRCS			:= 
OBJS			:= $(SRCS:.c=.o)

# ------------ Utensils ------------ #

CFLAGS			:= -Wall -Wextra -Werror -g -fsanitize=address
RM				:= rm -f

# ------------ Recipes ------------ #

all: $(NAME)

$(NAME): $(OBJS) $(PUSH_SWAP)
	cc $(CFLAGS) $^ -o $(NAME)

%.o:%.c
	cc $(CFLAGS) -c $< -o $@

$(PUSH_SWAP): 
	cd ../push_swap && make

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	cd ../push_swap && make fclean 

re:
	$(MAKE) fclean
	$(MAKE) all

print-%:
	$(info $($*))

# ------------ Specifications ------------ #

.PHONY: clean fclean re new all

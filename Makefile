#NAMES
NAME= push_swap
NAME_BONUS= checker

#COMPILING
CC= cc
CFLAGS= -Wall -Wextra -Werror #-fsanitize=address
RM= rm -rf

#DIRS
LIBFT_DIR= ./libft
INCS= ./include
SRCS_DIR= ./src
OBJS_DIR= ./obj

#LIBS
LIBFT= ${LIBFT_DIR}/libft.a
LIBFT_LIB= -L${LIBFT_DIR} -lft

#FILES
SRCF= costs ops ops2 sorter stack utils
SRCF_B= ops_bonus ops2_bonus stack_bonus utils_bonus

SRCS= $(addprefix ${SRCS_DIR}/, $(addsuffix .c, ${SRCF}))
SRCS_BONUS= $(addprefix ${SRCS_DIR}/, $(addsuffix .c, ${SRCF_B}))
OBJS= $(addprefix ${OBJS_DIR}/, $(addsuffix .o, ${SRCF}))
OBJS_BONUS= $(addprefix ${OBJS_DIR}/, $(addsuffix .o, ${SRCF_B}))

all: ${NAME}

${NAME}: ${LIBFT} ${OBJS} main.c
	${CC} ${CFLAGS} main.c ${OBJS} -I${INCS} ${LIBFT_LIB} -o ${NAME}

${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c | ${OBJS_DIR}
	${CC} ${CFLAGS} -I${INCS} -c $< -o $@

${OBJS_DIR}:
	mkdir -p ${OBJS_DIR}

${LIBFT}:
	make bonus -sC ${LIBFT_DIR}

bonus: ${NAME_BONUS}

${NAME_BONUS}: ${LIBFT} ${OBJS_BONUS} main_bonus.c
	${CC} ${CFLAGS} main_bonus.c ${OBJS_BONUS} -I${INCS} ${LIBFT_LIB} -o ${NAME_BONUS}

clean:
	${RM} ${OBJS_DIR}
	make clean -sC ${LIBFT_DIR}

fclean: clean
	${RM} ${NAME} ${NAME_BONUS}
	make fclean -sC ${LIBFT_DIR}

re: fclean all

bre: fclean bonus

debug: ${LIBFT}
	${CC} -g3 main.c ${SRCS} -I${INCS} ${LIBFT_LIB} -o ${NAME}

debugB: ${LIBFT}
	${CC} -g3 main_bonus.c ${SRCS_BONUS} -I${INCS} ${LIBFT_LIB} -o ${NAME_BONUS}

.PHONY: all bonus clean fclean re bre

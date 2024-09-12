NAME = 		ARRS

SRCS = 		main.cpp MyArrs.cpp ./utils/ft_split.cpp ./utils/ft_strlcpy.cpp ./utils/ft_strlen.cpp ./utils/ft_toupper.cpp Random.cpp \
			./Func/Load.cpp \
			./Func/Concat.cpp \
			./Func/Copy.cpp \
			./Func/Exit.cpp \
			./Func/Free.cpp \
			./Func/Intersect.cpp \
			./Func/Permute.cpp \
			./Func/Print.cpp \
			./Func/Rand.cpp \
			./Func/Remove.cpp \
			./Func/Save.cpp \
			./Func/Sort.cpp \
			./Func/Stat.cpp \
			./Func/Xor.cpp 

OBJS = 		${SRCS:.cpp=.o}

CPP	= 		c++

HEADER  =  MyArrs.hpp

all:		$(NAME)

.o: 		$(SRCS)
			$(CPP)  -c $< -o $@

$(NAME):	$(OBJS) $(HEADER)
			$(CPP)  $(OBJS) -o $(NAME)

clean:
			@rm -rf $(OBJS)

fclean:		clean
			@rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
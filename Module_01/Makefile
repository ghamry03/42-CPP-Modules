DIRS		=	./ex00		\
				./ex01		\
				./ex02		\
				./ex03		\
				./ex04		\
				./ex05		\
				./ex06		\

all			:	
				$(foreach dir,$(DIRS),$(MAKE) -C $(dir) all && ) true

clean		:	
				$(foreach dir,$(DIRS),$(MAKE) -C $(dir) clean && ) true

fclean		:	
				$(foreach dir,$(DIRS),$(MAKE) -C $(dir) fclean && ) true

re			:	
				$(foreach dir,$(DIRS),$(MAKE) -C $(dir) re && ) true


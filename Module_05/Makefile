DIRS		=	./ex00		\

all			:	
				$(foreach dir,$(DIRS),$(MAKE) -C $(dir) all && ) true

clean		:	
				$(foreach dir,$(DIRS),$(MAKE) -C $(dir) clean && ) true

fclean		:	
				$(foreach dir,$(DIRS),$(MAKE) -C $(dir) fclean && ) true

re			:	
				$(foreach dir,$(DIRS),$(MAKE) -C $(dir) re && ) true


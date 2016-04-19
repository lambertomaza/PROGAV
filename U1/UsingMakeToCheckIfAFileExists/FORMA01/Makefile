DOT := $(shell command -v dot)

all:
ifndef DOT
	$(error "dot is not available please install graphviz")
endif
	dot -Tpdf -o pres.pdf pres.dot
#It works beautifully because "command -v" doesn't print anything 
#if the executable is not available, so the variable DOT never 
#gets defined and you can just check it whenever you want in your 
#code. In this example I'm throwing an error, but you could do 
#something more useful if you wanted.

#If the variable is available, "command -v" performs the inexpensive 
#operation of printing the command path, defining the DOT variable.

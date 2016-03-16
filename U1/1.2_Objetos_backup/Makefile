CC=g++
#LD=ld

APP_SRCS:=$(wildcard *.cpp)

all: test

test: $(APP_SRCS:%.cpp=obj/%.o)
	$(CC) -o $@ $^

obj/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CC) -c -o $@ $<

clean:
	find $(ROOTBIN) -type f ! -name .empty -print -delete
	rm -rfv obj

CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -g
SRCS = main.c layer.c
HDRS = layer.h

nn: $(SRCS) $(HDRS)
	$(CC) $(CFLAGS) -o nn $(SRCS) -lm

clean:
	rm -rf nn nn.dSYM

.PHONY: clean

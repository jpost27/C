#   simple makefile
CC     =     gcc
CFLAGS =
# CFLAGS =     -g -std=gnu99
# CFLAGS =     -g -DDEBUG=1
OBJS   =     randoms.o
EXEC   =     randoms
LFLAGS =
LIBS  =
INCS  =

$(EXEC)   :   $(OBJS)
	$(CC) $(LFLAGS) -o $(EXEC) $(OBJS) $(LIBS)

.c.o:
	$(CC) $(CFLAGS) -c $(INCS) $*.c

$(OBJS)	:

clean :
	rm -f $(OBJS) $(EXEC)

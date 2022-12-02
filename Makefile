# Two executables
PROGS=sovohj child_exec
CC=gcc
#CC=clang
CFLAGS = -Wall -g -pedantic
C_E_OBJS = child_exec.o morse.o
S_OBJ = main.o


all: $(PROGS)
# Create executables
sovohj: $(S_OBJ)
	$(CC) $(CFLAGS) $(S_OBJ) -o sovohj
child_exec: $(C_E_OBJS)
	$(CC) $(CFLAGS) $(C_E_OBJS) -o child_exec

# Create object files
main.o: main.c
	$(CC) $(CFLAGS) -c main.c
child_exec.o: child_exec.c
	$(CC) $(CFLAGS) -c child_exec.c
morse.o: morse.c morse.h
	$(CC) $(CFLAGS) -c morse.c

# Clean (executable) files named in PROGS, files ending in ~ and files ending in .o
clean:
	rm -f $(PROGS) *~ *.o

SRC=$(wildcard *.c)
ASM=$(SRC:%.c=%.s)
OBJ=$(ASM:%.s=%.o)
EXE=$(OBJ:%.o=%)

.SUFFIXES: .c .s .o
.PHONY: clean all

all: $(EXE)

$(filter %.s, $(ASM)): %.s: %.c
	gcc -std=c17 -Wall -pedantic-errors -O0 -g -S $<

$(filter %.o, $(OBJ)): %.o: %.s
	as --gstabs -o $@ $<

$(filter %, $(EXE)): %: %.o
	gcc -o $@ $<

clean:
	@$(foreach exe, $(EXE), echo $(RM) $(exe); ($(RM) $(exe)) || exit;)
	@$(foreach obj, $(OBJ), echo $(RM) $(obj); ($(RM) $(obj)) || exit;)
	@$(foreach asm, $(ASM), echo $(RM) $(asm); ($(RM) $(asm)) || exit;)

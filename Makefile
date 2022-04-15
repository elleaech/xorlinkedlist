LIBS_INCLUDE = -I./

main:
	@gcc -o main.bin main.c node.c $(LIBS_INCLUDE)
clean:
	rm *.bin
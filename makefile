dirinfo: main.c
	gcc main.c -o dirinfo
	
run: dirinfo
	./dirinfo
	
clean:
	rm *~

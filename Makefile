frameworks = -framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL
raylib_path = /Users/magnusstenqvist/progg/c/raylib/src/libraylib.a

OBJ = main.o assets.o 

patience: $(OBJ)
	clang $(frameworks) $(OBJ) -o bin/patience $(raylib_path) 

main.o: main.c main.h
	clang -c main.c

assets.o: assets.c
	clang -c assets.c

clean:
	rm *.o

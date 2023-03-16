OBJ=main.cpp shader_manager.cpp vendor/glad.c

linux:
	g++ $(OBJ) -lglfw3 

apple:
	clang++ -std=c++20 -stdlib=libc++ -lglfw -framework CoreVideo -framework OpenGL -framework IOKit -framework Cocoa -framework Carbon $(OBJ)


CC = g++
PROG = physics
SRCS = ../physics/testPhysics.cpp ../physics/phy.cpp ../terrain/renderTerrain.cpp ../read/load.cpp ../physics/vect.cpp ../read/glm.c ../object/obj.cpp ../terrain/culling.cpp 
ifeq ($(shell uname),Darwin)
	LIBS = -framework OpenGL -framework GLUT
else
ifeq ($(shell uname),Linux)
	LIBS = -lglut -lGLU -lGL
else 
	LIBS = -lglu32 -lfreeglut -lopengl32
endif
endif

all: $(PROG)

$(PROG): 	$(SRCS)
	$(CC) -o $(PROG) $(SRCS) $(LIBS)
clean:
	rm -f $(PROG)
CPP = "g++"
CPPFLAGS =
GLFLAGS = -lglut -lglui -lGL -lGLU
MACFLAGS = -framework OpenGL -framework GLUT -lglui
XMLPARSE = tinystr.cpp tinyxml.cpp tinyxmlerror.cpp tinyxmlparser.cpp


mac:
	$(CPP) $(CPPFLAGS) Assignment3.cpp Camera.cpp SceneParser.cpp $(XMLPARSE) $(MACFLAGS) -o Assignment3

linux:
	$(CPP) $(CPPFLAGS) Assignment3.cpp Camera.cpp SceneParser.cpp $(XMLPARSE) $(GLFLAGS) -o Assignment3

clean:
	rm -rf *.o Assignment3

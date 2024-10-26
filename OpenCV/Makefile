CC=g++
CFLAGS=`pkg-config --cflags --libs opencv4`
SOURCES=camera_detection.cpp
EXECUTABLE=cam

all: $(EXECUTABLE)

$(EXECUTABLE): $(SOURCES)
	$(CC) -o $(EXECUTABLE) $(SOURCES) $(CFLAGS)

clean:
	rm -f $(EXECUTABLE)


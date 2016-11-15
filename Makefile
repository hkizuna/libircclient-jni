TARGET=libircclient-jni.dylib
INCLUDES=-I./libircclient/include -I$(JAVA_HOME)/include -I$(JAVA_HOME)/include/darwin
LIBRARYS=-L./libircclient
CFLAGS=$(INCLUDES) -Wall

all: $(TARGET)

$(TARGET): IRCClient.o 
	gcc -shared -o $@ $^ $(LIBRARYS) -lircclient

clean:
	rm -rf $(TARGET) *.o

classes:
	rm *.class

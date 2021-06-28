CC = gcc
LD:=ld
CFLAGS = -I /usr/lib/jvm/java-8-openjdk-amd64/include/ -I /usr/lib/jvm/java-8-openjdk-amd64/include/linux/ -fpic
LDFLAGS:=-shared -fpic
OBJS = jvmti_evt_ex.o
TARGET = Jvmti_Evt_Ex.so
RM = rm -f

$(TARGET):$(OBJS)
	echo $(OBJS)
	$(LD) $(LDFLAGS) -o $(TARGET) $(OBJS)

$(OBJS):jvmti_evt_ex.cpp Stdafx.h jvmti_evt_ex.h
	@echo Compiling $< ...
	$(CC) -c $(CFLAGS) $< -o $@

.PHONY: clean

clean:
	$(RM) $(TARGET) $(OBJS)
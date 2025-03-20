BUILD=build
COMPILER=x86_64-w64-mingw32-gcc
OPTIONS=-mwindows
COMPILE=$(COMPILER) $(OPTIONS)

all: beep.exe

debug: OPTIONS += -g
debug: all

beep.exe: $(BUILD)/beep.o build
	$(COMPILE) -o $@ $(BUILD)/beep.o

$(BUILD)/beep.o: beep.c build
	$(COMPILE) -c -o $@ beep.c

clean:
	rm -r $(BUILD)

build:
	mkdir -p $(BUILD)
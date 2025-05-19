TARGET = $(firstword $(MAKECMDGOALS))
FILE = $(TARGET).cpp
OUT = $(TARGET).out

.PHONY: $(TARGET)

$(TARGET):
	g++-14 -std=c++23 -O2 -Wall src/$(FILE) -o $(OUT)
	@./$(OUT)
%:: ;




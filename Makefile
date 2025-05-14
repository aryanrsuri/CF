TARGET = $(firstword $(MAKECMDGOALS))
FILE = $(TARGET).cc
OUT = $(TARGET).out

.PHONY: $(TARGET)

$(TARGET):
	g++ -std=c++23 -O2 -Wall src/$(FILE) -o $(OUT)
	@./$(OUT)
%:: ;

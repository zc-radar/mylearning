CC := gcc
CFLAGS := -std=c11 -Wall -Wextra -Werror -O2
TARGET := student_mgmt
SRC := src/main.c

.PHONY: all run clean

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $^ -o $@

run: $(TARGET)
	mkdir -p data
	./$(TARGET)

clean:
	rm -f $(TARGET)
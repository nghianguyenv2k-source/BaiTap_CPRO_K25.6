# Compiler
CC = gcc

# Flags biên dịch
CFLAGS = -Wall -g

# Tên file thực thi
TARGET = App_Library

# Các file source
SRCS = main.c book.c

# Các file object (tạo từ SRCS)
OBJS = $(SRCS:.c=.o)

# Rule mặc định: build chương trình
all: $(TARGET)

# Tạo file thực thi từ object files
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Biên dịch từng file .c thành .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule clean: xóa file object và file thực thi
clean:
	rm -f $(OBJS) $(TARGET)
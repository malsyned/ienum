TARGET := ienum_example
SRC := \
       my_enum.c \
       other_enum.c \
       third_enum.c \
       $(TARGET).c

CFLAGS += -I..

.DEFAULT_GOAL := all

.PHONY: run
run: all
	./$(TARGET)

.PHONY: all
all: $(TARGET)

$(TARGET): $(SRC:%.c=%.o)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

%.o: %.c $(MAKEFILE_LIST)
	$(CC) $(CFLAGS) $(CPPFLAGS) -MD -MP -c -o $@ $<

.PHONY: clean
clean:
	rm -f *.o *.d $(TARGET)

-include $(wildcard *.d)

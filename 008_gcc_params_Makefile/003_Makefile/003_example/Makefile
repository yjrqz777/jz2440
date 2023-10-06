
objs = a.o b.o c.o

dep_files := $(patsubst %,.%.d, $(objs))
dep_files := $(wildcard $(dep_files))


CFLAGS = -Werror -I.

# -I:指定头文件路径

test: $(objs)
	gcc -o test $^

ifneq ($(dep_files), )
include $(dep_files)
endif



%.o:%.c
	gcc $(CFLAGS) -c -o $@ $< -MD -MF .$@.d

clean:
	rm -rf *.o test

distclean:
	rm $(dep_files)

.PHONY:clean
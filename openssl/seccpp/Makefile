CC = g++
CFLAGS =  -Wall -g
LDFLAGS = -lssl -lcrypto
# -g show error detail information


# wildcard: general char
SRCS = ${wildcard *.cpp}
# patsubst: ${patsubst pattern, replacement, text}
OBJS = ${patsubst %.cpp, %.o, ${SRCS}}
TARGET = openssl

# $@  == target file
# $^  == all depends files
# $<  == first depends file
# $?  == all depens files that are newer than the target file

all: ${TARGET}

${TARGET}: ${OBJS}
	${CC} ${CFLAGS} -o $@ $^ $(LDFLAGS)

# -c means : only to compare not link
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@ 

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET)

# g++   -lssl -lcrypto  openssl.cpp   -o openssl
# g++ -o openssl openssl3.cpp -lssl -lcrypto
# firmon@ubt:~/Dev/apue/apue_ubuntu/openssl/sec$ ./openssl 
# SHA256 hash of 'hello world': b94d27b9934d3e08a52e52d7da7dabfac484efe37a5380ee9088f7ace2efcde9
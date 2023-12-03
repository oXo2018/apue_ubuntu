#### The term *unbuffered* means that <font color= red> each `read` or `write` invokes a system call in the kernel </font>. These unbuffered I/O functions are not part of ISO C, but are part of POSIX.1 and the Single UNIX Specification.

#### Whenever we describe the sharing of resources among multiple processes, the concept of an atomic operation becomes important.

#### A file descriptor is a non-negative integer. When we open an existing file or create a new file, the kernel returns a file descriptor to the process. When we want to read or write a file, we identify the file with the file descriptor that was returned by open or create as an argument to either read or write.

#### By convention, UNIX System shells asssociate file descriptor 0 with the standard input of a process, file descriptor 1 with the standard output, and file descriptor 2 with the standard error. It is not a feature of the UNIX kernel.

#### Although their values are standardized by POSIX.1, the magic numbers 0,1 and 2 should be replaced in POSIX-compliant applications with the symbolic constants `STDIN_FILENO`, `STDOUT_FILENO`, and `STDERR_FILENO` to improve readability. These constants are defined in the `<unistd.h>` header.

#### File descriptors range from 0 through OPEN_MAX - 1. Many system subsequently increased this limit to 63. 
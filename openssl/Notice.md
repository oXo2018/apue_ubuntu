The `ldd program_name`command can help you view which dynamic link libraries a program needs, as well as the paths to these dynamic link libraries.

The `/usr/lib` directory is where most system-level shared library files are stroed in linux systems. These shared library files are typically dynamically linked by executable files at runtime to provide additional functionality. In this directory, you will find many files ending with `.so`, which are the shared library files. Shared library files contain functions and data that are shared for use by multiple programs.

`ldconfig` is a command in linux used to update the cache of dynamic linkers. In linux, dynamic link librares are stored in specifc directories, such as `lib` and `/usr/lib`. The `ldconfig` command scans these directories and creates a cache file containing information about these dynamic link libraries. This allows the systems to quickly locate the required dynamic link libraries when running programs, without needing to search the entire disk each time.

***

The `/etc/ld.so.conf.d` directory is used in linux systems to store configuration files for the dynamic linker. In this directory, each file corresponds to a configuration for the dynamic linker, and the file names typically end with `.conf`.

These configuration files are used to tell the dynamic linker which directories to search for dynamic linker libraries when a program is running. Each configuration file can specify one or more directories, and the dynamic linker will search these directories in the order specified in the file to find the dynamic link libraries.

Using the `/etc/ld.so.conf.d` directory makes it easy to manage the configuration of the dynamic linker. You can modify the search paths for dynamic link libraries by adding, removing, or editing configuration files, <font color="red"> without directly mofigying the `/etc/ld.so.conf` file. </font>

***
When you compile and install `Openssl 1.0` on the Linux platform, it will place the relevant files in `/usr/local/bin` and `/usr/local/lib`

Reference:
https://github.com/CyberHashira/Learn_OpenSSL
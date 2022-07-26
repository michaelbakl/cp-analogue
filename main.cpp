#include <unistd.h>
#include <fcntl.h>
#include <cerrno>
#include <sys/stat.h>
#include <cstring>
#include "exceptions/SysCallException.h"

const int BUFFER_SIZE = 4096;

int main(int argc, char *argv[]) {
    if(argc != 3){
        throw SysCallException(EINVAL, argv[0]);
    }
    char *input_file = argv[1];
    char *output_file = argv[2];
    struct stat input_stat;
    int fd1_mode;
    int j = 0;

    int fd1, fd2;
    char buffer[BUFFER_SIZE];
    char buffer_without_hole[BUFFER_SIZE];

    fd1 = open(input_file, O_RDONLY);

    if (fd1 < 0) {
        throw SysCallException(ENOENT, input_file);
    }

    if (stat(input_file, &input_stat) < 0) {
        throw SysCallException(EINVAL, input_file);
    }

    fd1_mode = input_stat.st_mode;

    fd2 = open(output_file, O_WRONLY | O_CREAT, fd1_mode);
    if (fd2 < 0) {
        throw SysCallException(ENOENT, output_file);
    }

    ssize_t readBytes;
    while ((readBytes = read(fd1, buffer, BUFFER_SIZE)) > 0) {
        for (int i = 0; i < readBytes; i++) {
            if (buffer[i] != '\0') {
                buffer_without_hole[j] = buffer[i];
                j++;
                if (j == BUFFER_SIZE) {
                    write(fd2, buffer_without_hole, BUFFER_SIZE);
                    j = 0;
                }
            }
        }
    }
    if (j > 0) {
        write(fd2, buffer_without_hole, j);
    }
    close(fd1);
    close(fd2);
}

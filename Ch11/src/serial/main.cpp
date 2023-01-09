#include <iostream>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    int com0 = open("/dev/ttyS0", O_RDWR);
    int com1 = open("/dev/ttyS1", O_RDWR);

    uint8_t send[3];
    send[0] = 'F';
    send[1] = 'U';
    send[2] = 'N';
    write(com0, send, 3);

    uint8_t receive[3];
    read(com1, &receive, 3);

    std::cout << "Received " << receive[0] << receive[1] << receive[2] << std::endl;

    return 0;
}
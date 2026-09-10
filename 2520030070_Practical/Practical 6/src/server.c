#include <stdio.h> // Provides printf()
#include <fcntl.h> // Provides O_RDONLY and O_WRONLY
#include <unistd.h> // Provides read(), write(), and close()
#include <sys/stat.h> // Provides mkfifo()

int main()
{
char message[100]; // Stores the message from client
int fd1, fd2; // File descriptors for the FIFOs

mkfifo("server_fifo", 0666); // Creates server FIFO
mkfifo("client_fifo", 0666); // Creates client FIFO

printf("Server waiting...\n");

fd1 = open("server_fifo", O_RDONLY); // Opens server FIFO for reading

read(fd1, message, sizeof(message)); // Reads message from client

printf("Client says: %s\n", message); // Displays client's message

close(fd1); // Closes server FIFO

// Send response
fd2 = open("client_fifo", O_WRONLY); // Opens client FIFO for writing
char response[] = "Hello Client, message received!";
write(fd2, response, sizeof(response)); // Sends response to client
close(fd2); // Closes client FIFO
}

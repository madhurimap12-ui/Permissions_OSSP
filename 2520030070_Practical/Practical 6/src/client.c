#include <stdio.h> // Provides printf() and fgets()
#include <fcntl.h> // Provides O_RDONLY and O_WRONLY
#include <unistd.h> // Provides read(), write(), and close()
#include <sys/stat.h> // Provides FIFO functions

int main()
{
char message[100]; // Stores the message entered by user
char response[100]; // Stores response from server
int fd1, fd2; // File descriptors for the FIFOs
printf("Enter message: ");

fgets(message, sizeof(message), stdin); // Reads message from user

// Send message to server
fd1 = open("server_fifo", O_WRONLY); // Opens server FIFO for writing
write(fd1, message, sizeof(message)); // Sends message to server
close(fd1); // Closes server FIFO

// Receive response from server
fd2 = open("client_fifo", O_RDONLY); // Opens client FIFO for reading
read(fd2, response, sizeof(response)); // Reads response from server
printf("Server says: %s\n", response);
// Displays server response
close(fd2);// Closes client FIFO
return 0;// Ends the program
}


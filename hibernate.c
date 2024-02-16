#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Check if the user is root
    if (getuid() != 0) {
        fprintf(stderr, "This script requires root privileges to execute.\n");
        return 1;
    }

    // Check if an argument is provided
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <state>\n", argv[0]);
        fprintf(stderr, "Valid parameters are:\n");

        // Open the file /sys/power/state
        FILE *file = fopen("/sys/power/state", "r");
        if (file == NULL) {
            perror("Error opening /sys/power/state");
            return 1;
        }

        // Read and display the contents of the file
        char buffer[100];
        while (fgets(buffer, sizeof(buffer), file) != NULL) {
            printf("%s", buffer);
        }

        fclose(file);
        return 1;
    }

    // Get the provided argument
    char *state = argv[1];

    // Check if the state exists in /sys/power/state
    char buffer[100];
    FILE *file = fopen("/sys/power/state", "r");
    if (file == NULL) {
        perror("Error opening /sys/power/state");
        return 1;
    }

    int found = 0;
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        // Compare the provided state with each line in the file
        if (strstr(buffer, state) != NULL) {
            found = 1;
            break;
        }
    }

    fclose(file);

    if (!found) {
        fprintf(stderr, "The parameter '%s' does not exist in /sys/power/state.\n", state);
        return 1;
    }

    // Execute the command to put the system into the specified state
    int fd = open("/sys/power/state", O_WRONLY);
    if (fd == -1) {
        perror("Error opening /sys/power/state");
        return 1;
    }

    if (write(fd, state, strlen(state)) == -1) {
        perror("Error writing to /sys/power/state");
        close(fd);
        return 1;
    }

    close(fd);
    return 0;
}

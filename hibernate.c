#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[]) {
    // Vérifier si l'utilisateur est root
    if (getuid() != 0) {
        fprintf(stderr, "Ce script nécessite des privilèges root pour exécuter.\n");
        return 1;
    }

    // Vérifier s'il y a un argument fourni
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <state>\n", argv[0]);
        fprintf(stderr, "Les paramètres valides sont :\n");

        // Ouvrir le fichier /sys/power/state
        FILE *file = fopen("/sys/power/state", "r");
        if (file == NULL) {
            perror("Erreur lors de l'ouverture de /sys/power/state");
            return 1;
        }

        // Lire et afficher le contenu du fichier
        char buffer[100];
        while (fgets(buffer, sizeof(buffer), file) != NULL) {
            printf("%s", buffer);
        }

        fclose(file);
        return 1;
    }

    // Récupérer le paramètre fourni en argument
    char *state = argv[1];

    // Vérifier si l'état existe dans /sys/power/state
    char buffer[100];
    FILE *file = fopen("/sys/power/state", "r");
    if (file == NULL) {
        perror("Erreur lors de l'ouverture de /sys/power/state");
        return 1;
    }

    int found = 0;
    while (fgets(buffer, sizeof(buffer), file) != NULL) {
        // Comparer l'état fourni avec chaque ligne du fichier
        if (strstr(buffer, state) != NULL) {
            found = 1;
            break;
        }
    }

    fclose(file);

    if (!found) {
        fprintf(stderr, "Le paramètre '%s' n'existe pas dans /sys/power/state.\n", state);
        return 1;
    }

    // Exécuter la commande pour mettre le système dans l'état spécifié
    int fd = open("/sys/power/state", O_WRONLY);
    if (fd == -1) {
        perror("Erreur lors de l'ouverture de /sys/power/state");
        return 1;
    }

    if (write(fd, state, strlen(state)) == -1) {
        perror("Erreur lors de l'écriture dans /sys/power/state");
        close(fd);
        return 1;
    }

    close(fd);
    return 0;
}

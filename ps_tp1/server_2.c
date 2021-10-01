#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdbool.h>
#include <signal.h>

/*Initialisation du booléen*/
bool running = 1;

/*Fonction stop_handler*/
void stop_handler(int sig)
{

    char str[sig];
    printf("Signal numéro:  ");
    printf("%i ", sig);
    printf("\n");
    printf("La boucle a été arrêtée");

    running = 0;
}

int main()
{

    struct sigaction sa;
    sa.sa_flags = 0;
    sa.sa_handler = &stop_handler;
    sigaction(SIGINT, &sa, NULL);

    printf("Boucle infinie\n");
    /*Boucle Infinie*/
    while (running)
    {
        /*Id des process*/
        pid_t process_id;
        pid_t p_process_id;
        process_id = getpid();
        p_process_id = getppid();
        printf("L'ID du process: %d\n", process_id);
        printf("L'ID du process père: %d\n", p_process_id);

        /*Nb aléatoire entre 0 et 99*/
        printf("Nombre aléatoire entre 0 et 99: %d\n", rand() % 99);

        /*Sleep*/
        printf("Endormissement pour 1 seconde\n");
        sleep(1);
        printf("\n");
    }

    printf("Fin de la boucle \n");
    return EXIT_SUCCESS;
}
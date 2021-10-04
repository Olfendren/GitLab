#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdbool.h>
#include <signal.h>
#include <sys/wait.h>

/* Question 2.1 Première partie. On peut déterminer l'origine du message par la valeur des PID retournés, 
les deux processus s'arrêtent avec Ctrl+C*/

/*Question 2.1 Deuxième Partie, on remarque qu'après avoir kill le process fils, le père continue d'exister*/

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

void exit_message()
{
    printf("I'll be back \n");
}

int main()
{
    /*Structure de Sigaction*/
    struct sigaction sa;
    sa.sa_flags = 0;
    sa.sa_handler = &stop_handler;
    sigaction(SIGINT, &sa, NULL);

    printf("Boucle infinie\n");
    /*Boucle Infinie*/

    pid_t process_id;
    pid_t p_process_id;
    pid_t process_idb;
    pid_t p_process_idb;
    pid_t pid = fork();
    if (pid > 0)
    {
        /* Un comportement quand je suis le fils*/
        process_id = getpid();
        p_process_id = getppid();
    }
    
    else if (pid == 0)
{
    // On est dans le fils
    printf("Mon PID est %i et celui de mon père est %i\n", getpid(), getppid());
}
else
{
    // On est dans le père
    printf("Mon PID est %i et celui de mon fils est %i\n", getpid(), pid);
}
int status;

wait(&status);


while (running)
{
    /*Id des process*/
    process_idb = getpid();
    p_process_idb = getppid();
    
    printf("L'ID du process boucle : %d\n", process_idb);
    printf("L'ID du process boucle père: %d\n", p_process_idb);

    /*Nb aléatoire entre 0 et 99*/
    printf("Nombre aléatoire entre 0 et 99: %d\n", rand() % 99);

    /*Sleep*/
    printf("Endormissement pour 1 seconde\n");
    sleep(1);
    printf("\n");
}
printf("Le fils renvoit le code %i \n",wait);
/*atexit pour le message de fin*/
atexit(exit_message);

return EXIT_SUCCESS;
}

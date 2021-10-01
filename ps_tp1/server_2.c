#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdbool.h>
#include <signal.h>

/*Question 1.2 Deuxième partie, avec la commande kill -s INT (code) le message d'arrêt de mon handler s'affiche*/

/*Question 1.2 Troisième partie, avec la commande kill -9 (code) le message d'arrêt de mon handler ne s'affiche pas, 
je ne pense pas que ce soit possible de faire tourner l'handler post-kill de cette façon (kill -9). 
Sigaction ne peut recevoir de signal SIGKILL ou SIGSTOP comme argument donc on ne peut pas forcer la lecture de l'handler.
Si on kill le process père, le terminal disparait*/

/*Question 1.2 Dernière Partie, après avoir retiré le changement de running, la fonction ne s'arrête pas après un Ctrl + C, ni après un kill.
La commande kill -9 réussit à arrêter le programme*/

/*Question 1.3 Message de fin, le message est affiché pour l'arrêt par Ctrl+C et Kill -s INT mais pas pour kill -9*/


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
    running=0;
}

void exit_message()
{
    printf("I'll be back \n");
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
    
   
    atexit(exit_message);

    printf("Fin de la boucle \n");
    return EXIT_SUCCESS;
}

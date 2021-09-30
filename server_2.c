#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdbool.h>
#include <signal.h>

/*Initialisation du booléen*/
bool running = 1;

/*Fonction stop_handler*/
static void stop_handler(int sig)
{
    
    char str[sig];
    printf("Signal numéro:  ");
    printf("%i ",sig);
    printf("\n");
    printf("La boucle a été arrêtée");
    
    running=0;
}



int main()
{

    struct sigaction sa;

    struct sigaction new_action, old_action;
    new_action.sa_handler = stop_handler;
    sigemptyset (&new_action.sa_mask);
    new_action.sa_flags = 0;

    /*Le message à afficher (si le booléen est true)*/
    if(running==1)
    {
        printf("Boucle Infinie, c'est parti\n");
        /*Boucle Infinie*/
        for (;;)
        {
            
            /* Vérification de la condition d'execution*/
            if(running==1)
            {
                
                /*Id des process*/
                pid_t process_id;
                pid_t p_process_id;
                process_id = getpid();
                p_process_id = getppid();
                printf("L'ID du process: %d\n",process_id);
                printf("L'ID du process père: %d\n",p_process_id);

                /*Nb aléatoire entre 0 et 99*/
                printf("Nombre aléatoire entre 0 et 99: %d\n", rand() % 99);

                /*Sleep*/
                printf("Endormissement pour 1 seconde\n");
                sleep(1);
                printf("\n"); 

               int returnvalue = sigaction(SIGINT, &sa,NULL);
                if (returnvalue==-1)
                {
                    printf("kek");
                }
                

            }
            else
            {
                printf("\n");
                return 0;
            }
            
        }          
    }
    
    
    printf("Fin de la boucle \n");
    return EXIT_SUCCESS;
     
}

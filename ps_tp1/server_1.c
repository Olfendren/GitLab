#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>


int main()
{

    /*Le message à afficher*/
    printf("Boucle Infinie, c'est parti\n");
        /*Boucle Infinie*/
        for (;;)
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
        }
    
    printf("Fin de la boucle \n");
    return EXIT_SUCCESS;
     
}

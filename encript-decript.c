/*
    CIFRA DE CESAR 
*/
#include <stdio.h>
#include <stdlib.h>

// Define o tamanho máximo do índice.
#define max_len 100

// Define uma função global de limpesa de acordo com o sistema.
#ifdef WIN32
    #define clean_screen system("cls")
#else
    #define clean_screen system("clear")
#endif

void cript(char message[max_len], long rotation);
void decript(char message[max_len], long rotation);


void main(void){
    char message[max_len];
    long rotation;
    int option;

    clean_screen;
    printf("==========CRIPTOGRAFIA==========\n");
        printf("Digite uma palavra: ");
        fgets(message, sizeof(message), stdin);
        printf("Quantas rotações: ");
        scanf("%ld", &rotation);
        printf("[1] Criptografar\n[2] Descriptografar\n");
        scanf("%d", &option);
        
        if(option < 1 || option > 2){
            clean_screen;
            printf("Opção inválida.");
            return;
        }
        else if(option == 1){
            // Chama função de criptografia.
            cript(message, rotation);
        }
        else if(option == 2){
            // Chama a função de descriptografia.
            decript(message, rotation);
        }
}


void cript(char message[max_len], long rotation){
    int control;
    /* Criptografia */
    for(int i = 0; message[i] !='\0'; i++){
        control = message[i];

        if(control >= 'a' && control <= 'z'){
            control = control-rotation;
            if(control < 'a'){
                control = control + 'z' - 'a' + 1;
            }
        }
        message[i] = control;
    }
    clean_screen;
    printf("\nCriptografado: %s\n", message);
}


void decript(char message[max_len], long rotation){
    int control;
    /* Descriptografia */
    for(int i = 0; message[i] != '\0'; i++){
        control = message[i];

        if(control >= 'a' && control <= 'z'){
            control = control+rotation;
            if(control > 'z'){
                // control = control - 'z' - 'a' - 1;
                control = 1 - 'a' -'z' - control;
            }
            message[i] = control;
        }
    }
    clean_screen;
    printf("\nDescriptografado: %s\n", message);
}

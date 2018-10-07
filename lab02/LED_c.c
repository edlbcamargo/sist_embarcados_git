/** Programa baseado no código disponibilizado em:
* Derek Molloy, Exploring Raspberry Pi: Interfacing to the Real World with Embedded Linux,
* Wiley 2016, ISBN 978-1-119-1868-1, http://www.exploringrpi.com/
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define GPIO_NUMBER "16"
#define GPIO4_PATH "/sys/class/gpio/gpio16/"
#define GPIO_SYSFS "/sys/class/gpio/"

void writeGPIO(char filename[], char value[]){
   FILE* fp;                           // cria um ponteiro fp
   fp = fopen(filename, "w+");         // abre o arquivo para escrita
   fprintf(fp, "%s", value);           // grava o valor no arquivo
   fclose(fp);                         // fecha o arquivo
}

int main(int argc, char* argv[]){
   if(argc!=2){                        // o nome do programa eh o argumento 1
      printf("Numero incorreto de argumentos\n");
      printf(" uso: ./LED_c comando\n");
      printf(" onde comando pode ser: setup, on, off, status, ou close\n");
      return 2;                        // numero invalido de argumentos
   }
   printf("Iniciando o programa em C para alterar a gpio %s.\n",GPIO_NUMBER);
   if(strcmp(argv[1],"setup")==0){
      printf("Habilitando a gpio\n");
      writeGPIO(GPIO_SYSFS "export", GPIO_NUMBER);
      usleep(100000);                  // aguarda 100ms
      writeGPIO(GPIO4_PATH "direction", "out");
   }
   else if(strcmp(argv[1],"close")==0){
      printf("Desabilitando a gpio\n");
      writeGPIO(GPIO_SYSFS "unexport", GPIO_NUMBER);
   }
   else if(strcmp(argv[1],"on")==0){
      printf("Acendendo o LED\n");
      writeGPIO(GPIO4_PATH "value", "1");
   }
   else if (strcmp(argv[1],"off")==0){
      printf("Desligando o LED\n");
      writeGPIO(GPIO4_PATH "value", "0");
   }
   else if (strcmp(argv[1],"status")==0){
      FILE* fp;                        // cria um ponteiro fp
      char line[80], fullFilename[100];
      sprintf(fullFilename, GPIO4_PATH "/value");
      fp = fopen(fullFilename, "rt");  // abre o arquivo para leitura de texto
      while (fgets(line, 80, fp) != NULL){
         printf("O estado do LED eh %s", line);
      }
      fclose(fp);
   }
   else{
      printf("Comando invalido!\n");
   }
   printf("Fim do programa em C.\n");
   return 0;
}


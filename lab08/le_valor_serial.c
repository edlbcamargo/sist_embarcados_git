#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<termios.h>   // biblioteca para comunicacao serial

int main(){
   int file, count, nValoresRecebidos, n;
   unsigned char receive[1000];         // cria um buffer para receber os dados
   
   if ((file = open("/dev/ttyACM0", O_RDWR | O_NOCTTY | O_NDELAY))<0){
      perror("UART: Falha ao abrir o arquivo.\n");
      return -1;
   }
   struct termios options;             // cria estruturas para configurar a comunicacao
   tcgetattr(file, &options);          // ajusta os parametros do arquivo
   // Configura a comunicacao
   // 115200 baud, 8-bit, enable receiver, no modem control lines
   options.c_cflag = B115200 | CS8 | CREAD | CLOCAL;
   options.c_iflag = IGNPAR | ICRNL;   // ignora erros de paridade
   tcflush(file, TCIFLUSH);            // descarta informacao no arquivo
   tcsetattr(file, TCSANOW, &options); // aplica alteracoes imediatamente
   
   nValoresRecebidos = 0;
   while ( nValoresRecebidos < 1000 ){
	   if ((count = read(file, (void*)receive, 1000))<0){        // recebe os dados
		   perror("Falha ao ler da entrada\n");
		   return -1;
       }
       for  ( n = 0; n < count; n++ ){
		   printf("recebeu %d %d : %d \n",nValoresRecebidos,count,receive[n]);
	   }
       nValoresRecebidos += count;
       usleep(100);                      // aguarda 100us
   }
   close(file);
   return 0;
}

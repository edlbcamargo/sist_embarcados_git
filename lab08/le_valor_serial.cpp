#include "MinhaSerial.h"

int main(){
   int nValoresRecebidos;
   float valor;
   MinhaSerial<int> conexaoSerial;

   conexaoSerial.AbreDispositivo("/dev/ttyACM0");
   conexaoSerial.IniciaColeta();
   
   nValoresRecebidos = 0;
   while ( nValoresRecebidos < 10 ){
	   conexaoSerial.RecebeMedida(valor);
       if ( valor >= 0 ) {
		   nValoresRecebidos++;
           printf("recebeu %d: %f \n",nValoresRecebidos, valor );
	   }
       usleep(50000);               // aguarda 50ms
   }
   conexaoSerial.ParaColeta();
   return 0;
}

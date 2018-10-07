/** Programa baseado no código disponibilizado em:
* Derek Molloy, Exploring Raspberry Pi: Interfacing to the Real World with Embedded Linux,
* Wiley 2016, ISBN 978-1-119-1868-1, http://www.exploringrpi.com/
*/

#include<iostream>
#include<fstream>
#include<string>
#include<unistd.h>
using namespace std;

#define GPIO_NUMBER "16"
#define GPIO_PATH "/sys/class/gpio/gpio16/"
#define GPIO_SYSFS "/sys/class/gpio/"

void writeGPIO(string path, string filename, string value){
   fstream fs;
   fs.open((path + filename).c_str(), fstream::out);
   fs << value;
   fs.close();
}

int main(int argc, char* argv[]){
   if(argc!=2){
      cout << "Numero incorreto de argumentos" << endl;
      cout << " uso: ./LED_c comando" << endl;
      cout << " onde comando pode ser: setup, on, off, status, ou close" << endl;
      return 2;
   }
   string cmd(argv[1]);
   cout << "Iniciando o programa em C++ para alterar a gpio " << GPIO_NUMBER << endl;

   if(cmd=="on"){
      cout << "Acendendo o LED" << endl;
      writeGPIO(string(GPIO_PATH), "value", "1");
   }
   else if (cmd=="off"){
      cout << "Desligando o LED" << endl;
      writeGPIO(string(GPIO_PATH), "value", "0");
   }
   else if (cmd=="setup"){
      cout << "Habilitando a gpio" << endl;
      writeGPIO(string(GPIO_SYSFS), "export", GPIO_NUMBER);
      usleep(100000);
      writeGPIO(string(GPIO_PATH), "direction", "out");
   }
   else if (cmd=="close"){
      cout << "Desabilitando a gpio" << endl;
      writeGPIO(string(GPIO_SYSFS), "unexport", GPIO_NUMBER);
   }
   else if (cmd=="status"){
      std::fstream fs;
      fs.open( GPIO_PATH "value", std::fstream::in);
      string line;
      while(getline(fs,line)) cout << "O estado do LED eh " << line << endl;
      fs.close();
   }
   else{
      cout << "Comando invalido!" << endl;
   }
   cout << "Fim do programa em C++." << endl;
   return 0;
}

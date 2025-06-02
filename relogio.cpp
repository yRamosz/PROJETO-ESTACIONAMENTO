#include <iostream>
#include <ctime>       // time(), localtime()
#include <windows.h>   // Sleep(), system("cls")
#include <string>
using namespace std;

struct Carro {
    string placa;
    int horaEntrada;
};

int calculaValor(int horas) {
    return horas * 5; // R$5 por hora
}

int main() {
    while (true) {
        time_t agora = time(0); 
        struct tm *horaLocal = localtime(&agora);

        int hora = horaLocal->tm_hour;
        int minuto = horaLocal->tm_min;
        int segundo = horaLocal->tm_sec;
        int totalHoras = hora * 3600 + minuto * 60 + segundo;
        
        system("cls"); 
        std::cout << "Relogio em tempo real:\n\n";
        std::cout << (hora < 10 ? "0" : "") << hora << ":"
                  << (minuto < 10 ? "0" : "") << minuto << ":"
                  << (segundo < 10 ? "0" : "") << segundo << std::endl;

        Sleep(1000);
        totalHoras = hora; 
    }

   



    
    return 0;
}

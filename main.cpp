#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Carro {
    string placa;
    int horaEntrada;
};

int calculaValor(int horas) {
    return horas * 5; // R$5 por hora
}

int main() {
    vector<Carro> estacionamento;
    int opcao;

    do {
        cout << "Sistema de Estacionamento\n";
        cout << "1 - Registrar entrada\n";
        cout << "2 - Registrar saída\n";
        cout << "3 - Mostrar carros estacionados\n";
        cout << "0 - Sair\n";
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        if(opcao == 1) {
            Carro c;
            cout << "Digite a placa do carro: ";
            cin >> c.placa;
            cout << "Digite a hora de entrada (0-23): ";
            cin >> c.horaEntrada;

            estacionamento.push_back(c);
            cout << "Entrada registrada.\n\n";

        } else if(opcao == 2) {
            string placaSaida;
            int horaSaida;
            cout << "Digite a placa do carro que vai sair: ";
            cin >> placaSaida;
            cout << "Digite a hora de saída (0-23): ";
            cin >> horaSaida;

            bool encontrado = false;
            for(vector<Carro>::iterator it = estacionamento.begin(); it != estacionamento.end(); ++it) {
                if(it->placa == placaSaida) {
                    encontrado = true;
                    int duracao = horaSaida - it->horaEntrada;
                    if(duracao < 0) duracao = 0; // Não deixar negativo
                    int valor = calculaValor(duracao);
                    cout << "Carro " << placaSaida << " ficou " << duracao << " horas.\n";
                    cout << "Valor a pagar: R$" << valor << "\n";

                    estacionamento.erase(it);
                    break;
                }
            }

            if(!encontrado) {
                std::cout << "Carro nao encontrado no estacionamento.\n";
            }

            cout << "\n";

        } else if(opcao == 3) {
            cout << "Carros atualmente estacionados:\n";
            if(estacionamento.empty()) {
                cout << "Nenhum carro estacionado.\n";
            } else {
                for(std::vector<Carro>::iterator it = estacionamento.begin(); it != estacionamento.end(); ++it) {
                    cout << "Placa: " << it->placa << ", Hora de entrada: " << it->horaEntrada << "\n";
                }
            }
            cout << "\n";
        }

    } while(opcao != 0);

    cout << "Saindo do sistema...\n";
    return 0;
}

#include <iostream>
using namespace std;

int main() {
    int opcao, escolha, placa, vagas[6] = {0, 0, 0, 0, 0, 0};
    int saidaV;
    char tipoVeiculo;
    double c = 0, m = 0;

    do {
        cout << "\nBEM VINDO AO ESTACIONAMENTO" << endl;
        cout << "1 - REGISTRAR ENTRADA DE VEICULO" << endl;
        cout << "2 - REGISTRAR SAIDA DE VEICULO" << endl;
        cout << "3 - LISTAR VEICULOS" << endl;
        cout << "4 - FECHAR ESTACIONAMENTO" << endl;
        cout << "0 - SAIR" << endl;
        cout << "Escolha uma opcao: ";
        cin >> opcao;

        if (opcao == 1) {
            int placaRepetida = -1;

            cout << "O veiculo eh uma moto(m) ou um carro(c): ";
            cin >> tipoVeiculo;

            if (tipoVeiculo == 'm' || tipoVeiculo == 'M') {
                m++;
            } else if (tipoVeiculo == 'c' || tipoVeiculo == 'C') {
                c++;
            }

            cout << "Digite a placa do veiculo (apenas os numeros): ";
            cin >> placa;

            // Verifica se a placa já está registrada
            for (int i = 0; i < 6; i++) {
                if (vagas[i] == placa) {
                    placaRepetida = i;
                    break;
                }
            }

            if (placaRepetida != -1) {
                cout << "Essa placa ja esta registrada na vaga " << (placaRepetida + 1) << ".\n";
            } else {
                cout << "Escolha sua vaga (1 a 6): ";
                cin >> escolha;
                escolha -= 1;

                if (escolha >= 0 && escolha < 6) {
                    if (vagas[escolha] == 0) {
                        vagas[escolha] = placa;
                        cout << "Veiculo guardado com sucesso na vaga " << (escolha + 1) << ".\n";
                    } else {
                        cout << "Essa vaga ja esta ocupada.\n";
                    }
                } else {
                    cout << "Vaga invalida.\n";
                }
            }

        } else if (opcao == 2) {
            cout << "Digite a placa do veiculo: ";
            cin >> saidaV;

            int posicaoEncontrada = -1;

            for (int i = 0; i < 6; i++) {
                if (vagas[i] == saidaV) {
                    vagas[i] = 0;
                    posicaoEncontrada = i;
                    cout << "Veiculo removido da vaga " << (i + 1) << " com sucesso.\n";
                    break;
                }
            }

            if (posicaoEncontrada == -1) {
                cout << "Placa nao encontrada nas vagas.\n";
            }

        } else if (opcao == 3) {
            cout << "\nVeiculos guardados nas vagas:\n";
            for (int i = 0; i < 6; i++) {
                cout << "Vaga " << (i + 1) << ": ";
                if (vagas[i] == 0) {
                    cout << "Vazia\n";
                } else {
                    cout << "Placa " << vagas[i] << "\n";
                }
            }

        } else if (opcao == 4) {
            cout << "\nFechando estacionamento...\n";
            cout << "Total de carros: " << c << endl;
            cout << "Total de motos: " << m << endl;

        } else if (opcao != 0) {
            cout << "Opcao invalida. Tente novamente.\n";
        }

    } while (opcao != 0);

    cout << "Sistema encerrado.\n";
    return 0;
}

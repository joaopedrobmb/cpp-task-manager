#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <typeinfo>

int main() // função que inicia o programa, que retorna sempre um número inteiro quando finalizado
{
    std::string linha;
    std::string comando;
    std::string tarefa;
    std::string numero_tarefa;
    int numero;
    std::unordered_map<int, std::string> lista;

    while (true)
    {
        std::cout << "> ";
        std::getline(std::cin, linha);

        std::istringstream entrada(linha);
        entrada >> comando;

        if (comando == "add")
        {
            entrada >> tarefa;

            numero = lista.size() + 1;
            lista[numero] = tarefa;
            std::cout << "Tarefa " << numero << ". " << tarefa << " adicionada com sucesso! \n";
        }

        if (comando == "list")
        {
            for (const auto &[numero, tarefa] : lista)
            {
                std::cout << numero << ". " << tarefa << '\n';
            }
        }

        if (comando == "done")
        {
            entrada >> numero_tarefa;
            int numero_tarefa_int = std::stoi(numero_tarefa);
            lista.erase(numero_tarefa_int);
        }
        if (comando == "sair")
        {
            break;
        }
    }
}
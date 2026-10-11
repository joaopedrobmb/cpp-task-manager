#include <iostream>
#include <string>
#include <vector>
#include <sstream>

int main() // função que inicia o programa, que retorna sempre um número inteiro quando finalizado
{
    std::string linha;
    std::string comando;
    std::string tarefa;
    std::string numero_tarefa;
    int numero;
    std::vector<std::string> lista;

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
            lista.push_back(std::to_string(numero) + " " + tarefa);
            std::cout << "Tarefa " << tarefa << " adicionada com sucesso! \n";
        }

        if (comando == "list")
        {
            for (const std::string &t : lista)
            {
                std::cout << t << '\n';
            }
        }

        if (comando == "done")
        {
            entrada >> numero_tarefa;

            for (std::string &t : lista)
            {
                size_t espaco = t.find(' ');

                if (espaco != std::string::npos)
                {
                    t.erase(0, espaco + 1);

                    if (t == numero_tarefa)
                    {
                    }
                }
                else
                {
                    t.clear();
                }
            }
        }
        if (comando == "sair")
        {
            break;
        }
    }
}
/*
Calculadora de média
Escreva um programa em C++ que leia 3 notas do usuário (números decimais) e exiba a média aritmética com 2 casas decimais.

Exemplo de saída esperada:

Digite a nota 1: 7.5
Digite a nota 2: 8.0
Digite a nota 3: 9.5
Media: 8.33
Dica: use cout << fixed << setprecision(2) para formatar a saída.
*/

#include <array>
#include <iomanip>
#include <iostream>

double calc_media(double n1, double n2, double n3) {
    return (n1 + n2 + n3) / 3;
}

int main() {

    std::array<double, 3> n{};

    for (std::size_t i = 0; i < 3; i++) {
        std::cout << "Digite a nota " << i + 1 << ": ";
        std::cin >> n.at(i);
    }

    std::cout << "Média: " << std::fixed << std::setprecision(2) << calc_media(n[0], n[1], n[2]) << '\n';

    return 0;
}

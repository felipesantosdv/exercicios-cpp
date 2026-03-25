/*
Validação de entrada com loop
Escreva um programa que leia números inteiros do usuário indefinidamente, até que ele digite 0. Ao final, exiba:

A quantidade de números lidos (sem contar o 0)
A soma total
O maior e o menor valor digitado
Exemplo de saída esperada:

Digite um número (0 para sair): 4
Digite um número (0 para sair): -2
Digite um número (0 para sair): 7
Digite um número (0 para sair): 1
Digite um número (0 para sair): 0

Quantidade: 4
Soma: 10
Maior: 7
Menor: -2
Dica: pense no valor inicial de "maior" e "menor" antes do loop. Que valor faz sentido usar?
*/

#include <cstdint>
#include <iostream>

void compare(std::int64_t &less_num, std::int64_t &great_num, const std::int64_t &num) {
    if (num > great_num)
        great_num = num;
    if (num < less_num)
        less_num = num;
}

int main() {

    std::uint16_t cont_num{};
    std::int64_t num{};
    std::int64_t sum_num{};
    std::int64_t less_num{INT64_MAX}, great_num{INT64_MIN};

    while (true) {
        std::cout << "Digite um número (0 para sair): ";
        std::cin >> num;

        if (num == 0)
            break;
        cont_num++;
        compare(less_num, great_num, num);
        sum_num += num;
    }

    std::cout << "Quantidade: " << cont_num << '\n';
    std::cout << "Soma: " << sum_num << '\n';
    std::cout << "Maior: " << great_num << '\n';
    std::cout << "Menor: " << less_num << '\n';

    return 0;
}

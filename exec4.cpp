/*
Conta bancária com classes
Implemente uma classe ContaBancaria com as seguintes características:

Atributos privados: titular (string), saldo (double), numero (int)
Construtor que recebe titular e número — saldo começa em 0
Métodos: depositar(valor), sacar(valor) (retorna bool, falha se saldo insuficiente), exibir()
Sobrecarga do operador << para imprimir a conta
No main, crie 2 contas, faça algumas operações e exiba o estado final com std::cout << conta.

Exemplo de saída esperada:

Conta #1001 | Titular: Ana | Saldo: R$ 350.00
Conta #1002 | Titular: Bruno | Saldo: R$ 0.00
Saque de R$500.00 na conta de Bruno: negado (saldo insuficiente)
Dica: o operador << deve ser uma friend function ou acessar apenas métodos públicos da classe.
*/

#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <string>

class ContaBancaria {
  public:
    ContaBancaria(const std::string &titular, const std::uint32_t &numero) : titular_{titular}, numero_{numero} {
        saldo_ = 0.0;
    }
    ~ContaBancaria() = default;

    void depositar(const double &valor) {}
    bool sacar(const double &valor) {
        return false;
    }
    void exibir() const {
        std::cout << "Conta #" << numero_ << " | Titular: " << titular_ << " | Saldo: R$ " << saldo_ << '\n';
    }

  private:
    std::string titular_;
    double saldo_;
    std::uint32_t numero_;
};

int main() {

    ContaBancaria conta_a("Felipe", 1);
    ContaBancaria conta_b("Ana", 2);
    return EXIT_SUCCESS;
}

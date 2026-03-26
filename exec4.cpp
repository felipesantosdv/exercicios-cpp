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
#include <ostream>
#include <string>

class ContaBancaria {
  public:
    ContaBancaria(const std::string &titular, std::uint32_t numero) : titular_{titular}, numero_{numero} {
        saldo_ = 0.0;
    }
    ~ContaBancaria() = default;

    void depositar(double valor) {
        saldo_ += valor;
    }

    bool sacar(double valor) {
        if (saldo_ - valor < 0.0) {
            std::cerr << "Saque de R$ " << valor << " na conta de " << titular_ << ": acesso negado (saldo insuficiente)" << '\n';
            return false;
        }
        saldo_ -= valor;
        return true;
    }

    friend std::ostream &operator<<(std::ostream &out, const ContaBancaria &c) {
        out << "Conta #" << c.numero_ << " | Titular: " << c.titular_ << " | Saldo: R$ " << c.saldo_ << '\n';
        return out;
    }

  private:
    std::string titular_;
    double saldo_;
    std::uint32_t numero_;
};

int main() {

    ContaBancaria conta_a("Felipe", 1);
    ContaBancaria conta_b("Ana", 2);

    conta_a.depositar(1500.0);
    conta_b.depositar(500.0);

    conta_a.sacar(1000.0);
    conta_b.sacar(1000.0);

    std::cout << conta_a;
    std::cout << conta_b;

    return EXIT_SUCCESS;
}

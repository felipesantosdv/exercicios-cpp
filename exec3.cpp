/*
Cadastro de alunos com struct
Crie um programa que cadastre N alunos (N informado pelo usuário). Para cada aluno, armazene nome e 3 notas em uma struct. Ao final, exiba:

A média de cada aluno e sua situação: Aprovado (média ≥ 6), Recuperação (≥ 4) ou Reprovado (< 4)
O nome do aluno com a maior média da turma
Exemplo de saída esperada:

Quantos alunos? 2

Aluno 1:
  Nome: Ana
  Nota 1: 7.0
  Nota 2: 8.5
  Nota 3: 6.5

Aluno 2:
  Nome: Bruno
  Nota 1: 3.0
  Nota 2: 4.0
  Nota 3: 3.5

--- Resultados ---
Ana: média 7.33 → Aprovado
Bruno: média 3.50 → Reprovado

Melhor aluno: Ana
Dica: use std::vector<Aluno> para armazenar os alunos e std::string para o nome. Lembre-se do std::getline ao ler strings com espaço.
*/

#include <algorithm>
#include <array>
#include <cstdint>
#include <iostream>
#include <limits>
#include <numeric>
#include <string>
#include <vector>

struct Student {
    enum class Status {
        Aprovado,
        Recuperacao,
        Reprovado
    };
    std::string name{};
    std::array<double, 3> notas{};
    double media{};
    Status status;

    std::string get_status() const {
        if (status == Status::Aprovado)
            return "Aprovado";
        else if (status == Status::Recuperacao)
            return "Recuperação";
        else
            return "Reprovado";
    }

    void calc_media() {
        media = std::accumulate(notas.begin(), notas.end(), 0.0) / 3;
        if (media >= 6) {
            status = Status::Aprovado;
        } else if (media >= 4) {
            status = Status::Recuperacao;
        } else {
            status = Status::Reprovado;
        }
    }
};

void print_students(const std::vector<Student> &students) {
    std::cout << '\n';
    for (const auto &student : students) {
        std::cout << student.name << ": " << student.media << " -> " << student.get_status() << '\n';
    }

    auto it = std::max_element(students.begin(), students.end(), [](const Student &a, const Student &b) {
        return a.media < b.media;
    });

    std::cout << "\nMelhor aluno: " << it->name << '\n';
}

int main() {

    std::vector<Student> students{};
    Student student{};
    std::uint32_t n{}, i{};

    std::cout << "Digite quantos alunos deseja cadastrar: ";
    std::cin >> n;

    while (i < n) {
        std::cout << "ALUNO " << i + 1 << '\n';

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        std::cout << "Nome: ";
        std::getline(std::cin, student.name);

        std::cout << "Nota 1: ";
        std::cin >> student.notas[0];

        std::cout << "Nota 2: ";
        std::cin >> student.notas[1];

        std::cout << "Nota 3: ";
        std::cin >> student.notas[2];

        student.calc_media();
        students.emplace_back(student);
        i++;
    }

    print_students(students);
    return 0;
}

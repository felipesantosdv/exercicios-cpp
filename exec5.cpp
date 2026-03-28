/*
Formas geométricas
Crie uma hierarquia de classes para formas geométricas:

Classe base abstrata Forma com métodos virtuais puros area() e perimetro(), e um método virtual descricao() que imprime o nome da forma, área e perímetro
Classes derivadas: Circulo (raio), Retangulo (largura e altura), Triangulo (três lados — use Heron para a área)
No main, crie um std::vector<std::unique_ptr<Forma>> com uma instância de cada forma e chame descricao() em todas via loop
Exemplo de saída esperada:

Circulo    | Area: 78.54  | Perimetro: 31.42
Retangulo  | Area: 24.00  | Perimetro: 20.00
Triangulo  | Area: 6.00   | Perimetro: 12.00
Dica: destrutor virtual na classe base é obrigatório ao usar polimorfismo com ponteiros. Use std::make_unique<Circulo>(...) para criar as instâncias.
*/

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <vector>

class Forma {
  private:
  public:
    Forma() = default;
    virtual ~Forma() = default;

    virtual double area() = 0;

    virtual double perimetro() = 0;

    virtual void descricao() {}
};

class Circulo : public Forma {
  private:
    double raio_;
    static constexpr double PI = 3.141592653589793;

  public:
    Circulo(double raio) : raio_{raio} {
        if (raio < 0.0)
            raio_ = 0.0;
    }
    ~Circulo() = default;

    double area() override {
        return PI * raio_ * raio_;
    }

    double perimetro() override {
        return 2 * PI * raio_;
    }

    void descricao() override {
        std::cout << "Círculo   |  Área: " << area() << "  |  Perímetro: " << perimetro() << '\n';
    }
};

class Retangulo : public Forma {
  private:
    double lado_;
    double altura_;

  public:
    Retangulo(double lado, double altura) : lado_{lado}, altura_{altura} {
        if (lado < 0.0 || altura < 0.0) {
            lado_ = 0.0;
            altura_ = 0.0;
        }
    }
    ~Retangulo() = default;

    double area() override {
        return lado_ * altura_;
    }

    double perimetro() override {
        return (lado_ * 2) + (altura_ * 2);
    }

    void descricao() override {
        std::cout << "Retângulo   |  Área: " << area() << "  |  Perímetro: " << perimetro() << '\n';
    }
};

class Triangulo : public Forma {
  private:
    double a_;
    double b_;
    double c_;

  public:
    Triangulo(double a, double b, double c) : a_{a}, b_{b}, c_{c} {
        if (a < 0.0 || b < 0.0 || c < 0.0) {
            a_ = 0.0;
            b_ = 0.0;
            c_ = 0.0;
        }
    }
    ~Triangulo() = default;

    double area() override {
        double p = (a_ + b_ + c_) / 2;
        return sqrt(p * (p - a_) * (p - b_) * (p - c_));
    }

    double perimetro() override {
        return a_ + b_ + c_;
    }

    void descricao() override {
        std::cout << "Triângulo   |  Área: " << area() << "  |  Perímetro: " << perimetro() << '\n';
    }
};

int main() {

    std::vector<std::unique_ptr<Forma>> formas{};
    auto circulo{std::make_unique<Circulo>(3.0)};
    auto retangulo{std::make_unique<Retangulo>(4.0, 2.0)};
    auto triangulo{std::make_unique<Triangulo>(3.1, 3.2, 4.4)};
    formas.reserve(3);
    formas.emplace_back(std::move(circulo));
    formas.emplace_back(std::move(retangulo));
    formas.emplace_back(std::move(triangulo));

    for (const auto &forma : formas) {
        forma->descricao();
    }

    return EXIT_SUCCESS;
}

#include <iostream>
#include <random>

using namespace std;
class Polynomial
{
public:
    Polynomial(int t = 0);
    Polynomial &operator=(const Polynomial &r);
    ~Polynomial();
    double F1a(double x);
    double F1b(double x, int index = 0);
    double F2a(double x);
    double F2b(double x, int index = 0);
    double GetCoef(int pos) { return coefArray[pos]; }
    int GetTerms() { return terms; }

private:
    double *coefArray;
    int capacity;
    int terms;
};

// 默认构造函数
Polynomial::Polynomial(int t) : terms(t)
{
    capacity = (terms == 0) ? 1 : t;
    coefArray = new double[capacity];
    default_random_engine generator(time(0));
    uniform_real_distribution<double> distribution(0, 10);
    for (int i = 0; i < terms; i++)
    {
        double randomValue = distribution(generator); // 生成随机数并填充到数组
        coefArray[i] = stod(to_string(randomValue).substr(0, 4));
    }
}

Polynomial &Polynomial::operator=(const Polynomial &r)
{
    terms = r.terms;
    capacity = (terms == 0) ? 1 : terms;
    delete[] coefArray;
    coefArray = new double[capacity];
    copy(r.coefArray, r.coefArray + terms, coefArray);
    return *this;
}

// 析构函数
Polynomial::~Polynomial()
{
    delete[] coefArray;
}

ostream &operator<<(ostream &os, Polynomial &r)
{
    for (int Pos = 0; Pos < r.GetTerms() - 1; Pos++)
    {
        os << r.GetCoef(Pos);
        os << (r.GetCoef(Pos) ? " * x^" : "\bx^");
        os << r.GetTerms() - Pos - 1 << " + ";
        os << (r.GetTerms() - Pos - 1 == 1 ? "\b\b\b\b\b + " : "");
    }
    os << r.GetCoef(r.GetTerms() - 1);
    return os;
}
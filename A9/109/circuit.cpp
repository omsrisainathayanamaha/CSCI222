#include <iostream>
using namespace std;

class ResonantCircuit {
private:
    double omega, B, k;

public:
    ResonantCircuit(double o, double b, double r) : omega(o), B(b), k(r) {}

    double getOmega() { return omega; }
    double getB() { return B; }
    double getk() { return k; }

    void setOmega(double o) { omega = o; }
    void setB(double b) { B = b; }
    void setk(double v) { k = v; }

    virtual void display() {
        cout << "Omega, B, k: " << omega << ", " << B << ", " << k << endl;
    }

 
};

class ParallelResonantCircuit : public ResonantCircuit {
private:
    double R, C, L;

public:
    ParallelResonantCircuit(double o, double b, double r) : ResonantCircuit(o, b, r) {
        R = getk();
        C = 1.0 / (getB() * R);
        L = 1.0 / (getOmega() * getOmega() * C);
    }

    void display() override {
        ResonantCircuit::display();
        cout << "RCL: " << R << ", " << C << ", " << L << endl;
    }
};

class SeriesResonantCircuit : public ResonantCircuit {
private:
    double R, C, L;

public:
    SeriesResonantCircuit(double o, double b, double r) : ResonantCircuit(o, b, r) {
        R = getk();
        L = R / getB();
        C = 1.0 / (getOmega() * getOmega() * L);
    }

    void display() override {
        ResonantCircuit::display();
        cout << "RCL: " << R << ", " << C << ", " << L << endl;
    }
};

int main() {
    SeriesResonantCircuit s(1.0, 2.0, 4.0);
    ParallelResonantCircuit p(3.0, 57.4, 2.0);

    s.display();
    p.display();

    return 0;
}

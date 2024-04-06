#include "Abono.h"
#include "Cliente.h"
#define DIM 5
class Cuenta{
    private:
        int numeroCuenta;
        Cliente *cliente;
        Abono *lstabono[DIM];
        float saldo;
        int contadorAbono;
    public:
        Cuenta();
        Cuenta(int , Cliente*);
        int getNumeroCuenta();
        void setNumeroCuenta(int);
        Cliente *getCliente();
        void setCliente(Cliente*);
        bool agregarAbono(Abono*);
        Abono **getlstAbonos();
        float getSaldo();
        int getContadorAbonos();
};



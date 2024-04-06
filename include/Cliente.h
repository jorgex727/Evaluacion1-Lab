#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
#include <string.h>
#include <iostream>
using namespace std;
class Cliente{
    private:
        int idCliente;
        string nombre;
        string apellido;
    public:
        Cliente(int, string, string);
        int getIdCliente();
        string getNombre();
        string getApellido();
};


#endif // CLIENTE_H_INCLUDED

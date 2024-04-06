#include <iostream>
using namespace std;
#define DIM 5
#include "Cliente.h"
#include "Abono.h"
#include "Cuenta.h"
Cuenta::Cuenta(int n, Cliente *c){
    this->numeroCuenta=n;
    this->cliente=c;
}
int Cuenta::getNumeroCuenta(){
    return this->numeroCuenta;
}
void Cuenta::setNumeroCuenta(int n){
    this->numeroCuenta=n;
}
Cliente *Cuenta::getCliente(){
    return this->cliente;
}
void Cuenta::setCliente(Cliente *c){
    this->cliente=c;
}
bool Cuenta::agregarAbono(Abono *ab){
    bool resultado=false;
    if(this->contadorAbono<DIM){
        this->lstabono[this->contadorAbono] = ab;
        this->saldo+=ab->getMontoAbono();
        this->contadorAbono++;
        resultado=true;
    }else{
        cout << "No hay mas intentos de abono permitidos a esta cuenta limite alcanzado\n";
    }
    return resultado;
}
Abono **Cuenta::getlstAbonos(){
    return this->lstabono;
}
float Cuenta::getSaldo(){
    return this->saldo;
}
int Cuenta::getContadorAbonos(){
    return this->contadorAbono;
}

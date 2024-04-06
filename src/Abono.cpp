#include "Abono.h"
#include <iostream>
#include "Fecha.h"
using namespace std;

Abono::Abono(Fecha *f, float ma){
    this->fecha = f;
    this->montoAbono = ma;
}
Fecha *Abono::getFechaAbono(){
    this->fecha;
}
float Abono::getMontoAbono(){
    return this->montoAbono;
}

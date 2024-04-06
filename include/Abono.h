#ifndef ABONO_H_INCLUDED
#define ABONO_H_INCLUDED
#include "Fecha.h"
class Abono{
    private:
        Fecha *fecha;
        float montoAbono;
    public:
        Abono(Fecha*, float);
        Fecha *getFechaAbono();
        float getMontoAbono();
};


#endif // ABONO_H_INCLUDED

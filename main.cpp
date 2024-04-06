#include <iostream>
using namespace std;
#define TAM 5
#include "Cliente.h"
#include "Abono.h"
#include "Cuenta.h"
#include "stdlib.h"
int menu(){
    int op=0;
    cout << "MENU DE OPCIONES\n";
    cout << "1. Agregar cliente a la lista\n";
    cout << "2. Agregar cuenta a la lista.\n";
    cout << "3. Hacer abonos\n";
    cout << "4. Mostrar lista de clientes\n";
    cout << "5. Mostrar lista de cuentas\n";
    cout << "6. Mostrar detalles de la cuenta\n";
    cout << "7. Salir\n";
    cout << "Digite la opcion a realizar: ";
    cin >> op;
    return op;
}
Cliente *agregarCliente(){
    Cliente *cliente;
    int idCliente;
    string n, a;
    cout << "Ingrese el id del Cliente\n";
    cin >> idCliente;
    cout << "Ingrese el nombre del Cliente\n";
    cin >> n;
    cout << "Ingrese el apellido del Cliente\n";
    cin >> a;
    cliente = new Cliente(idCliente, n, a);
    return cliente;
}
Cliente *buscarCliente(Cliente *lst[], int id, int cont){
    Cliente *cliente=NULL;
    int contCliente=0;
    bool resultado=false;
    while(contCliente<cont && !resultado){
        if(lst[contCliente]->getIdCliente() == id){
            resultado=true;
            cliente=lst[contCliente];
        }
        else{
            contCliente++;
        }
    }
    return cliente;
}
Cuenta *agregarCuenta(Cliente *cliente){
    Cuenta *cuenta;
    int n=0;
    cout << "Ingrese el numero de cuenta: \n";
    cin >> n;
    cuenta = new Cuenta(n,cliente);
    return cuenta;
}
Cuenta *buscarCuenta(Cuenta *lst[], int id, int cont){
    Cuenta *cuenta=NULL;
    bool resultado=false;
    int contadorCuenta=0;
    while(contadorCuenta<cont && !resultado){
        if(lst[contadorCuenta]->getNumeroCuenta()==id){
            cuenta= lst[contadorCuenta];
            resultado=true;
        }else{
            contadorCuenta++;
        }
    }
    return cuenta;
}
void realizarAbono(Cuenta *cuenta){
    Abono *abono;
    Fecha *fecha;
    int d=0,m=0,a=0;
    float ma=0;
    cout << "Ingrese el dia de hoy: \n";
    cin >> d;
    cout << "ingrese el mes actual: \n";
    cin >> m;
    cout << "Ingrese el anio actual: \n";
    cin >> a;
    cout << "Ingrese el monto que desea abonar: \n";
    cin >> ma;
    fecha = new Fecha(d,m,a);
    abono = new Abono(fecha, ma);
    cuenta->agregarAbono(abono);
}
int main()
{
    Cliente *lstCliente[TAM];
    Cliente *cliente;
    Cuenta *lstCuenta[TAM];
    Cuenta *cuenta;
    Abono *lstAbono[TAM];
    Abono *abono;
    int opc=0, contClientes=0, contCuentas=0, idCliente=0, contAbono=0, idCuenta=0;
    do{
        system("cls");
        opc=menu();
        switch(opc){
            case 1:
                ///Agregar Cliente
                if(contClientes<TAM){
                    lstCliente[contClientes]=agregarCliente();
                    cout << "El Cliente fue agregado exitosamente\n";
                    contClientes++;
                }else{
                    cout << "La lista esta llena no es posible agregar mas clientes\n";
                }
                break;
            case 2:
                ///Agregar Cuenta
                if(contCuentas<TAM){
                    cout << "Ingrese el Id del Cliente\n";
                    cin >> idCliente;
                    if(contClientes==0){
                        cout << "La lista de clientes esta vacia no se puede agregar una cuenta\n";
                    }else{
                        cliente=buscarCliente(lstCliente, idCliente, contClientes);
                        if(cliente){
                            lstCuenta[contCuentas]= agregarCuenta(cliente);
                            cout << "La cuenta se agrego con exito\n";
                            contCuentas++;
                        }else{
                          cout << "El cliente no se encontro\n";
                        }
                    }
                }else{
                    cout << "La lista esta llena no se pueden agregar mas cuentas \n";
                }
                break;
            case 3:
                ///Hacer Abono
                    if(contCuentas==0){
                        cout << "No hay cuentas en existencia verificar mas tarde\n";
                    }else{
                        cout << "Ingrese el numero de cuenta que desea abonar: \n";
                        cin >> idCuenta;
                        cuenta = buscarCuenta(lstCuenta, idCuenta, contCuentas);
                        if(cuenta){
                            realizarAbono(cuenta);
                            cout << "El abono se agrego con exito\n";
                            contAbono++;
                        }else{
                            cout << "La cuenta no fue encontrada\n";
                        }
                    }
                break;
            case 4:
                ///Mostrar clientes
                if(contClientes==0){
                    cout << "No existen clientes registrados, lista vacia\n";
                }else{
                    cout << "Id\tNombre\tApellido\n";
                    for(int i=0; i<contClientes; i++){
                    cout << lstCliente[i]->getIdCliente() << "\t";
                    cout << lstCliente[i]->getNombre() << "\t";
                    cout << lstCliente[i]->getApellido() << "\n";
                    }
                }
                break;
            case 5:
                ///Mostras cuentas
                if(contCuentas==0){
                    cout << "No existen cuentas en el sistema intente mas tarde\n";
                }else{
                    cout << "No\tNombre\tApellido\tsaldo\n";
                    for(int i=0;i<contCuentas;i++){
                        cout << lstCuenta[i]->getNumeroCuenta() << "\t";
                        cout << lstCuenta[i]->getCliente()->getNombre() << "\t";
                        cout << lstCuenta[i]->getCliente()->getApellido() << "\t\t";
                        cout << lstCuenta[i]->getSaldo() << endl;
                    }
                }
                break;
            case 6:
                ///Mostrar detalles de cuentas
                break;
            case 7:
                ///
                cout << "Saliendo del sistema\n";
                break;
            default:
                cout << "Opcion no valida ingrese un numero dentro del rango de opciones habilitadas\n";
                break;
        }
        system("pause");
    }while(opc!=7);
    return 0;
}

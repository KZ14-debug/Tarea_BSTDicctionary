#include <iostream>
#include "BSTDictionary.h"
#include "Dictionary.h"
#include "LinkedList.h"
#include "List.h"
#include "Pair.h"
#include <stdexcept>
using namespace std;
using std::runtime_error;
using std::cout;
using std::cin;
using std::endl;
using std::string;


BSTDictionary<int, string>* seleccionarDiccionario(BSTDictionary<int, string>* diccio1, BSTDictionary<int, string>* diccio2)
{

    int opc;

    cout << "Seleccione diccionario (1 o 2): ";
    cin >> opc;

    if (opc == 1)
    {
        return diccio1;
    }

    return diccio2;

}



int main()
{


    BSTDictionary<int, string> diccionario1;
    BSTDictionary<int, string> diccionario2;

    int opc = 0;


    do
    {
        cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;
        cout << "\nDiccionario 1:" << endl;
        diccionario1.print();

        cout << "\nDiccionario 2:" << endl;
        diccionario2.print();
		cout << "\n" << endl;

        cout << "\n *-*-* MENU *-*-* " << endl;
        cout << "1. Insert" << endl;
        cout << "2. Remove" << endl;
        cout << "3. GetValue" << endl;
        cout << "4. SetValue" << endl;
        cout << "5. Contains" << endl;
        cout << "6. Clear" << endl;
        cout << "7. GetKeys" << endl;
        cout << "8. GetValues" << endl;
        cout << "9. Update" << endl;
        cout << "10. Zip" << endl;
        cout << "11. Salir" << endl;

        cout << "Seleccione una opcion: ";
        cin >> opc;

        cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*" << endl;

        try
        {

            switch (opc)
            {
            case 1:
            {


                BSTDictionary<int, string>* d = seleccionarDiccionario(&diccionario1, &diccionario2);

                int llave;
                string valor;
                cout << "\n *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n" << endl;
                cout << "Ingrese la llave: ";
                cin >> llave;
                cout << "\n" << endl;

                cout << "Ingrese el valor: ";
                cin >> valor;
                cout << "\n" << endl;

                d->insert(llave, valor);

                cout << "\n *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n" << endl;


                break;

            }

            case 2:
            {

                BSTDictionary<int, string>* d = seleccionarDiccionario(&diccionario1, &diccionario2);

                int llaveRemovida;

                cout << "\n *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n" << endl;

                cout << "Ingrese la llave a remover: ";
                cin >> llaveRemovida;
                cout << "\n" << endl;

                d->remove(llaveRemovida);

                cout << "\n *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n" << endl;


                break;

            }

            case 3:
            {

                BSTDictionary<int, string>* d = seleccionarDiccionario(&diccionario1, &diccionario2);

                int llave;

                cout << "\n *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n" << endl;

                cout << "Ingrese la llave: ";
                cin >> llave;

                cout << "El valor de la llave es: " << d->getValue(llave) << endl;

                cout << "\n *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n" << endl;

                break;

            }

            case 4:
            {

                BSTDictionary<int, string>* d = seleccionarDiccionario(&diccionario1, &diccionario2);

                int llave;
                string valor;

                cout << "\n *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n" << endl;

                cout << "Ingrese la llave: ";
                cin >> llave;

                cout << "Ingrese el nuevo valor: ";
                cin >> valor;


                d->setValue(llave, valor);

                cout << "\n *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n" << endl;



                break;

            }

            case 5:
            {

                BSTDictionary<int, string>* d = seleccionarDiccionario(&diccionario1, &diccionario2);

                int llave;
                string valor;

                cout << "\n *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n" << endl;

                cout << "Ingrese la llave: ";
                cin >> llave;

                if (d->contains(llave))
                {
					cout << "El diccionario si contiene a: " << llave << endl;
                }

                else
                {
                    cout << "El diccionario no contiene la llave" << endl;
                }

                cout << "\n *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n" << endl;

                break;

            }

            case 6:
            {

                BSTDictionary<int, string>* d = seleccionarDiccionario(&diccionario1, &diccionario2);

                d->clear();


                break;

            }

            case 7:
            {

                BSTDictionary<int, string>* d = seleccionarDiccionario(&diccionario1, &diccionario2);

                cout << "\n *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n" << endl;

                cout << "Llaves del diccionario: ";

                d->getKeys()->print();

                cout << "\n *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n" << endl;


                break;


            }

            case 8:
            {

                BSTDictionary<int, string>* d = seleccionarDiccionario(&diccionario1, &diccionario2);

                cout << "\n *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n" << endl;

                cout << "Valores del diccionario: ";

                d->getValues()->print();

                cout << "\n *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n" << endl;


                break;

            }

            case 9:
            {

                int opcD;

                cout << "\n *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n" << endl;

				cout << "Indique cual es el diccionario que desea actualizar (diccionario 1 o diccionario 2): ";
				cin >> opcD;


                if (opcD == 1)
                {

					diccionario1.update(&diccionario2);

                }

                else if(opcD == 2)
                {

					diccionario2.update(&diccionario1);

                }

                else
                {
					cout << "Opcion no valida" << endl;
                }

				cout << "El diccionario seleccionado fue actualizado" << endl;

                cout << "\n *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n" << endl;

                break;

            }

            case 10:
            {

                BSTDictionary<int, string>* d = seleccionarDiccionario(&diccionario1, &diccionario2);


                int cantidad;
                string valor;
                int llave;
                
                cout << "\n *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n" << endl;

                cout << "Ingrese la cantidad de elementos a añadir: ";
                cin >> cantidad;


                List<int>* llaves = new LinkedList<int>();
                List<string>* valores = new LinkedList<string>();


                cout << "\nIngrese las llaves de los elementos a añadir:" << endl;
                

                for (int i = 0; i < cantidad; i++)
                {

                    cin >> llave;

                    llaves->append(llave);

                }




                cout << "\nIngrese los valores de los elementos a añadir:" << endl;
                

                for (int i = 0; i < cantidad; i++)
                {

                    cin >> valor;

                    valores->append(valor);

                }


                d->zip(llaves, valores);

                cout << "\n *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n" << endl;


                break;

            }


            case 11:
            {
                cout << "\n *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n" << endl;

                cout << "Saliendo del sistema" << endl;

                cout << "\n *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n" << endl;

                break;
            }

            }

        }

        catch (exception& e)
        {
            cout << "Error: " << e.what() << endl;
        }

    } while (opc != 11);

}






























//BabyFace - Tender Lover
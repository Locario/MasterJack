#include <iostream>
#include <fstream>

using namespace std;

class controldegastos
{
public:
    void establecesueldo(int a);
    void establecegastos(int a, int b, int c, int d, int e, int f);
    void muestragastos();
    void menu();
private:
    int sueldo;
    int gastos;
    int queda;
    int coche;
    int movil;
    int visa;
    int comida;
    int gasolina;
    int abono;
};

void controldegastos::establecesueldo(int a)
{
    sueldo = a;

    ofstream file;
    file.open("file.dat", ios::out | ios::binary);

    file.write(reinterpret_cast<const char *>(&sueldo), sizeof(sueldo));
    file.close();
}

void controldegastos::establecegastos(int a, int b, int c, int d, int e, int f)
{
    coche = a;
    movil = b;
    visa = c;
    comida = d;
    gasolina = e;
    abono = f;

    gastos = a + b + c + d + e + f;

    ofstream file;
    file.open("file.dat", ios::out | ios::binary);

//    file.write((char *) &coche, sizeof(coche));

    file.write(reinterpret_cast<const char *>(&coche), sizeof(coche));
    file.write(reinterpret_cast<const char *>(&movil), sizeof(movil));
    file.write(reinterpret_cast<const char *>(&visa), sizeof(visa));
    file.write(reinterpret_cast<const char *>(&comida), sizeof(comida));
    file.write(reinterpret_cast<const char *>(&gasolina), sizeof(gasolina));
    file.write(reinterpret_cast<const char *>(&abono), sizeof(abono));
    file.write(reinterpret_cast<const char *>(&gastos), sizeof(gastos));
    file.close();
}

void controldegastos::muestragastos()
{
    ifstream file;
    file.open("file.dat", ios::in | ios::binary);

    if (!file)
        cout << "No se puede abrir el archivo...";

//    file.read((char *) &coche, sizeof(coche));

    file.read((char *) &coche, sizeof(coche));
    file.read((char *) &movil, sizeof(movil));
    file.read((char *) &visa, sizeof(visa));
    file.read((char *) &comida, sizeof(comida));
    file.read((char *) &gasolina, sizeof(gasolina));
    file.read((char *) &abono, sizeof(abono));
    file.read((char *) &gastos, sizeof(gastos));
    file.read((char *) &sueldo, sizeof(sueldo));
    file.close();

    cout << "Gastos de este mes :" << endl;
    cout << "---------------------" << endl;
    cout << endl;
    cout << "Coche : " << coche << endl;
    cout << "Comida : " << comida << endl;
    cout << "Abono : " << abono << endl;
    cout << "Gasolina : " << gasolina << endl;
    cout << "Seguro / Visa : " << visa << endl;
    cout << "Móvil : " << movil << endl;
    cout << endl;
    cout << "Sueldo : " << sueldo << endl;
    cout << "Gastos : " << gastos << endl;
    cout << "Te sobra : " << (sueldo - gastos) << endl;
    cout << endl;
}

void controldegastos::menu()
{
char eleccion;

cout << "Elige la opción :" << endl;
cout << "---------------------" << endl;
cout << "1.- Establecer sueldo." << endl;
cout << "2.- Establecer gastos." << endl;
cout << "3.- Mostrar informe." << endl;
cout << "4.- Salir del programa." << endl;
cout << endl;

cin >> eleccion;

        switch (eleccion)
            {
            case '1':
                int valor;
                cout << "Introduce un valor: "; cin >> valor; cout << endl;
                establecesueldo(valor);
                menu();
                break;
            case '2':
                int a, b, c, d, e, f;
                cout << "Introduce cuanto dinero vas a gastar en coche este mes : "; cin >> a; cout << endl;
                cout << "Introduce cuanto dinero vas a gastar en comida este mes : "; cin >> d; cout << endl;
                cout << "Introduce cuanto dinero vas a gastar en abono este mes : "; cin >> f; cout << endl;
                cout << "Introduce cuanto dinero vas a gastar en gasolina este mes : "; cin >> e; cout << endl;
                cout << "Introduce cuanto dinero vas a gastar en seguro/visa este mes : "; cin >> c; cout << endl;
                cout << "Introduce cuanto dinero vas a gastar en móvil este mes : "; cin >> b; cout << endl;
                establecegastos(a, b, c, d, e, f);
                menu();
                break;
            case '3':
                muestragastos();
                menu();
                break;
            case '4':
                return;
            default:
                cout << "Escoge una opción de las que ofrece el menú..." << endl;
                cout << endl;
                menu();
                break;
            }
}

int main()
{
    controldegastos miclase;
    miclase.menu();

    return 0;
}

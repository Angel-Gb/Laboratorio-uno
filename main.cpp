#include <iostream>
#include <cmath>

using namespace std;


int main() {
    int opcion;

    cout << "Seleccione un problema (1-16): ";
    cin >> opcion;

    switch (opcion) {
    case 1: {
        cout << "Problema 1: ";
        char caracter;
        cout << "Ingrese un caracter: ";
        cin >> caracter;

        if (isalpha(caracter)) {
            caracter = tolower(caracter);
            if (caracter == 'a' || caracter == 'e' || caracter == 'i' || caracter == 'o' || caracter == 'u') {
                cout << caracter << " es una vocal." << endl;
            } else {
                cout << caracter << " es una consonante." << endl;
            }
        } else {
            cout << "No es una letra." << endl;
        }
        break;
    }

    case 2: {
        cout << "Problema 2: ";
        int cantidad;
        cout << "Ingrese una cantidad de dinero: ";
        cin >> cantidad;

        int billetes[] = {50000, 20000, 10000, 5000, 2000, 1000};
        int monedas[] = {500, 200, 100, 50};
        int cantidad_billetes_monedas[sizeof(billetes) / sizeof(billetes[0]) + sizeof(monedas) / sizeof(monedas[0])] = {0};

        cout << "Desglose de billetes y monedas:" << endl;
        for (int i = 0; i < sizeof(billetes) / sizeof(billetes[0]); i++) {
            cantidad_billetes_monedas[i] = cantidad / billetes[i];
            cantidad %= billetes[i];
            cout << billetes[i] << " : " << cantidad_billetes_monedas[i] << endl;
        }
        for (int i = sizeof(billetes) / sizeof(billetes[0]); i < sizeof(billetes) / sizeof(billetes[0]) + sizeof(monedas) / sizeof(monedas[0]); i++) {
            cantidad_billetes_monedas[i] = cantidad / monedas[i - sizeof(billetes) / sizeof(billetes[0])];
            cantidad %= monedas[i - sizeof(billetes) / sizeof(billetes[0])];
            cout << monedas[i - sizeof(billetes) / sizeof(billetes[0])] << " : " << cantidad_billetes_monedas[i] << endl;
        }

        if (cantidad > 0) {
            cout << "Faltante: " << cantidad << endl;
        }
        break;
    }

    case 3: {
        cout << "Problema 3: ";
        int mes, dia;

        cout << "Ingrese el numero de mes: ";
                cin >> mes;

        cout << "Ingrese el dia: ";
                cin >> dia;

        switch (mes) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            if (dia >= 1 && dia <= 31) {
                cout << dia << "/" << mes << " es una fecha valida." << endl;
            } else {
                cout << dia << "/" << mes << " es una fecha invalida." << endl;
            }
            break;
        case 4: case 6: case 9: case 11:
            if (dia >= 1 && dia <= 30) {
                cout << dia << "/" << mes << " es una fecha valida." << endl;
            } else {
                cout << dia << "/" << mes << " es una fecha invalida." << endl;
            }
            break;
        case 2:
            if (dia >= 1 && dia <= 28) {
                cout << dia << "/" << mes << " es una fecha valida." << endl;
            } else if (dia == 29) {
                cout << dia << "/" << mes << " es valida en bisiesto." << endl;
            } else {
                cout << dia << "/" << mes << " es una fecha invalida." << endl;
            }
            break;
        default:
            cout << mes << " es un mes invalido." << endl;
            break;
        }
        break;
    }

    case 4: {
        cout << "Problema 4: ";
        int hora, minutos, duracion;

        cout << "Ingrese la hora (formato HHMM): ";
        cin >> hora;

        if (hora < 0 || hora >= 2400 || hora % 100 >= 60) {
            cout << hora << " es un tiempo invalido." << endl;
            break;
        }

        cout << "Ingrese la duracion (formato HHMM): ";
                cin >> duracion;

        if (duracion < 0 || duracion >= 2400 || duracion % 100 >= 60) {
            cout << duracion << " es un tiempo invalido." << endl;
            break;
        }

        int total = hora + duracion;
        int nueva_hora = total / 100;
        int nuevos_minutos = total % 100;

        if (nueva_hora >= 24) {
            nueva_hora -= 24;
        }

        cout << "La hora es " << (nueva_hora < 10 ? "0" : "") << nueva_hora << (nuevos_minutos < 10 ? "0" : "") << nuevos_minutos << "." << endl;
        break;
    }

    case 5: {
        cout << "Problema 5: ";
        int n;
        cout << "Ingrese un numero impar: ";
                cin >> n;

        if (n % 2 == 0) {
            cout << "El numero ingresado no es impar." << endl;
        } else {
            for (int i = 1; i <= n; i++) {
                int asteriscos = n - abs(n - 2 * i);
                for (int j = 0; j < asteriscos; j++) {
                    cout << "*";
                }
                cout << endl;
            }
        }
        break;
    }

    case 6: {
        cout << "Problema 6: ";
        int n;
        cout << "Ingrese el numero de elementos para la aproximacion de e: ";
        cin >> n;

        double e = 1.0;
        double factorial = 1.0;

        for (int i = 1; i <= n; i++) {
            factorial *= i;
            e += 1.0 / factorial;
        }

        cout << "e es aproximadamente: " << e << endl;
        break;
    }

    case 7: {
        cout << "Problema 7: ";
        int n;
        cout << "Ingrese un numero: ";
                cin >> n;

        long long a = 1, b = 1, suma = 0;

        while (a <= n) {
            if (a % 2 == 0) {
                suma += a;
            }
            long long temp = a;
            a = b;
            b += temp;
        }

        cout << "El resultado de la suma es: " << suma << endl;
        break;
    }

    case 8: {
        cout << "Problema 8: ";
        int a, b, c;
        cout << "Ingrese tres numeros a, b y c: ";
                cin >> a >> b >> c;

        int suma = 0;

        for (int i = 1; i < c; i++) {
            if (i % a == 0 || i % b == 0) {
                suma += i;
            }
        }

        cout << "m" << a << " + m" << b << " + ... = " << suma << endl;
        break;
    }

    case 9: {
        cout << "Problema 9: ";
        int numero;
        cout << "Ingrese un numero: ";
                cin >> numero;

        int suma = 0;
        int temp = numero;

        while (temp > 0) {
            int digito = temp % 10;
            int potencia = pow(digito, digito);
            suma += potencia;
            temp /= 10;
        }

        cout << "El resultado de la suma es: " << suma << endl;
        break;
    }

    case 10: {
        cout << "Problema 10: ";
        int n;
        cout << "Ingrese un numero n: ";
                cin >> n;

        int contador = 0;
        int numero = 2;

        while (contador < n) {
            bool es_primo = true;
            for (int i = 2; i <= sqrt(numero); i++) {
                if (numero % i == 0) {
                    es_primo = false;
                    break;
                }
            }
            if (es_primo) {
                contador++;
            }
            if (contador < n) {
                numero++;
            }
        }

        cout << "El primo numero " << n << " es: " << numero << endl;
            break;
    }

    case 11: {
        cout << "Problema 11: ";
        int n;
        cout << "Ingrese un numero n: ";
                cin >> n;

        int mcm = 1;

        for (int i = 1; i <= n; i++) {
            int maximo = max(i, mcm);
            int minimo = min(i, mcm);

            for (int j = maximo; ; j += maximo) {
                if (j % minimo == 0) {
                    mcm = j;
                    break;
                }
            }
        }

        cout << "El minimo común multiplo es: " << mcm << endl;
            break;
    }

    case 12: {
        cout << "Problema 12: ";
        int numero;
        cout << "Ingrese un numero: ";
                cin >> numero;

        int mayor_factor_primo = 2;

        while (numero > 1) {
            if (numero % mayor_factor_primo == 0) {
                numero /= mayor_factor_primo;
            } else {
                mayor_factor_primo++;
            }
        }

        cout << "El mayor factor primo de " << numero << " es: " << mayor_factor_primo << endl;
        break;
    }

    case 13: {
        cout << "Problema 13: ";
        int n;
        cout << "Ingrese un numero n: ";
                cin >> n;

        int suma = 0;

        for (int i = 2; i < n; i++) {
            bool es_primo = true;
            for (int j = 2; j <= sqrt(i); j++) {
                if (i % j == 0) {
                    es_primo = false;
                    break;
                }
            }
            if (es_primo) {
                suma += i;
            }
        }

        cout << "El resultado de la suma es: " << suma << endl;
        break;
    }

    case 14: {
        cout << "Problema 14: ";
        int mayor_palindromo = 0;
        int num1, num2;
        for (int i = 100; i <= 999; i++) {
            for (int j = 100; j <= 999; j++) {
                int producto = i * j;
                int inverso = 0;
                int temp = producto;
                while (temp > 0) {
                    inverso = inverso * 10 + temp % 10;
                    temp /= 10;
                }
                if (producto == inverso && producto > mayor_palindromo) {
                    mayor_palindromo = producto;
                    num1 = i;
                    num2 = j;
                }
            }
        }
        cout << num1 << "*" << num2 << "=" << mayor_palindromo << endl;
        break;
    }

    case 15: {
        cout << "Problema 15: ";
        int k;
        cout << "Ingrese un numero k: ";
                cin >> k;

        int semilla_mas_larga = 0;
        int terminos_mas_larga = 0;

        for (int i = 1; i < k; i++) {
            long long numero = i;
            int terminos = 1;

            while (numero != 1) {
                if (numero % 2 == 0) {
                    numero /= 2;
                } else {
                    numero = 3 * numero + 1;
                }
                terminos++;
            }

            if (terminos > terminos_mas_larga) {
                terminos_mas_larga = terminos;
                semilla_mas_larga = i;
            }
        }

        cout << "La serie mas larga es con la semilla: " << semilla_mas_larga << ", teniendo " << terminos_mas_larga << " términos." << endl;
            break;
    }

    case 16: {
        cout << "Problema 16: ";
        int k;
        cout << "Ingrese un numero k: ";
                cin >> k;

        int n = 1;
        int divisors = 0;

        while (true) {
            int triangular = n * (n + 1) / 2;

            for (int i = 1; i <= sqrt(triangular); i++) {
                if (triangular % i == 0) {
                    divisors += 2;
                }
            }

            if (divisors > k) {
                cout << "El numero es: " << triangular << " que tiene " << divisors << " divisores." << endl;
                    break;
            }

            n++;
            divisors = 0;
        }
        break;
    }

    default:
        cout << "Opcion no valida." << endl;
            break;
    }

    return 0;
}




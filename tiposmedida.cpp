/* Autor: Alexis Tercero
 * github: AlexisTercero55
 * Fecha: 12/12/21
 * Descripcion: 
 * -----------------------------------------------------------
 * Clase para tipos de medida
 * 
 * atributos:
 *         - unidad de medida: string
 *         - magnitud: double (numerico)
 * metodos:
 *       - constructor: inicializa unidad y magnitud
 *       - destructor
 *       - toString
 * sobrecarga de operadores:
 *      - +|-: suma de tipos de medida iguales
 *      - *: retorna un objeto cuya unidad de medida
 *           es la concatenacion de las dos unidades de medida
 *           separadas por el signo "*"
 *           y cuya magnitud es el producto de las magnitudes.
 *           ejemplo:
 *           1m * 3m = 3m*m != 3mm
 *       - /: retorna un objeto cuya unidad de medida
 *            es la concatenacion de las dos unidades de medida
 *            separadas por el signo "/"
 *            y cuya magnitud es el cociente de las magnitudes.
 *           ejemplo:
 *           1m / 3m = 1/3m/m 
 * -----------------------------------------------------------
 * */
// librerias
#include <iostream>
#include <string>

// definicion de la clase tipo de medida
class TipoMedida
{
    private:
        std::string unidad;// unidad de medida: metros, gramos, etc
       
    public:
        double magnitud;// magnitud: 1, 3, etc

    // metodos
        // constructor
        TipoMedida(std::string unidad, double magnitud)
        {
            this->unidad = unidad;
            this->magnitud = magnitud;
        }
        // destructor
        ~TipoMedida()
        {
            std::cout << "Destructor de  " + this->toString() << std::endl;
        }
        // cadena con el valor y la unidad de medida ejemplo: 1m
        std::string toString()
        {
            std::string cadena = std::to_string(magnitud) + unidad;
            return cadena;
        }
    // sobrecarga de operadores
        // tm es por TipoMedida
        TipoMedida operator+(TipoMedida tm)
        {
            // problema: necesita un error para que no se pueda sumar
            // unidades de medida distintas
            if(this->unidad != tm.unidad)
            {
                // error
                std::cout << "No se puede sumar unidades de medida distintas" << std::endl;
                //aborta compilacion
                exit(1);
            }
            return TipoMedida(this->unidad, this->magnitud + tm.magnitud);
        }

        TipoMedida operator-(TipoMedida tm)
        {
            // problema: necesita un error para que no se pueda sumar
            // unidades de medida distintas
            if(this->unidad != tm.unidad)
            {
                // error
                std::cout << "No se puede restar unidades de medida distintas" << std::endl;
                //aborta ejecucuion
                exit(1);
            }
            return TipoMedida(this->unidad, this->magnitud - tm.magnitud);
        }

        TipoMedida operator*(TipoMedida tm)
        {
            return TipoMedida(this->unidad + "*" + tm.unidad, this->magnitud * tm.magnitud);
        }
        // sobrecarga de operador '/' concatena unidad de medida con '/'
        TipoMedida operator/(TipoMedida tm)
        {
            return TipoMedida(this->unidad + "/" + tm.unidad, this->magnitud / tm.magnitud);
        }
};

int main()
{
    // test: 1m + 3m = 4m imprime 4m
    // intacia de clase tipo de medida
    TipoMedida tm1("m", 1);
    TipoMedida tm2("m", 3);
    TipoMedida tm3 = tm1 + tm2;
    std::cout<<tm3.toString()<<std::endl;
    tm3 = tm1 - tm2;
    std::cout<<tm3.toString()<<std::endl;

    // test: 1m * 3m = 3m*m imprime 3m*m
    TipoMedida tm4 = tm1 * tm2;
    std::cout<<tm4.toString()<<std::endl;

    // test: 1m + 2n = error
    // TipoMedida tm5("m", 1);
    TipoMedida tm6("n", 2);
    // TipoMedida tm7 = tm5 + tm6;// error

    //test: 1m / 3m = 1/3m/m imprime 1/3m/m
    TipoMedida tm8 = tm1 / tm2;
    std::cout<<tm8.toString()<<std::endl;

    // test: 1m / 2n imprime 1/2m/n
    TipoMedida tm9 = tm1 / tm6;
    std::cout<<tm9.toString()<<std::endl;

    return 0;
}
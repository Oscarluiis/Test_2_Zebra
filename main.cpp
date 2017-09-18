#include <iostream>
#include <list>
#include <fstream>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include "Libro.h"
#include "Evaluador.h"
#include "NodoBinario.h"

using namespace std;

//Escribe todos los datos del libro en un archivo con nombre nombre_archivo en la posicion dada


// Este ejercicio lo hice en base al que hicimos de los gatos, que fue una tarea de examen ya puesto.
//https://tostaka.slack.com/files/U11PMBX8D/F6XGPDNRM/resolviendo_un_examen2.cpp

//
//https://tostaka.slack.com/files/U11PMBX8D/F6RVA1666/registros_en_un_archivo_binario.cpp

int TAMANO_ARCHIVO = 100;
void escribir(string nombre_archivo, Libro*libro, int posicion)
{
    ofstream out (nombre_archivo.c_str(),ios::in);
    if(!out.is_open())
    {
        out.open(nombre_archivo.c_str());
    }
    out.seekp(posicion*TAMANO_ARCHIVO);
    out.write(libro->nombre.c_str(),40);
    out.write(libro->autor.c_str(),40);
    out.write((char*)&libro->existencias,20);

    out.close();
}

//Devuelve el libro guardado en el archivo en la posicion dada

// Este ejercicio lo hice en base al que hicimos de los gatos, que fue una tarea de examen ya puesto.
//https://tostaka.slack.com/files/U11PMBX8D/F6XGPDNRM/resolviendo_un_examen2.cpp

//
//https://tostaka.slack.com/files/U11PMBX8D/F6RVA1666/registros_en_un_archivo_binario.cpp

Libro* leer(string nombre_archivo, int posicion)
{
    char no[40];
    char au[40];
    int exis;

    ifstream in(nombre_archivo.c_str());
    in.seekg(posicion*TAMANO_ARCHIVO);

    in.read(no,40);
    in.read(au,40);
    in.read((char*)&exis,20);


    in.close();

    Libro *libro = new Libro(no, au,exis);
    return libro;
}

//Crea un mapa en base a las llaves y valores dados, asocia cada llave con los valores en la misma posicion

//Este lo hice con base en este archivo llamado "std::set/multiset"
// Aqui el link de slack: https://tostaka.slack.com/files/U11PMBX8D/F6T9A6PPF/std__set___multiset.cpp

map<string, int> convertirEnMapa(set<string> llaves, set<int> valores)
{
    map<string, int> respuesta;

    set<string>::iterator it = llaves.begin();
    set<int>::iterator ti = valores.begin();
    while(it!=llaves.end())
    {
        respuesta[*it] = *ti;
        ti++, it++;
    }
    return respuesta;
}

//Devuelve una cola con los mismos valores que el parametro exepto que no tiene el ultimo valor

//Este ejercicio se hizo en base a los ejercicios que estan en Slack llamados "STD::QUEUE" Y "STD::STACK"
//https://tostaka.slack.com/files/U11PMBX8D/F6SJWT5U1/std__queue.cpp
//https://tostaka.slack.com/files/U11PMBX8D/F6T96KW21/std__stack.cpp


queue<int> popBack(queue<int> cola)
{
    queue<int> reply;
    stack<int> replytime;
    stack<int> time;
    int add;
    while(!cola.empty())
    {
        add = cola.front();
        time.push(add);
        cola.pop();
    }
    time.pop();
    while(!time.empty())
    {
        add = time.top();
        replytime.push(add);
        time.pop();
    }
    while(!replytime.empty())
    {
        add = replytime.top();
        reply.push(add);
        replytime.pop();
    }
    return reply;
}

//Reemplaza todos los valores del arbol
void reemplazarValores(NodoBinario* raiz, int valor)
{
    if (raiz==NULL){
        return;
    }

    if(raiz->valor = valor){
    }

    reemplazarValores(raiz->derecho,valor);
    reemplazarValores(raiz->izquierdo,valor);
}

//Devuelve la cantidad de bits "encendidos" o con el valores de 1

//Este si lo investigue en el momento

//Fuente http://www.chw.net/foro/lenguajes-programacion/1049362-determinar-si-bit-apagado-encendido.html

bool estadodeBit(char valor, int pos)
{
    int mascara = 1;
    mascara = mascara<<pos;
    return valor & mascara;
}
int contarBits(char byte)
{
    int contarlos=0;
    for(int n=0;n<8;n++)
    {
        if(estadodeBit(byte,n)){
            contarlos++;
        }
    }
    return contarlos;
}

int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}
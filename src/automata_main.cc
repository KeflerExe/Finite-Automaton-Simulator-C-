/// Universidad de La Laguna
/// Escuela Superior de Ingeniería y Tecnología
/// Grado en Ingeniería Informática
/// Asignatura: Computabilidad y Algoritmia
/// Curso: 2º
/// Práctica 6: Autómatas finitos
/// Autor: Joel Oscar Martín Gutiérrez
/// Correo: alu0101473840@ull.es
/// Fecha: 07/11/2022
/// Archivo: automata_main.cc
/// Contiene la función main del proyecto que usa las diferentes clases y llama a otras funciones
/// para realizar las operaciones requeridas por el usuario.

#include <iostream>
#include <fstream>

#include "automata.h"

/// Función main encargada de crear el autómata correspondiente y de realizar las diferentes llamadas a funciones y métodos para obtener los resultados deseados por el usuario.
int main (int argc, char *argv[]) {
  Usage(argc, argv);
  Automata automata1;
  std::string nombre_archivo_automata = argv[1];
  std::string nombre_archivo_automata2 = argv[2];
  std::string nombre_archivo_cadenas = argv[3];
  std::string linea_extraida_automata;
  std::ifstream archivo_automata;
  archivo_automata.open(nombre_archivo_automata);
  getline(archivo_automata, linea_extraida_automata);
  automata1.InsertaElAlfabeto(linea_extraida_automata);
  getline(archivo_automata, linea_extraida_automata);
  int numero_total_estados = std::stoi(linea_extraida_automata);
  getline(archivo_automata, linea_extraida_automata);
  int identific_estado_arranque{0};
  if (linea_extraida_automata.size() == 1) {
    identific_estado_arranque = std::stoi(linea_extraida_automata);
  } else {
    std::cout << "Error crítico: debe existir uno y sólo un estado inicial para el autómata." << std::endl;
    exit(EXIT_SUCCESS);
  }
  int contador_lineas_automata{0};
  while (getline(archivo_automata, linea_extraida_automata)) {
    automata1.InsertaEstados(linea_extraida_automata, identific_estado_arranque, numero_total_estados);
    contador_lineas_automata += 1;
  }
  if (contador_lineas_automata != numero_total_estados) {
    std::cout << "Error crítico: debe existir una sola línea en el fichero para cada uno de los estados del autómata." << std::endl;
    exit(EXIT_SUCCESS);  
  }
  archivo_automata.close();
  Automata automata2;
  std::ifstream archivo_automata2;
  archivo_automata2.open(nombre_archivo_automata2);
  getline(archivo_automata2, linea_extraida_automata);
  automata2.InsertaElAlfabeto(linea_extraida_automata);
  getline(archivo_automata2, linea_extraida_automata);
  numero_total_estados = std::stoi(linea_extraida_automata);
  getline(archivo_automata2, linea_extraida_automata);
  identific_estado_arranque = 0;
  if (linea_extraida_automata.size() == 1) {
    identific_estado_arranque = std::stoi(linea_extraida_automata);
  } else {
    std::cout << "Error crítico: debe existir uno y sólo un estado inicial para el autómata." << std::endl;
    exit(EXIT_SUCCESS);
  }
  contador_lineas_automata = 0;
  while (getline(archivo_automata2, linea_extraida_automata)) {
    automata2.InsertaEstados(linea_extraida_automata, identific_estado_arranque, numero_total_estados);
    contador_lineas_automata += 1;
  }
  if (contador_lineas_automata != numero_total_estados) {
    std::cout << "Error crítico: debe existir una sola línea en el fichero para cada uno de los estados del autómata." << std::endl;
    exit(EXIT_SUCCESS);  
  }
  archivo_automata2.close();
  std::string cadena_extraida;
  std::ifstream archivo_cadenas;
  bool coincidencia_cadena_automata;
  bool coincidencia_cadena_automata2;
  archivo_cadenas.open(nombre_archivo_cadenas);
  while (getline(archivo_cadenas, cadena_extraida)) {
    coincidencia_cadena_automata = automata1.EvaluaString(cadena_extraida);
    coincidencia_cadena_automata2 = automata2.EvaluaString(cadena_extraida);
    automata1.ReiniciaLosEstadosActuales();
    automata2.ReiniciaLosEstadosActuales();
    if (coincidencia_cadena_automata == coincidencia_cadena_automata2) {
      std::cout << cadena_extraida << " ---> igual" << std::endl;
    } else {
      std::cout << cadena_extraida << " ---> distinto" << std::endl;
    }
  }

}
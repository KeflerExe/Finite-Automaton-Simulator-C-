/// Universidad de La Laguna
/// Escuela Superior de Ingeniería y Tecnología
/// Grado en Ingeniería Informática
/// Asignatura: Computabilidad y Algoritmia
/// Curso: 2º
/// Práctica 6: Autómatas finitos
/// Autor: Joel Oscar Martín Gutiérrez
/// Correo: alu0101473840@ull.es
/// Fecha: 07/11/2022
/// Archivo: automata_func.cc
/// Contiene las diferentes funciones que son llamadas desde el main encargadas de realizar ciertas funciones

#include <iostream>
#include <string>
#include <cassert>

/// Comprueba que los argumentos introducidos por línea de comandos sean los 
/// correctos, además de proporcionar ayuda en caso de que el usuario no sepa como se han de introducir los argumentos.
void Usage(int argc, char *argv[]) {
  if (argc != 4) {
    std::string parametro_introducido = argv[1];
    if (parametro_introducido == "--help") {
      std::cout << "--Automata" << std::endl;
      std::cout << "Modo de uso: ./automata_main fichero_entrada_automata fichero_entrada_cadenas" << std::endl;
      std::cout << "fichero_entrada_automata: Fichero de texto donde se define el autómata." << std::endl;
      std::cout << "fichero_entrada_cadenas: Fichero de texto donde se definen las cadenas a analizar por el autómata." << std::endl;
      exit(EXIT_SUCCESS);
    } else {
      std::cout << "--Automata " << std::endl;
      std::cout << "Modo de uso: ./automata_main fichero_entrada_automata fichero_entrada_cadenas" << std::endl << "Pruebe ./automata_main --help para más información" << std::endl;
      exit(EXIT_FAILURE);
    }
  }   
}
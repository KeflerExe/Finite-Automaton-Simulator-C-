/// Universidad de La Laguna
/// Escuela Superior de Ingeniería y Tecnología
/// Grado en Ingeniería Informática
/// Asignatura: Computabilidad y Algoritmia
/// Curso: 2º
/// Práctica 6: Autómatas finitos
/// Autor: Joel Oscar Martín Gutiérrez
/// Correo: alu0101473840@ull.es
/// Fecha: 07/11/2022
/// Archivo: automata.h
/// Contiene la clase Automata encargada de crear objetos tipo automata y de proporcionar métodos para los mismos.

#include <iostream>

#include "alfabeto.h"
#include "estado.h"
#include "transiciones.h"

#ifndef AUTOMATA_H
#define AUTOMATA_H

/// Clase Automata, encargada de crear y manejar los objetos tipo automata
class Automata {  
 public:
  /// Constructor 
  Automata() : alfabeto_{}, estados_{}, estados_actuales_{}, estado_arranque_{} {}

  /// Métodos que modifican los atributos de la clase autómata
  void InsertaElAlfabeto(const std::string& linea_extraida);
  void InsertaEstados(const std::string& linea_extraida, const int identificador_estado_arranque, const int numero_total_estados);
  void ReiniciaLosEstadosActuales();

  /// Métodos encargados de realizar las operaciones necesarias para el correcto funcionamiento del programa.
  Estado RetornaEstadoPorIdentificador(const int identificador) const;
  bool CompruebaQueElSimboloEstaEnAlfabeto(const char simbolo_extraido) const;
  bool EvaluaString(const std::string& linea_extraida);

  /// Sobrecarga de operadores
  bool operator<(const Automata& automatas) const {
    return estados_actuales_ < automatas.estados_actuales_;
  }
 private:
  Alfabeto alfabeto_; ///< Atributo tipo alfabeto en cual son almacenados los símbolos del lenguaje que reconoce el autómata
  std::vector<Estado> estados_; ///< Vector de estados en el cual se almacenarán todos los estados que componen el autómata
  std::set<Estado> estados_actuales_; ///< Set de estados usado en el análisis de cadenas el cual se encarga de almacenar los estados en el cual estamos actualmente en el recorrido
  Estado estado_arranque_; ///< Atributo tipo estado que almacena el estado de arranque del autómata
};

void Usage(int argc, char *argv[]);

#endif
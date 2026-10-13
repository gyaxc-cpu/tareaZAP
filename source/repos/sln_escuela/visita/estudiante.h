#pragma once
#define NOMINMAX
#define NO_REDEFINITION_OF_BYTE
#include "persona.h"
#include "conexionB.h"
#include <iostream>
#include <mysql.h>
#include <string>
using namespace std;
class estudiante : persona{
private: string codigo;
	   int id_estudiante = 0;
	   //constructor
public :
	estudiante(){}
	estudiante( string nom, string ape, string dir, int tel, string fn, int id_ts, string cod,int id_e) : persona(nom,ape,dir,tel,fn,id_ts) {
		codigo = cod;
		id_estudiante = id_e;
	}
	//metodos get y set
	// set(modificar atributo)
	void setId_estudiantes(int e) { id_estudiante = e;}
	void setCodigo(string c) { codigo = c; }
	void setNombres(string n) { nombres = n; }
	void setApellidos(string a) { apellidos = a; }
	void setDireccion(string d) { direccion = d; }
	void setTelefono(int t) { telefono = t; }
	void setFecha_Nacimiento(string f) { fecha_nacimiento = f; }
	void setId_Tipo_Sangre(int ts) { id_tipo_sangre = ts; }
	// get (mostrar el contenido del atributo)
	int getId_estudiante() { return id_estudiante; }
	string getCodigo() { return codigo; }
	string getNombres() { return nombres; }
	string getApellidos() {return apellidos; }
	string getDireccion() {return direccion; }
	int  getTelefono() { return telefono; }
	string getFecha_Nacimiento() { return fecha_nacimiento; }
	int getId_Tipo_Sangre() { return id_tipo_sangre; }
	//metodos
	void crear(){}
	void leer(){
		int q_estado = 0; 
		conexionB cn = conexionB();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.abrir_conexion();
		if (cn.getconector()) {
			cout << "___________Datos Del Estudiante__________" << endl;
			string consulta = "select * from estudiantes;";
			const char* c = consulta.c_str();
			q_estado = mysql_query(cn.getconector(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getconector());
				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << ","<<fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << fila[6] << "," << fila[7]<<endl;
				}
			}
		}
		else {
			cout << "xxx Fallo La Conexion xxx"<<endl;
		}
		cn. cerrar_conexion();

	}
	void actualizar(){}
	void borrar(){}
};





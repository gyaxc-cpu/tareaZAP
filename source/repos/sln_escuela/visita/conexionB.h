#pragma once
#include <mysql.h>
#include <iostream>
using namespace std;

class conexionB{
private: MYSQL* conector;
public :
	void abrir_conexion() {
		conector = mysql_init(0);
		conector = mysql_real_connect(conector, "localhost","root","Gladiss2809","db_escuela7+",3306,NULL,0);
			
		 
	}
	MYSQL* getconector() {
		return conector;
	}
	void cerrar_conexion() {
		mysql_close(conector);

   }
};


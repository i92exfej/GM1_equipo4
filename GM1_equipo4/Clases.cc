#include <iostream>
#include <cstdlib>
#include <string.h>
#include <list>

using namespace std;

struct Horario{
	string dias;
	string horas;
};

struct Premio{
	string nombre;
	string fecha;
	string descripcion;
};

struct Reconocimiento{
	string nombre;
	string fecha;
	string descripcion;
};

class Usuario{
	private:
		string password_;
		string DNI_;

	public:
		Usuario(string dni, string password);
		virtual string getDNI()=0;
		bool compruebaPassword();

};

class Monitor:public Usuario{
	private:
		string nombre_;
		string apellidos_;
		int telefono_;
		string fechaNacimiento_;
		string correo_;
		string direccion_;

	public:
		Monitor(string dni, string password,string nombre="",string apellidos="",int telefono=0,string fechaNacimiento="",string correo="",string direccion="");
		void setNombre(string nombre);
		void setApellidos(string apellido1, string apellido2)
		void setTelefono(int telefono);
		void setFechaNacimiento(string dia, string mes, string año);
		void setCorreo(string correo);
		void setDireccion(string direccion);
		string getDNI() override;
		string getNombre();
		string getApellidos();
		int getTelefono();
		string getFechaNacimiento();
		string getCorreo();
		string getDireccion();

		Incidencia setIncidencia(string nombre, string codigo,Ruta ruta, string descripcion);
		Ruta createRuta();
};

class Administrativo:public Usuario{
	private:
	//nada

	public:
		Administrativo(string dni, string password):Usuario(dni,password);
		string getDNI() override{
			return dni_;
		}

		void obtenerDatosParque(){
			Parque P;
			P=parque; //objeto de la clase parque declarado como global en el programa main
			cout<<"Nombre del parque: "<<P.Parque::mostrarNombre()<<endl;
			cout<<"Ubicacion del parque: "<<P.Parque::mostrarUbicacion<<endl;
			cout<<"Superficie del parque "<<P.Parque::mostrarSuperficie<<" hectareas"<<endl;
			cout<<"Zonas contenidas en el parque"<<P.Parque::mostrarZona<<endl;
			cout<<"Fecha de declaracion de parque natural: "<<P.Parque::mostrarFechaDeclaracion<<endl;
			cout<<"El parque ha obtenido los premios: "<<P.Parque::mostrarPremios<<endl;
			cout<<"El parque tiene los siguientes reconocimientos: "<<P.Parque::mostarReconocimientos<<endl;
			cout<<"El horario del parque es: "<<P.Parque::mostrarHorario<<endl;
			cout<<"Las rutas disponibles en el parque son: "<<P.Parque::mostrarRutas<<endl;

		};
		void setDatosParque(){
			Premio aux1; //Auxiliar del tipo struct Premio
			Reconocimiento aux2; //Auxiliar del tipo struct Reconocimiento
			Horario aux3; // Auxiliar del tipo struct Horario
			Parque P;
			P=parque; //objeto de la clase parque declarado como global en el programa main
			int opcion;

			cout<<"Elija opcion de modificacion:"<<endl;
			cout<<"1. Modificar horario"<<endl;
			cout<<"2. Borrar Premio"<<endl;
			cout<<"3. Añadir nuevo Premio"<<endl;
			cout<<"4. Borrar reconocimiento"<<endl;
			cout<<"5. Añadir nuevo reconocimiento"<<endl;
			cin>>opcion;
			switch(opcion){
			case 1:
				cout<<"Introduzca el nuevo horario: "<<endl;
				cout<<"Dias de apertura: "; getline(cin,aux3.dias);
				cout<<"\nHoras de trabajo :"; getline(cin,aux3.horas);
			if(!(P.Parque::cambiarhorario(aux3))){
				cout<<"Error cambiando el horario"<<endl;
			}
				break;
			case 2:
				if(P.Paque::borrarPremio()){
					cout<<"Premio borrado con exito"<<endl;
				}
				else{
					cout<<"Error al borrar premio"<<endl;
				}
				break;
			case 3:
				cout<<"Introduczca nuevo premio: "<<endl;
				cout<<"Introduzca nombre: "; cin>>aux1.nombre;
				cout<<"\nIntroduzca fecha: "; getline(cin,aux1.fecha);
				cout<<"\nIntroduzca descripcion: "; getline(cin,aux1.descripcion);
				if(P.Parque::añadirPremio(aux1)){
					cout<<"\nPremio introducido con exito"<<endl;
				}
				else{
					cout<<"Error al introducir premio"<<endl;
				}
				break;
			case 4:
				if(P.Parque::borrarReconocimiento()){
					cout<<"Reconocimiento borrado con exito;"<<endl;

				}
				else{
					cout<<"Borrado de reconocimiento fallido"<<endl;
				}
				break;
			case 5:
				cout<<"Introduczca nuevo reconocimiento: "<<endl;
				cout<<"Introduzca nombre: "; cin>>aux2.nombre;
				cout<<"\nIntroduzca fecha: "; getline(cin,aux2.fecha);
				cout<<"\nIntroduzca descripcion: "; getline(cin,aux2.descripcion);
				if(P.Parque::añadirReconocimiento(aux2)){
					cout<<"\nReconocimiento introducido con exito"<<endl;
				}
				else{
					cout<<"Error al introducir reconocimiento"<<endl;
				}
				break;
			default:
				cout<<"El numero introducido no se corresponde con ninguna opcion"<<endl;
			}
		};
		void obtenerDatosRutas(){
		 Parque P;
		 P=parque; //objeto de la clase parque declarado como global en el programa main
		 P.Parque::mostrarRutas();
		};

		void changeRuta(){
			Parque P;
			P=parque; //objeto de la clase parque declarado como global en el programa main
			P.Parque::borrarRuta();
		};

		Cliente setCliente(){
			string dni, nombre, apellidos, direccion, condicion;
			int telefono;
			Reserva reserva;
			cout<<"Introduzca dni: "; getline(cin,dni);
			cout<<"Introduzca nombre: "; getline(cin,nombre);
			cout<<"Introduzca apellidos: "; getline(cin,apellidos);
			cout<<"Introduzca direccion: "; getline(cin,direccion);
			cout<<"Introduzca condicion: "; getline(cin,condicion);
			cout<<"Introduzca numero de telefono: "; cin>>telefono;
			Cliente C(nombre,apellidos,dni,telefono,direccion,condicion,reserva);
		return C;
		};

		void setReserva(Cliente cliente){
			string codigo, dia, mes, año;
			Reserva aux;
			 Parque P;
			 P=parque; //objeto de la clase parque declarado como global en el programa main

			cout>>"Introduzca codigo de la reserva: "; cin>>codigo;
			cout>>"Introduzca fecha de la reserva: "<<endl;
			cout<<"\ndia: "; cin>>dia;
			cout<<"\nmes: "; cin>>mes;
			cout<<"\naño: "; cin>>año;
			aux.setCodigo(codigo);
			aux.setFecha(dia,mes,año);
			 P.Parque::mostrarRutas();
			cout<<"\nIntroduzca nombre de la ruta para la reserva:";
			cin>>nombre;
			Ruta R;
			R.Ruta::cambiarNombre(nombre);
			aux.setRuta(R);
			cliente.Cliente::setReserva(aux);
		};
		void getCliente(){
			bool encontrado=false;
			string dni;
			cout<<"Introduzca dni del cliente a buscar: "; cin>>dni;
			list<Cliente>::iterator itc;
			for(itc=clientes.begin();itc!=clientes.end();itc++){
				if(dni==(*itc).Cliente::getDNI()){
				cout<<"DNI: "<<(*itc).Cliente::getDNI()<<endl;
				cout<<"Nombre: "<<(*itc).Cliente::getnombre()<<endl;
				cout<<"Apellidos: "<<(*itc).Cliente::getapellidos()<<endl;
				cout<<"Telefono: "<<(*itc).Cliente::getTelefono()<<endl;
				cout<<"Direccion: "<<(*itc).Cliente::getDireccion()<<endl;
				cout<<"Condicion: "<<(*itc).Cliente::getCondicion()<<endl;
			encontrado=true;
			}}
if(encontrado==false){
	cout<<"El cliente con dni "<<dni<<" no se encuentra en el sistema"<<endl;
}
		};
		void getReserva(Cliente cliente){
			Reserva aux;
			Ruta R;
			aux=cliente.Cliente::getReserva();
			R=aux.Reserva::getRuta();
			cout<<"Codigo: "<<aux.getCodigo()<<endl;
			cout<<"Ruta: "<<R.mostrarNombre()<<endl;
			cout<<"Fecha: "<<aux.getFecha()<<endl;
		};

		void eliminarCliente(){
		bool encontrado=false;
		string dni;
		cout<<"Introduzca dni del cliente a buscar: "; cin>>dni;
		list<Cliente>::iterator itc;
		for(itc=clientes.begin();itc!=clientes.end();itc++){
			if(dni==(*itc).Cliente::getDNI()){
				clientes.remove(dni);
		encontrado=true;
		}}
if(encontrado==false){
cout<<"El cliente con dni "<<dni<<" no se encuentra en el sistema"<<endl;
}

		};
		void eliminarReserva(Cliente cliente){
			Reserva clear;
			cliente.Cliente::setReserva(clear);
		};

		Monitor setMonitor(){
		string dni, pass, nombre, ape1, ape2, dia, mes, año, correo, direccion;
		int telefono;
			cout<<"Introduca dni "; cin>>dni;
			cout<<"\nIntroduca contraseña del monitor "; cin>>pass;
	Monitor moni(dni,pass);
			cout<<"Introduzca nombre: "; cin<<nombre;
			cout<<"\nIntroduzca apellido1: "; cin>>ape1;
			cout<<"\nIntroduzca apellido2: "; cin>>ape2;
			cout<<"\nIntroduzca telefono: "; cin>>telefono;
			cout<<"\nIntroduzca dia de nacimiento: "; cin>>dia;
			cout<<"\nIntroduzca mes de nacimiento: "; cin>>mes;
			cout<<"\nIntroduzca año de nacimiento: "; cin>>año;
			cout<<"\nIntroduzca correo electronico: "; getline(cin,correo);
			cout<<"\nIntroduzca direccion: "; getline(cin,direccion);
		moni.Monitor::setApellidos(ape1,ape2);
		moni.Monitor::setNombre(nombre);
		moni.Monitor::setTelefono(telefono);
		moni.Monitor::setFechaNacimiento(dia,mes,año);
		moni.Monitor::setCorreo(correo);
		moni.Monitor::setDireccion(direccion);

			return moni;
		};
		void modificarMonitor(string dni){
			string nombre, ape1, ape2, dia, mes, año, correo, direccion;
					int telefono,opcion;

			list<Monitor>::iterator itm;
			for(itm=monitores.begin();itm!=monitores.end();itm++){
				if(dni==(*itm).Monitor::getDNI()){

					cout<<"Nombre: "<<(*itm).Monitor::getNombre()<<endl;
					cout<<"Apellidos: "<<(*itm).Monitor::getApellidos()<<endl;
					cout<<"Fecha de nacimiento: "<<(*itm).Monitor::getFechaNacimiento()<<endl;
					cout<<"Telefono: "<<(*itm).Monitor::getTelefono()<<endl;
					cout<<"Direccion: "<<(*itm).Monitor::getDireccion()<<endl;
					cout<<"Correo electronico: "<<(*itm).Monitor::getCorreo()<<endl;


					cout<<"Modificar datos personales (1). Nombre, apellidos, fecha nacimiento"<<endl;
					cout<<"Modificar datos (2). Telefono, correo, direccion"<<endl;
					cin>>opcion;
				switch(opcion){
					case 1:
						cout<<"Introduzca nuevo nombre: "; cin<<nombre;
						cout<<"\nIntroduzca nuevo apellido1: "; cin>>ape1;
						cout<<"\nIntroduzca nuevo apellido2: "; cin>>ape2;
						cout<<"\nIntroduzca nuevo dia de nacimiento: "; cin>>dia;
						cout<<"\nIntroduzca nuevo mes de nacimiento: "; cin>>mes;
						cout<<"\nIntroduzca nuevo año de nacimiento: "; cin>>año;

						(*itm).Monitor::setApellidos(ape1,ape2);
						(*itm).Monitor::setNombre(nombre);
						(*itm).Monitor::setFechaNacimiento(dia,mes,año);
						break;
					case 2:
						cout<<"\nIntroduzca nuevo telefono: "; cin>>telefono;
						cout<<"\nIntroduzca nuevo correo electronico: "; getline(cin,correo);
						cout<<"\nIntroduzca nueva direccion: "; getline(cin,direccion);

						(*itm).Monitor::setTelefono(telefono);
						(*itm).Monitor::setCorreo(correo);
						(*itm).Monitor::setDireccion(direccion);


						break;
					default:
						cout<<"Opcion incorrecta"<<endl;
				}
				}
			}

		}

		void getIncidencias();
		void ModificarIncidencia(string codigo);

};

class Incidendia{
	private:
		string nombre_;
		string codigo_;
		Ruta ruta_;
		string descripcion_;
		int estado_;

	public:
		Incidencia(string nombre, string codigo, Ruta ruta, string descripcion);
		void setNombre(string nombre);
		void setCodigo(string codigo);
		void setRuta(Ruta ruta);
		void setDescripcion(string descripcion);
		void setEstado(int estado);
		string getNombre();
		string getCodigo();
		Ruta getRuta();
		string getDescripcion();
		int getEstado();
		void MostarIncidencia();

};

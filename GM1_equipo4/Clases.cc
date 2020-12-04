#include <iostream>
#include <cstdlib>
#include <string.h>

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
		void setFechaNaciemiento(string dia, string mes, string año);
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
		Administrartivo(string dni, string password);
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
				cout<<"Dias de apertura: "; cin>>aux3.dias;
				cout<<"\nHoras de trabajo :"; cin>>aux3.horas;
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
				cout<<"\nIntroduzca fecha: "; cin>>aux1.fecha;
				cout<<"\nIntroduzca descripcion: "; cin>>aux1.descripcion;
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
				cout<<"\nIntroduzca fecha: "; cin>>aux2.fecha;
				cout<<"\nIntroduzca descripcion: "; cin>>aux2.descripcion;
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
		}



		void obtenerDatosRutas();
		void changeRuta();

		Cliente setCliente();
		void setReserva(Cliente cliente);
		void getCliente();
		void getReserva(Cliente cliente);
		void eliminarCliente();
		void eliminarReserva(Cliente cliente)

		Monitor setMonitor();
		void modificarMonitor(string dni);

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

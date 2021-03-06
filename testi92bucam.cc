//test de prueba de i9bucam
#include "cute.h"
#include "ide_listener.h"
#include "xml_listener.h"
#include "cute_runner.h"
#include <iostream>
#include <cstdlib>
#include <string.h>
#include <list>
#include <fstream>

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

struct Sendero{
	string nombre;
	float distancia;
	int duracion;
};

class Cliente;
class Reserva;
class Parque;
class Usuario;
class Monitor;
class Administrativo;
class Incidencia;
class Ruta;

list<Cliente> clientes;
list<Monitor> monitores;
list<Incidencia> incidencias;

//clase reserva
class Reserva{
    private:
        string ruta_;
        string fecha_;
        string codigo_;

    public:
        Reserva(string ruta="", string fecha="", string codigo=""){
		ruta_=ruta;
		fecha_=fecha;
		codigo_=codigo;
	};


	void setRuta(string ruta){ruta_ = ruta;}

	string getRuta(){return ruta_;};

	void setFecha(string dia, string mes, string anyo){
		fecha_=dia+" de "+mes+" de "+anyo+".";
	};

	string getFecha(){return fecha_;}

	void setCodigo(string codigo){
		codigo_ = codigo;
	};

	string getCodigo(){return codigo_;}

};


//clase ruta
class Ruta{
	private:
		string nombre_;
		float duracionMinutos_;
		bool aPie_;
		bool enBici_;
		list<Sendero>senderos_;
		list<Reserva>reservas_;
		int aforoGrupos_;
		string estado_;
		string nivel_;
	public:
		string mostrarNombre(){return nombre_;};

		bool cambiarNombre(string nombre){nombre_ = nombre; return true;};

		float mostrarDuracionMinutos(){return duracionMinutos_;};

		bool cambiarDuracionMinutos(float duracionMinutos){duracionMinutos_ = duracionMinutos; return true;};

		string mostrarAPie(){
			string cad;
			if(aPie_ == true){
				cad ="Si";
			}
			else{
				cad = "No";
			}
			return cad;
		};

		bool cambiarAPie(bool aPie){
			if(aPie==true){
				aPie_=true;
				return true;
			}
			else{
				aPie_=false;
				return true;
			}
			return false;
		};

		string mostrarEnBici(){
			string cad;
			if(enBici_ == true){
				cad = "Si";
			}
			else{
				cad = "No";
			}
			return cad;
		};

		bool cambiarEnBici(bool enBici){
			if(enBici==true){
				enBici_=true;
				return true;
			}
			else{
				enBici_=false;
				return true;
			}
			return false;
		};

		void mostrarSenderos(){
			list<Sendero>:: iterator i;
			for(i=senderos_.begin();i!=senderos_.end();i++){
				cout << "DATOS DEL SENDERO: ";
				cout << "\n\tNombre: ";
				cout << i->nombre;
				cout << "\n\tDistancia en Kms: ";
				cout << i->distancia;
				cout << "\n\tDuracion aproximada: ";
				cout << i->duracion;
				cout << "\n-------------------------------------\n";
			}
		};

		bool anyadirSendero(Sendero sendero){
			list<Sendero>:: iterator i;
			for(i=senderos_.begin();i!=senderos_.end();i++){
				if(i->nombre==sendero.nombre){
					cout << "Sendero ya registrado.\n";
					return false;
				}
			}

			senderos_.push_back(sendero);
			return true;
		};


		bool borrarSendero(){
			string nombre;
			cout << "\n\tPor favor, introduzca el nombre del sendero a eliminar: ";
			cin >> nombre;
			cout << endl;
			list<Sendero>:: iterator i;
			for(i=senderos_.begin();i!=senderos_.end();i++){
				if((*i).nombre==nombre){
					i = senderos_.erase(i);
					return true;
				}
			}
			cout<<"ERROR. No se ha encontrado el sendero seleccionado.\n";
			return false;
		};

		void mostrarReservas(){
			list<Reserva>:: iterator i;
			for(i=reservas_.begin();i!=reservas_.end();i++){
				cout << "DATOS DE LA RESERVA: ";
				cout << "\n\tFecha de realizacion: ";
				cout << (*i).getFecha();
				cout << "\n\tCodigo: ";
				cout << (*i).getCodigo();
				cout << "\n-------------------------------------\n";
			}
		};

		bool anyadirReserva(Reserva reserva){
			list<Reserva>:: iterator i;
			for(i=reservas_.begin();i!=reservas_.end();i++){
				if(i->getCodigo()==reserva.getCodigo()){
					cout << "Reserva ya registrada.\n";
					return false;
				}
			}
			reservas_.push_back(reserva);
			return true;
		};

		bool borrarReserva(){
			string cod;
			cout << "\n\tPor favor, introduzca el codigo de la reserva a eliminar: ";
			cin >> cod;
			cout << endl;
			list<Reserva>:: iterator i;
			for(i=reservas_.begin();i!=reservas_.end();i++){
				if((*i).Reserva::getCodigo()==cod){
					i = reservas_.erase(i);
					cout << "Reserva eliminada correctamente.\n";
					return true;
				}
			}
			cout<<"ERROR. No se ha encontrado la reserva seleccionada.\n";
			return false;
		};

		int mostrarAforoTotal(){return aforoGrupos_;}
			int mostrarAforoDispponible(){
			int cont = aforoGrupos_;
			list<Reserva>:: iterator i;
			for(i=reservas_.begin();i!=reservas_.end();i++){
				cont--;
			}
			return cont;
		};

		bool cambiarAforo(int aforoGrupos){
			if(aforoGrupos > 1){
				aforoGrupos_ = aforoGrupos;
				return true;
			}
			else{
				cout << "Este valor para el aforo no es valido.\n";
				return false;
			}
		};

		string mostrarEstado(){return estado_;};
			bool cambiarEstado(string estado){estado_ = estado;return true;};
			string mostrarNivel(){return nivel_;};
			bool cambiarNivel(string nivel){nivel_ = nivel;return true;};
};



//clase cliente
class Cliente{
    private:
        string nombre_;
        string apellidos_;
        string dni_;
        int telefono_;
        string direccion_;
        string condicion_;
        Reserva reserva_;

    public:
  	Cliente(string nombre, string apellidos, string dni, int telefono, string direccion, string condicion, Reserva reserva){
        	nombre_=nombre;
        	apellidos_=apellidos;
        	dni_=dni;
        	telefono_=telefono;
        	direccion_=direccion;
        	condicion_=condicion;
        	reserva_=reserva;
        };
  	Cliente(){/*nada*/};

        void setNombre(string nombre){nombre_=nombre;};
        string getNombre(){return nombre_;};

        void setApellidos(string apellido1, string apellido2){apellidos_=apellido1+" "+apellido2;};
        string getApellidos(){return apellidos_;};

        void setDNI(string dni){dni_=dni;};
        string getDNI(){return dni_;};

        void setTelefono(int telefono){telefono_=telefono;};
        int getTelefono(){return telefono_;};

        void setDireccion(string direccion){direccion_=direccion;};
        string getDireccion(){return direccion_;};

        void setCondicion(string condicion){condicion_=condicion;};
        string getCondicion(){return condicion_;};

        void setReserva(Reserva reserva){
        	reserva_=reserva;
        };
        Reserva getReserva(){
        	return reserva_;
        };
};


//clase parque
class Parque{
	private:
		string nombre_;
		string ubicacion_;
		float superficie_;
		string zona_;
		string fechaDeclaracion_;
		list<Premio> premios_;
		list<Reconocimiento> reconocimientos_;
		Horario horario_;
		list<Ruta> rutas_;

	public:
		string mostrarNombre()const{return nombre_;};
		string mostrarUbicacion()const{return ubicacion_;};
		float mostrarSuperficie(){return superficie_;};
		string mostrarZona()const{return zona_;};
		string mostrarFechaDeclaracion()const{return fechaDeclaracion_;};
		void mostrarPremios(){
			list<Premio>::iterator itp;
			for(itp=premios_.begin();itp!=premios_.end();itp++){
						cout<<"Nombre del premio: "<<(*itp).nombre<<endl;
						cout<<"Fecha en que se consiguio "<<(*itp).fecha<<endl;
						cout<<"Descripcion: "<<(*itp).descripcion<<endl;
			}
		};
		bool anyadirPremio(Premio premio){
			list<Premio>::iterator itp;
					for(itp=premios_.begin();itp!=premios_.end();itp++){
						if(premio.nombre==(*itp).nombre){
							return false;
						}
					}
				premios_.push_back(premio);
				return true;
		};
		bool borrarPremio(){
			list<Premio>::iterator itre;
			Premio premio;
			cout<<"Introduzca nombre del premio a borrar: ";
			getline(cin,premio.nombre);
					for(itre=premios_.begin();itre!=premios_.end();itre++){
						if(premio.nombre==(*itre).nombre){
							premios_.erase(itre);
							return true;
						}
					}
				return false;
		};

		void mostrarReconocimientos(){
			list<Reconocimiento>::iterator itre;
			for(itre=reconocimientos_.begin();itre!=reconocimientos_.end();itre++){
						cout<<"Nombre del reconocimiento: "<<(*itre).nombre<<endl;
						cout<<"Fecha en que se consiguio "<<(*itre).fecha<<endl;
						cout<<"Descripcion: "<<(*itre).descripcion<<endl;
			}
		};
		bool anyadirReconocimiento(Reconocimiento reconocimiento){
			list<Premio>::iterator itre;
					for(itre=premios_.begin();itre!=premios_.end();itre++){
						if(reconocimiento.nombre==(*itre).nombre){
							return false;
						}
					}
				reconocimientos_.push_back(reconocimiento);
				return true;
		};
		bool borrarReconocimiento(){
			list<Reconocimiento>::iterator itre;
			Reconocimiento reconocimiento;
			cout<<"Introduzca nombre del premio a borrar: ";
			getline(cin,reconocimiento.nombre);
					for(itre=reconocimientos_.begin();itre!=reconocimientos_.end();itre++){
						if(reconocimiento.nombre==(*itre).nombre){
							reconocimientos_.erase(itre);
							return true;
						}
					}
				return false;
		};


		Horario mostrarHorario()const{return horario_;};
		bool cambiarHorario(Horario horario){
			if(horario_.horas==horario.horas&&horario_.dias==horario.dias){
				cout<<"No se ha modificado el horario ya que el introducido es el mismo"<<endl;
				return false;
			}
			else{
			horario_.horas=horario.horas;
			horario_.dias=horario.dias;
			return true;}
		};
		void mostrarRutas(){
			list<Ruta>::iterator itr;

			//variables de rutas
			string nombre;
			float duracion;
			int aforo;
			string estado, nivel;

			//variables para senderos
			Sendero sendero;

			//variables para Reservas
			Reserva res;
			string dia,mes,anyo, codigo;

			//variables para condiciones
			int opcion;
			char temp1;
			int temp2;
			bool found;

			cout<<"¿Que desea?"<<endl;
			cout<<"1. Ver todas las rutas"<<endl;
			cout<<"2. Modificar una ruta"<<endl;
			cout<<"3. Modificar reserva"<<endl;
			cin>>opcion;
			switch(opcion){
				case 1:
					for(itr=rutas_.begin();itr!=rutas_.end();itr++){
						cout<<"Nombre de la ruta: "<<(*itr).mostrarNombre()<<endl;
						cout<<"Duracion estimada: "<<(*itr).mostrarDuracionMinutos()<<endl;
						cout<<"Realizable a pie: "<<(*itr).mostrarAPie()<<endl;
						cout<<"Realizable en bici: "<<(*itr).mostrarEnBici()<<endl;
						(*itr).mostrarSenderos();
						(*itr).mostrarReservas();
						cout<<"El aforo total de la ruta es: "<<(*itr).mostrarAforoTotal()<<endl;
						cout<<"El aforo disponible en la ruta es: "<<(*itr).mostrarAforoDispponible()<<endl;
						cout<<"El nivel de dificultad de la ruta es: "<<(*itr).mostrarNivel()<<endl;
						cout<<"Estado de la ruta: "<<(*itr).mostrarEstado()<<endl;
						cout<<endl;

					}
						break;
				case 2:
					cout<<"Introduzca nombre de la ruta que desea cambiar: ";
					cin>>nombre;
					for(itr=rutas_.begin();itr!=rutas_.end();itr++){
							if(nombre==(*itr).mostrarNombre()){
								found=true;
								cout<<"\nIntroduzca nuevo nombre: ";
							cin>>nombre;
							if(nombre!=(*itr).mostrarNombre()){
								(*itr).cambiarNombre(nombre);}

							cout<<"\nIntroduzca nueva duracion: ";
								cin>>duracion;
								if(duracion!=(*itr).mostrarDuracionMinutos()){
								(*itr).cambiarDuracionMinutos(duracion);}

							cout<<"desea añadir o borrar senderos"<<endl;
							cout<<"Para añadir introduzca 'a'"<<endl;
							cout<<"Para borrar introduzca 'b"<<endl;
							cin>>temp1;
							if(temp1=='a'){
								cout<<"\nIntroduzca el numero de senderos:"; cin>>temp2;

							for(int i=0;i<temp2;i++){
								cout<<"\nNombre del sendero: "; cin>>sendero.nombre;
								cout<<"\nIntroduzca distancia del sendero: "; cin>>sendero.distancia;
								cout<<"\nIntroduzca la duracion del sendero: "; cin>>sendero.duracion;
							if(!(*itr).Ruta::anyadirSendero(sendero)){
							cout<<"Error al introducir el nuevo sendero"<<endl;
									}
								}
							}
							if(temp1=='b'){
								if(!(*itr).borrarSendero()){
									cout<<"Error al borrar el sendero"<<endl;
								}
							}

							cout<<"Introduzca el nuevo aforo: ";
							cin>>aforo;
							if(aforo!=(*itr).mostrarAforoTotal()){
								(*itr).cambiarAforo(aforo);
							}

							cout<<"Introduzca el nuevo estado: ";
							cin>>estado;
							if(estado!=(*itr).mostrarEstado()){
								(*itr).cambiarEstado(estado);
							}

							cout<<"Introduzca el nuevo nivel: ";
							cin>>nivel;
							if(nivel!=(*itr).mostrarNivel()){
								(*itr).cambiarNivel(nivel);
							}

							}}
					if(!found){
				cout<<"\nRuta no encontrada"<<endl;
					}
					break;
				case 3:
					cout<<"\nDesea añadir (introduzca 'a') nueva reserva o borrar (introduzca 'b') una reserva: ";
					cin>>temp1;
					cout<<"\nIntroduzca el nombre de la ruta deseada: ";
					cin>>nombre;
					for(itr=rutas_.begin();itr!=rutas_.end();itr++){
					if(nombre==(*itr).mostrarNombre()){
						found=true;
					if(temp1=='a'){
						cout<<"\nIntroduzca codigo de la reserva: ";
								cin>>codigo;
						cout<<"\nIntroduzca dia de la reserva: ";
							cin>>dia;
						cout<<"\nIntroduzca mes de la reserva: ";
							cin>>mes;
						cout<<"\nIntroduzca anyo de la reserva: ";
							cin>>anyo;
							res.Reserva::setCodigo(codigo);
							res.Reserva::setFecha(dia,mes,anyo);
							res.Reserva::setRuta((*itr).mostrarNombre());

						if(!(*itr).anyadirReserva(res)){
							cout<<"Error al añadir la reserva"<<endl;
						}
					}
					if(temp1=='b'){
						if(!(*itr).borrarReserva()){
							cout<<"La reserva no se ha podido borrar"<<endl;
						}
					}}}
					if(!found){
						cout<<"La ruta no ha sido encontrada, por lo que no se puede añadir la reserva"<<endl;
					}
					break;
				default:
					cout<<"Opcion incorrecta"<<endl;
					break;
			}
		};

		bool anyadirRuta(Ruta ruta){
		list<Ruta>::iterator itr;
		for(itr=rutas_.begin();itr!=rutas_.end();itr++){
			if(ruta.Ruta::mostrarNombre()==(*itr).Ruta::mostrarNombre()){
				return false;
			}
		}
		rutas_.push_back(ruta);
				return true;
		};

		bool borrarRuta(){
			list<Ruta>::iterator itr;
			Ruta ruta;
			string nombre;
			cout<<"Introduzca nombre de la ruta: ";
					getline(cin,nombre);
			ruta.cambiarNombre(nombre);

			for(itr=rutas_.begin();itr!=rutas_.end();itr++){
				if(ruta.Ruta::mostrarNombre()==(*itr).Ruta::mostrarNombre()){
					rutas_.erase(itr);
					return true;
				}
			}
					return false;
		};

};
Parque parque;

//clase incidencia.

class Incidencia{
	private:
		string nombre_;
		string codigo_;
		Ruta ruta_;
		string descripcion_;
		int estado_;

	public:
		Incidencia(string nombre, string codigo, Ruta ruta, string descripcion){
			setNombre(nombre);
			setCodigo(codigo);
			setRuta(ruta);
			setDescripcion(descripcion);
			setEstado(1);
		};

		void setNombre(string nombre){nombre_ = nombre;};
		void setCodigo(string codigo){codigo_ = codigo;};
		void setRuta(Ruta ruta){ruta_ = ruta;};
		void setDescripcion(string descripcion){descripcion_ = descripcion;};
		void setEstado(int estado){
			if(estado > 0 && estado < 4){
			estado_ = estado;
			}
			else{
				cout << "ERROR. Estado invalido";
			}
		};
		string getNombre()const{return nombre_;};
		string getCodigo()const{return codigo_;};
		Ruta getRuta()const{return ruta_;};
		string getDescripcion()const{return descripcion_;};
		int getEstado()const{return estado_;};
		void mostrarIncidencia(){
			string cadestado;
			switch(estado_){
				case 1: cadestado == "Sin resolver";
				break;
				case 2: cadestado == "Resuelta";
				break;
				case 3: cadestado == "Almacenada";
			}

			cout << "DATOS DE LA INCIDENCIA: \n";
			cout << "\tNombre -> " << getNombre() << endl;
			cout << "\tCodigo -> " << getCodigo() << endl;
			cout << "\tPerteneciente a la ruta -> " << ruta_.mostrarNombre() << endl;
			cout << "\tDescripcion -> " << getDescripcion() << endl;
			cout << "\tEstado -> " << cadestado << endl;
			cout << "-----------------------------------" << endl;
		}

};


//clases usuario monitor y administrativo.
class Usuario{
	private:
		string password_;
		string DNI_;

	public:
		Usuario(string DNI, string password){
			while(DNI.size() != 9 || password.size() != 6){
				cout << "El formato del DNI y/o del password son incorrectos. Por favor vuelva a intentarlo.\n";
				cout << "\tUsuario: ";
				cin >> DNI;
				cout << "\n\tPassword: ";
				cin >> password;
			}
			DNI_ = DNI;
			password_ = password;
		}
		string dni(){return DNI_;};
		virtual string getDNI()=0;
		bool compruebaPassword(){
			string usuario = DNI_ + "," + password_;
			ifstream f("listadeusuarios.txt");
			if (f.is_open()){
			string linea;
			while(getline(f, linea)){
				if(linea.find(usuario) != string::npos){
				cout << "Usuario encontrado. Bienvenido.\n";
				f.close();
				return true;
				}
			}
			cout << "El DNI y/o la contraseña son incorrectos.";
			f.close();
			return false;

			}
			else{
				cout << "No se ha podido abrir el archivo.";
				f.close();
				return false;
			}
		}

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
		Monitor(string dni, string password,string nombre="",string apellidos="",int telefono=0,string fechaNacimiento="",string correo="",string direccion=""):Usuario(dni,password){
			nombre_=nombre;
			apellidos_=apellidos;
			telefono_=telefono;
			fechaNacimiento_=fechaNacimiento;
			correo_=correo;
			direccion_=direccion;
		};

		void setNombre(string nombre){nombre_=nombre;};
		void setApellidos(string apellido1, string apellido2){apellidos_=apellido1+apellido2;};
		void setTelefono(int telefono){telefono_=telefono;};
		void setFechaNacimiento(string dia, string mes, string anyo){fechaNacimiento_=dia+mes+anyo;};
		void setCorreo(string correo){correo_=correo;}
		void setDireccion(string direccion){direccion_=direccion;};
		string getDNI()override{return dni();};
		string getNombre(){return nombre_;};
		string getApellidos(){return apellidos_;};
		int getTelefono(){return telefono_;};
		string getFechaNacimiento(){return fechaNacimiento_; };
		string getCorreo(){return correo_;};
		string getDireccion(){ return direccion_;};

		Incidencia setIncidencia(string nombre, string codigo,Ruta ruta, string descripcion){
		    Incidencia aux(nombre,codigo,ruta,descripcion);
		    return aux;
		};

		Ruta createRuta(){
		    string nombre,nivel,estado;
		    float duracion;
		    int aforo, nsenderos;
		    Ruta rnueva;
		    Sendero sendero;
		    bool a,b;
		    Parque P;
		    P=parque;
		    cout<<"Introduzca el nombre de la ruta nueva: ";
		    cin>>nombre;
		    rnueva.Ruta::cambiarNombre(nombre);
		    cout<<"\nIndique la duracion de la ruta nueva: ";
		    cin>>duracion;
		    rnueva.Ruta::cambiarDuracionMinutos(duracion);
		    cout<<"\nIntroduzca el aforo maximo de la ruta nueva: ";
		    cin>>aforo;
		    rnueva.Ruta::cambiarAforo(aforo);
		    cout<<"\nIntroduzca el nivel de dificultad de la ruta: ";
		    cin>>nivel;
		    rnueva.Ruta::cambiarNivel(nivel);
		    cout<<"\nIntroduzca el numero de senderos: ";
		    cin>>nsenderos;
		    for(int i=0; i<nsenderos; i++){
		    	cout<<"\n";
		        cout<<"\nIndique el nombre del sendero: ";
		        cin>>sendero.nombre;
		        cout<<"\nIntroduzca la distancia del sendero: ";
		        cin>>sendero.distancia;
		        cout<<"\nIntroduzca la duracion del sendero: ";
		        cin>>sendero.duracion;

		        if(!rnueva.Ruta::anyadirSendero(sendero)){
		            cout<<"\nError al introducir el sendero nuevo\n";
		        }
		    }
		    cout<<"\n¿La ruta se puede realizar a pie?";
		    cout<<"\nIntroduzca 1 para si o 0 para no: ";
		    cin>>a;

		    cout<<"\n¿La ruta se puede realizar en bici?";
		    cout<<"\nIntroduzca 1 para si o 0 para no: ";
		  	cin>>b;

		  	cout<<"\nIntroduzca el estado de la ruta: ";
		  	cin>>estado;
		  	rnueva.Ruta::cambiarEstado(estado);
		  	rnueva.Ruta::cambiarAPie(a);
		  	rnueva.Ruta::cambiarEnBici(b);


		    if(!P.Parque::anyadirRuta(rnueva)){
		        cout<<"\nError al introducir la ruta nueva\n";
		}
		    parque=P;
		    return rnueva;
};
};




class Administrativo:public Usuario{
	private:
	//nada

	public:
		Administrativo(string dni, string password):Usuario(dni,password){};
		string getDNI()override{return dni();};

		void obtenerDatosParque(){
			Parque P;
			P=parque; //objeto de la clase parque declarado como global en el programa main
			cout<<"Nombre del parque: "<<P.Parque::mostrarNombre()<<endl;
			cout<<"Ubicacion del parque: "<<P.Parque::mostrarUbicacion()<<endl;
			cout<<"Superficie del parque "<<P.Parque::mostrarSuperficie()<<" hectareas"<<endl;
			cout<<"Zonas contenidas en el parque"<<P.Parque::mostrarZona()<<endl;
			cout<<"Fecha de declaracion de parque natural: "<<P.Parque::mostrarFechaDeclaracion()<<endl;
			cout<<"El parque ha obtenido los premios: "<<endl;
			P.Parque::mostrarPremios();
			cout<<"\nEl parque tiene los siguientes reconocimientos: "<<endl;
			P.Parque::mostrarReconocimientos();
			cout<<"\nEl horario del parque es: "<<endl;
			P.Parque::mostrarHorario();
			cout<<"\nLas rutas disponibles en el parque son: "<<endl;
			P.Parque::mostrarRutas();

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
			if(!(P.Parque::cambiarHorario(aux3))){
				cout<<"Error cambiando el horario"<<endl;
			}
				break;
			case 2:
				if(P.Parque::borrarPremio()){
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
				if(P.Parque::anyadirPremio(aux1)){
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
				if(P.Parque::anyadirReconocimiento(aux2)){
					cout<<"\nReconocimiento introducido con exito"<<endl;
				}
				else{
					cout<<"Error al introducir reconocimiento"<<endl;
				}
				break;
			default:
				cout<<"El numero introducido no se corresponde con ninguna opcion"<<endl;
				parque=P;
			}
		};
		void obtenerDatosRutas(){
		 Parque P;
		 P=parque; //objeto de la clase parque declarado como global en el programa main
		 P.Parque::mostrarRutas();
		};

		void changeRuta(){
			Parque P;
			P=parque;
			P.Parque::mostrarRutas();
			parque=P;
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
			clientes.push_back(C);
		return C;
		};

		void setReserva(Cliente &cliente){
			string codigo, dia, mes, anyo,nombre;
			Reserva aux;
			 Parque P;
			 P=parque; //objeto de la clase parque declarado como global en el programa main

			cout<<"Introduzca codigo de la reserva: "; cin>>codigo;
			cout<<"Introduzca fecha de la reserva: "<<endl;
			cout<<"\ndia: "; cin>>dia;
			cout<<"\nmes: "; cin>>mes;
			cout<<"\naño: "; cin>>anyo;
			aux.setCodigo(codigo);
			aux.setFecha(dia,mes,anyo);
			 P.Parque::mostrarRutas();
			cout<<"\nIntroduzca nombre de la ruta para la reserva:";
			cin>>nombre;
			Ruta R;
			R.Ruta::cambiarNombre(nombre);
			aux.setRuta(R.mostrarNombre());
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
				cout<<"Nombre: "<<(*itc).Cliente::getNombre()<<endl;
				cout<<"Apellidos: "<<(*itc).Cliente::getApellidos()<<endl;
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
			string R;
			aux=cliente.Cliente::getReserva();
			R=(aux.Reserva::getRuta());
			cout<<"Codigo: "<<aux.Reserva::getCodigo()<<endl;
			cout<<"Ruta: "<<R<<endl;
			cout<<"Fecha: "<<aux.Reserva::getFecha()<<endl;
		};

		void eliminarCliente(){
		bool encontrado=false;
		string dni;
		//Cliente borrar;
		cout<<"Introduzca dni del cliente a buscar: "; cin>>dni;
		list<Cliente>::iterator itc;
		for(itc=clientes.begin();itc!=clientes.end();itc++){
			if(dni==(*itc).Cliente::getDNI()){
				//borrar=*itc;
				clientes.erase(itc);
		encontrado=true;
		}}
if(encontrado==false){
cout<<"El cliente con dni "<<dni<<" no se encuentra en el sistema"<<endl;
}

		};
		void eliminarReserva(Cliente &cliente){
			Reserva aux;

			cliente.Cliente::setReserva(aux);
		};

		Monitor setMonitor(){
		string dni, pass, nombre, ape1, ape2, dia, mes, anyo, correo, direccion;
		int telefono;
			cout<<"Introduca dni "; cin>>dni;
			cout<<"\nIntroduca contraseña del monitor "; cin>>pass;
	Monitor moni(dni,pass);
			cout<<"Introduzca nombre: "; cin>>nombre;
			cout<<"\nIntroduzca apellido1: "; cin>>ape1;
			cout<<"\nIntroduzca apellido2: "; cin>>ape2;
			cout<<"\nIntroduzca telefono: "; cin>>telefono;
			cout<<"\nIntroduzca dia de nacimiento: "; cin>>dia;
			cout<<"\nIntroduzca mes de nacimiento: "; cin>>mes;
			cout<<"\nIntroduzca año de nacimiento: "; cin>>anyo;
			cout<<"\nIntroduzca correo electronico: "; getline(cin,correo);
			cout<<"\nIntroduzca direccion: "; getline(cin,direccion);
		moni.Monitor::setApellidos(ape1,ape2);
		moni.Monitor::setNombre(nombre);
		moni.Monitor::setTelefono(telefono);
		moni.Monitor::setFechaNacimiento(dia,mes,anyo);
		moni.Monitor::setCorreo(correo);
		moni.Monitor::setDireccion(direccion);

			return moni;
		};
		void modificarMonitor(string dni){
			string nombre, ape1, ape2, dia, mes, anyo, correo, direccion;
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
						cout<<"Introduzca nuevo nombre: "; cin>>nombre;
						cout<<"\nIntroduzca nuevo apellido1: "; cin>>ape1;
						cout<<"\nIntroduzca nuevo apellido2: "; cin>>ape2;
						cout<<"\nIntroduzca nuevo dia de nacimiento: "; cin>>dia;
						cout<<"\nIntroduzca nuevo mes de nacimiento: "; cin>>mes;
						cout<<"\nIntroduzca nuevo año de nacimiento: "; cin>>anyo;

						(*itm).Monitor::setApellidos(ape1,ape2);
						(*itm).Monitor::setNombre(nombre);
						(*itm).Monitor::setFechaNacimiento(dia,mes,anyo);
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

		};

		void getIncidencias(){
			list<Incidencia>::iterator iti;
			for(iti=incidencias.begin();iti!=incidencias.end();iti++){
				(*iti).Incidencia::mostrarIncidencia();
			}
		};

		void ModificarIncidencia(string codigo){
			string descripcion;
			int estado;
			list<Incidencia>::iterator iti;
					for(iti=incidencias.begin();iti!=incidencias.end();iti++){
						if(codigo==(*iti).Incidencia::getCodigo()){
						(*iti).Incidencia::mostrarIncidencia();
				cout<<"\nIntroduzca la nueva descripcion de la incidencia: "<<endl;
				getline(cin,descripcion);
				cout<<"\nIntroduzca nuevo estado de la ruta: 1-sin resolver /2-resuelta /3-almacenada"<<endl;
				cin>>estado;
				if(estado>0&&estado<4){
					(*iti).Incidencia::setEstado(estado);
				}
				else{
					cout<<"Estado incorrecto, se mantendra el anterior"<<endl;
				}
				(*iti).Incidencia::setDescripcion(descripcion);
						}
					}
				};
};


void testSetIncidencia () {
	string nombre, codigo, descripcion, nombreruta, dni, password;
	Ruta ruta;
	cout<<"Introduzca dni: ";
	cin>>dni;
	cout<<"\nIntroduzca password: ";
	cin>>password;
	Monitor moni(dni, password);
	cout<<"\nIntroduzca el nombre de la incidencia: ";
	cin>>nombre;
	cout<<"\nIntroduzca el codigo de la incidencia: ";
	cin>>codigo;
	cout<<"\nIndique la ruta en la que ha ocurrido la incidencia: ";
	cin>>nombreruta;
	ruta.Ruta::cambiarNombre(nombreruta);
	cout<<"\nIndique de manera breve una descripcion de la incidencia: ";
	cin>>descripcion;
	cout<<"\n";
    Incidencia incidencia = moni.setIncidencia(nombre, codigo, ruta, descripcion);
    Incidencia aux (nombre, codigo, ruta, descripcion);
    ruta = incidencia.getRuta();
    Ruta raux= aux.getRuta();
    ASSERT_EQUAL(incidencia.getNombre(), aux.getNombre());
    ASSERT_EQUAL(incidencia.getCodigo(), aux.getCodigo());
    ASSERT_EQUAL(ruta.mostrarNombre(), raux.mostrarNombre());
    ASSERT_EQUAL(incidencia.getDescripcion(), aux.getDescripcion());
}

void testCreateRuta () {
	string dni, password;
	Ruta nueva;
	cout<<"Introduzca dni: ";
	cin>>dni;
	cout<<"\nIntroduzca password: ";
	cin>>password;
	Monitor moni(dni, password);
	Ruta aux = nueva = moni.createRuta();

	ASSERT_EQUAL(nueva.mostrarNombre(), aux.mostrarNombre());
	ASSERT_EQUAL(nueva.mostrarDuracionMinutos(), aux.mostrarDuracionMinutos());
	ASSERT_EQUAL(nueva.mostrarAforoTotal(), aux.mostrarAforoTotal());
	ASSERT_EQUAL(nueva.mostrarNivel(), aux.mostrarNivel());
	ASSERT_EQUAL(nueva.mostrarAPie(), aux.mostrarAPie());
	ASSERT_EQUAL(nueva.mostrarEnBici(), aux.mostrarEnBici());
	ASSERT_EQUAL(nueva.mostrarEstado(), aux.mostrarEstado());
}

bool runAllTests(int argc, char const *argv[]) {
	cute::suite s { };
	//TODO add your test here

	s.push_back(CUTE(testSetIncidencia));
	s.push_back(CUTE(testCreateRuta));

	cute::xml_file_opener xmlfile(argc, argv);
	cute::xml_listener<cute::ide_listener<>> lis(xmlfile.out);
	auto runner = cute::makeRunner(lis, argc, argv);
	bool success = runner(s, "AllTests");
	return success;
}

int main(int argc, char const *argv[]) {
    return runAllTests(argc, argv) ? EXIT_SUCCESS : EXIT_FAILURE;
}

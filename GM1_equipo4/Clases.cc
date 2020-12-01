

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
		string getDNI() override;

		void obtenerDatosParque();
		void setDatosParque();

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

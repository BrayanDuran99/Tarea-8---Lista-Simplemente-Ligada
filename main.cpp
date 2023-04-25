#include <iostream>
using namespace std;
class Socio{
    private:
        int NumS;
        string NomS;
        string Domi;
        int Ing;
    public:
        Socio(){}
        friend ostream& operator<<(ostream& O, Socio& x){
            O << "\nNumero de socio: " << x.NumS;
            O << "\nNombre: " << x.NomS;
            O << "\nDomicilio: " << x.Domi;
            O << "\nAnio de Ingreso: " << x.Ing;
        return O;
        }
        friend istream& operator>>(istream& I, Socio& x){
            cout << "\nNumero de socio: ";
            I >> x.NumS;
            cout << "Nombre: ";
            I >> x.NomS;
            cout << "Domicilio: ";
            I >> x.Domi;
            cout << "Anio de Ingreso: ";
            I >> x.Ing;
            return I;
    }

    int getIng(){
        return Ing;
    }
    int getNumS(){
        return NumS;
    }

    //bool operator==(string str) const {
        //return (this->NomS == str);
    //}
    const string& getNomS() const {
        return NomS;
    }

    //void setNomS(const string& nuevoNombre) {
        //NomS = nuevoNombre;
    //}


    //bool operator==(string str) const {
        //return (this->Domi == str);
    //}
    const string& getDomi() const {
        return Domi;
    }

    //void setDomi(const string& nuevoDomicilio) {
        //Domi = nuevoDomicilio;
    //}
};


template<class T>
class LSLSE;

template<class T>
class node{
private:
    T data;
    node<T>* sig;
public:
    node():sig(nullptr){};
    friend class LSLSE<T>;
};

template<class T>
class LSLSE{
private:
    node<T>* lista;
public:
    LSLSE():lista(nullptr){};
    bool vacia()const;
    node<T>* ultimo()const;
    node<T>* primero()const;
    node<T>* anterior(node<T>* pos)const;
    void insertar(node<T>* pos, T elem);
    bool eliminar(node<T>* pos);
    void imprimir()const;
    void Buscar(string, string);
    void insercion(node<T>* aux);

};

template<class T>
void LSLSE<T>::Buscar(string Nom, string Dom){
    node<T>* aux=lista;
    int i=0, num;
    while(aux!=nullptr){
        if(aux->data.getNomS() == Nom && aux->data.getDomi() == Dom){
            cout<<"Socio encontrado con exito: \n"<<aux->data;
            i=1;
        }
        aux=aux->sig;
    }
    if(i == 0){
        cout<<"El socio que intenta buscar no esta dado de alta\n";
    }
}

template<class T>
void LSLSE<T>::imprimir()const{
    node<T>* aux=lista;
    while(aux!=nullptr){
        std::cout<<aux->data<<"-> ";
        aux=aux->sig;
    }
}

template<class T>
bool LSLSE<T>::eliminar(node<T>* pos){
    if(vacia() || pos==nullptr){
        return false;
    }
    if(pos==lista){
        lista=lista->sig;
    }
    else{
        anterior(pos)->sig=pos->sig;
    }
    delete pos;
    return true;
}

template<class T>
void LSLSE<T>::insertar(node<T>* pos, T elem){
    node<T>* aux= new node<T>;
    aux->data=elem;
    if(pos==nullptr){
        aux->sig=lista;
        lista=aux;
    }
    else{
        insercion(aux);
    }
}

template<class T>
void LSLSE<T>::insercion(node<T>* aux){
    node<T>* Xa= lista;
    int i=0,c=0;
    while(Xa!=nullptr){
        if(Xa->data.getNumS() == aux->data.getNumS()){
            i=2;
            cout<<"Este numero de socio ya esta en uso\n";
        }
        if(i==0){
            if(Xa->data.getNumS()<aux->data.getNumS()){
                if(Xa->sig==nullptr){
                    Xa->sig=aux;
                }
            }
            if(Xa->data.getNumS()>aux->data.getNumS()&&c!=2){
                aux->sig=lista;
                lista=aux;
                c=2;
            }
        }
        Xa=Xa->sig;
    }
}




template<class T>
node<T>* LSLSE<T>::anterior(node<T>* pos)const{
    if(vacia() || pos==nullptr){
        return nullptr;
    }
    node<T>* aux=lista;
    while(aux!=nullptr && aux->sig!=pos){
        aux=aux->sig;
    }
    return aux;
}

template<class T>
node<T>* LSLSE<T>::primero()const{
    if(vacia()){
        return nullptr;
    }
    return lista;
}


template<class T>
node<T>* LSLSE<T>::ultimo()const{
    if(vacia()){
        return nullptr;
    }
    node<T>* aux=lista;
    while(aux->sig!=nullptr){
        aux=aux->sig;
    }
    return aux;
}

template<class T>
bool LSLSE<T>::vacia()const{
    if(lista==nullptr)
        return true;
    return false;
}

int menu();

int main()
{
    LSLSE<Socio> milista;
    Socio x;
    int opc, total=0;
    string Nombre, Domicilio;
    do{
        opc = menu();
        switch(opc){
            case 1:{
                cout<<"Ingresa datos\n";
                cin>>x;
                milista.insertar(milista.ultimo(),x);
                total++;
                break;}
            case 2:
                milista.eliminar(milista.ultimo());
                total--;
                break;
            case 3:
                milista.imprimir();
                break;
            case 4:
                cout<<"A continuacion escribe el nombre de socio que desea buscar\n";
                cin>>Nombre;
                cout<<"A continuacion escribe el domicilio tambien del socio que desea buscar\n";
                cin>>Domicilio;
                milista.Buscar(Nombre,Domicilio);
                break;
            case 5:
                cout<<"Total de socios registrados en el club:\t"<<total;
                cout<<"\n";
                break;
            case 6:
                break;
        }
    }while(opc!=6);
    return 0;
}

int menu(){
    int opc;
    cout<<"MENU\n"
    <<"1. Registrar un nuevo socio\n"
    <<"2. Dar de baja un socio\n"
    <<"3. Generar reporte de los socios del club\n"
    <<"4. Buscar un socio\n"
    <<"5. Calcular e imprimir total de socios registrados\n"
    <<"6. Salir\n"
    <<"Elige tu opcion: \t";
    cin>>opc;
    return opc;
}

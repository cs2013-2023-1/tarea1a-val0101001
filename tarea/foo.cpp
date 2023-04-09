#include "foo.h"

Matriz2D::Matriz2D(){
    // Constructor por defecto
    filas=3;columnas=3;
    ptr=new float*[filas]();
    for(int i=0;i<filas;i++){
        ptr[i]=new float[columnas]();
        for(int j=0;j<columnas;j++){
            ptr[i][j]=float(rand()%100)/100;
        }
    }
}

Matriz2D::Matriz2D(int n){
    // Constructor con un parametro
    filas=n;columnas=n;
    ptr=new float*[filas]();
    for(int i=0;i<filas;i++){
        ptr[i]=new float[columnas]();
        for(int j=0;j<columnas;j++){
            ptr[i][j]=float(rand()%100)/100;
        }
    }
}

Matriz2D::Matriz2D(int n, int m){
    // Constructor con dos parametros
    filas=n;columnas=m;
    ptr=new float*[filas]();
    for(int i=0;i<filas;i++){
        ptr[i]=new float[columnas]();
        for(int j=0;j<columnas;j++){
            ptr[i][j]=float(rand()%100)/100;
        }
    }
}

Matriz2D::Matriz2D(const Matriz2D& m){
    // Constructor de copia
    this->filas=m.filas;
    this->columnas=m.columnas;
    this->ptr=new float*[this->filas]();
    for(int i=0;i<this->filas;i++){
        ptr[i]=new float[this->columnas]();
        for(int j=0;j<this->columnas;j++){
            this->ptr[i][j]=m.ptr[i][j];
        }
    }
}

Matriz2D::Matriz2D(Matriz2D&& m){
    // Constructor de movimiento
    this->filas=m.filas;
    this->columnas=m.columnas;
    this->ptr=m.ptr;
    m.ptr=nullptr;
    m.filas=0;
    m.columnas=0;
}

Matriz2D t(Matriz2D& m){
    // Transpuesta de una matriz
    Matriz2D m2(m.columnas,m.filas);
    for(int i=0;i<m2.filas;i++){
        for(int j=0;j<m2.columnas;j++){
            m2.ptr[i][j]=m.ptr[j][i];
        }
    }
    return m2;
}

std::ostream& operator<<(std::ostream& os, const Matriz2D& m){
    // Sobrecarga del operador <<
    cout.precision(2);
    for(int i=0;i<m.filas;i++){
        for(int j=0;j<m.columnas;j++){
            os<<fixed<<m.ptr[i][j]<<" ";
        }
        os<<"\n";
    }
    return os;
}

Matriz2D operator+(const Matriz2D& m1, const Matriz2D& m2){
    // Sobrecarga del operador +
    if((m1.filas!=m2.filas)||(m1.columnas!=m2.columnas)) return Matriz2D(0);
    Matriz2D m3(m1.filas,m1.columnas);
    for(int i=0;i<m1.filas;i++){
        for(int j=0;j<m1.columnas;j++){
            m3.ptr[i][j]=m1.ptr[i][j]+m2.ptr[i][j];
        }
    }
    return m3;
}

Matriz2D operator-(const Matriz2D& m1, const Matriz2D& m2){
    // Sobrecarga del operador -
    if((m1.filas!=m2.filas)||(m1.columnas!=m2.columnas)) return Matriz2D(0);
    Matriz2D m3(m1.filas,m1.columnas);
    for(int i=0;i<m1.filas;i++){
        for(int j=0;j<m1.columnas;j++){
            m3.ptr[i][j]=m1.ptr[i][j]-m2.ptr[i][j];
        }
    }
    return m3;
}

Matriz2D operator*(const Matriz2D& m1, const Matriz2D& m2){
    // Sobrecarga del operador *
    if(m1.columnas!=m2.filas) return Matriz2D(0);
    Matriz2D m3(m1.filas,m2.columnas);
    float sum;
    for(int i=0;i<m1.filas;i++){
        for(int j=0;j<m2.columnas;j++){
            sum=0;
            for(int k=0;k<m1.columnas;k++){
                sum+=m1.ptr[i][k]*m2.ptr[k][j];
            }
            m3.ptr[i][j]=sum;
        }
    }
    return m3;
}

Matriz2D operator+(const Matriz2D& m, float n){
    // Sobrecarga del operador +
    Matriz2D m2(m.filas,m.columnas);
    for(int i=0;i<m.filas;i++){
        for(int j=0;j<m.columnas;j++){
            m2.ptr[i][j]=n+m.ptr[i][j];
        }
    }
    return m2;
}

Matriz2D operator-(const Matriz2D& m, float n){
    // Sobrecarga del operador -
    Matriz2D m2(m.filas,m.columnas);
    for(int i=0;i<m.filas;i++){
        for(int j=0;j<m.columnas;j++){
            m2.ptr[i][j]=m.ptr[i][j]-n;
        }
    }
    return m2;
}

Matriz2D operator*(const Matriz2D& m, float n){
    // Sobrecarga del operador *
    Matriz2D m2(m.filas,m.columnas);
    for(int i=0;i<m.filas;i++){
        for(int j=0;j<m.columnas;j++){
            m2.ptr[i][j]=n*m.ptr[i][j];
        }
    }
    return m2;
}

Matriz2D operator/(const Matriz2D& m, float n){
    // Sobrecarga del operador /
    Matriz2D m2(m.filas,m.columnas);
    for(int i=0;i<m.filas;i++){
        for(int j=0;j<m.columnas;j++){
            m2.ptr[i][j]=m.ptr[i][j]/n;
        }
    }
    return m2;
}

float Matriz2D::get(int i, int j){
    return ptr[i][j];
}

int Matriz2D::getFilas(){
    return filas;
}

int Matriz2D::getColumnas(){
    return columnas;
}
    

#include<iostream>
#include<cmath>
using namespace std;

struct Vector{
    private :
    double x;
    double y;
    double z;

    public :
    Vector(){
        this->x=1;
        this->y=1;
        this->z=1;
    }
    Vector(double x,double y,double z) {
        this->x=x;
        this->y=y;
        this->z=z;
    }
    double getLength(){
        return sqrt( x*x + y*y +z*z);
    }
    double scalarMulplicatiionWith(Vector vector){
        return this->x*vector.x+this->y*vector.y+this->z*vector.z;
    }

    double getCos(Vector vector){
        return this->scalarMulplicatiionWith(vector)/(this->getLength()*vector.getLength());
    }


    bool isPependicularWith(Vector vector){
       if(this->getCos(vector) == 0){
           return true;
       }
       else{
           return false;
       }
    }

    double vectorMultipilcationWith(Vector vector){
        double cos=this->getCos(vector);
        double sin=sqrt(1-cos*cos);

        return this->getLength()*vector.getLength()*sin;

    }
     
};

int main(){
    Vector vector1(-5,1,-5);
    Vector vector2(-2,-5,-2);

    cout<<vector1.scalarMulplicatiionWith(vector2)<<endl;
    cout<<vector1.getCos(vector2)<<endl;
    cout<<vector1.isPependicularWith(vector2)<<endl;


    return 0;
}
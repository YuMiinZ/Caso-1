//Programa elaborado por Ericka Yu Min


//Inclusión de librerías
#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> compare_the_triplets_v1(int a[3], int b[3]){
    /*
    Funcionamiento: Calculará los puntos obtenidos del primer participante y del segundo, para ello se realizará una
    comparación de cada puntaje a[0] con b[0] y así sucesivamente, si el primer participante obtuvo mayor puntaje
    se le otorgará un punto y sino se le ortogará al segundo.

    Entradas:
    -a[3](int): Puntajes del primer participante
    -b[3](int): Puntaje del segundo participante

    Salidas:
    -resultado (vector<int>): Retorna un vector con los resultados de los puntos que obtuvieron ambos participantes.

    Comentarios: Este algoritmo es más eficiente que el de la versión 2, ya que en la otra versión se utiliza un
    ciclo for y debido a ello se está realizando 3 iteraciones con 3 comparaciones como mínimo si se cumple la primera
    condición y un máximo de 6 comparaciones si no se cumpliera la primera condición.

    En este algoritmo nos ahorramos el for, se realiza 3 comparaciones y la asignación de puntos se realiza
    por medio de operaciones aritméticas.
    */
    vector<int> resultado(2);

    if(a[0]!=b[0]){
        resultado.at(0)+=((a[0]-b[0])/abs(a[0]-b[0]))+1;
        resultado.at(1)+=((a[0]-b[0])/abs(a[0]-b[0]))-1;
    }
    if(a[1]!=b[1]){
        resultado.at(0)+=((a[1]-b[1])/abs(a[1]-b[1]))+1;
        resultado.at(1)+=((a[1]-b[1])/abs(a[1]-b[1]))-1;
    }
    if(a[2]!=b[2]){
        resultado.at(0)+=((a[2]-b[2])/abs(a[2]-b[2]))+1;
        resultado.at(1)+=((a[2]-b[2])/abs(a[2]-b[2]))-1;
    }
    resultado.at(0)=resultado.at(0)/2;
    resultado.at(1)=abs(resultado.at(1)/2);
    return resultado;
}


vector<int> compare_the_triplets_v2(int a[3],int b[3]){
    /*
    Funcionamiento: Calculará los puntos obtenidos del primer participante y del segundo, para ello se realizará una
    comparación de cada puntaje a[0] con b[0] y así sucesivamente, si el primer participante obtuvo mayor puntaje
    se le otorgará un punto y sino se le ortogará al segundo.

    Entradas:
    -a[3](int): Puntajes del primer participante
    -b[3](int): Puntaje del segundo participante

    Salidas:
    -resultado (vector<int>): Retorna un vector con los resultados de los puntos que obtuvieron ambos participantes.

    */
    vector<int>resultado(2);

    for(int contador=0;contador<3;contador++){
        if(a[contador]>b[contador]){
            resultado.at(0)++;
        }
        else if (a[contador]<b[contador]){
            resultado.at(1)++;
        }
    }
    return resultado;
}

string time_conversion_v1(string horaIngresada){
    /*
    Funcionamiento: Método responsable de convertir la hora de 12h a 24h.

    Entradas:
     -horaIngresada(string): Hora ingresada por el usuario

    Salidas:
    -horaConvertida(string): Es la hora convertida a 24h.
    */
    int hora;
    string horaConvertida;

    hora=atoi((horaIngresada.substr(0,2)).c_str());

    if(horaIngresada.substr(8,2)=="PM"&&hora!=12){
        hora+=12;
        horaConvertida.append(to_string(hora));
        horaConvertida.append(":");
        horaConvertida.append(horaIngresada.substr(3,2));
        horaConvertida.append(":");
        horaConvertida.append(horaIngresada.substr(6,2));
    }
    else if(horaIngresada.substr(8,2)=="AM"&&hora==12){
        horaConvertida.append("00");
        horaConvertida.append(":");
        horaConvertida.append(horaIngresada.substr(3,2));
        horaConvertida.append(":");
        horaConvertida.append(horaIngresada.substr(6,2));
    }
    else{
        horaConvertida=horaIngresada.substr(0,8);
    }
    return horaConvertida;
}


string time_conversion_v2(string strHora){
    /*
    Funcionamiento: Método responsable de convertir la hora de 12h a 24h.

    Entradas:
     -strHora(string): Hora ingresada por el usuario

    Salidas:
    -strHora(string): Es la hora convertida a 24h.

    Comentarios: Este algoritmo es mejor que el anterior.

    En la versión 1, se utiliza la función "atoi" y ".c_str()" para convertir de
    string a int, se está realizando 4 comparaciones para saber  si corresponde
    a AM y es igual 12 o PM y hora es distinta que 12, también en el momento de
    formar el nuevo string de la hora con formato de 24 horas se utiliza el append muchas veces.

    En esta versión se utiliza el %12 para saber si corresponderá a AM o PM, se utiliza
    solo una condicional en el caso de que fuese AM y se reemplaza en las posiciones
    donde se encuentra la hora del string original por la nueva convertida.
    */
    int hora=stoi(strHora.substr(0,2)), am_pm=(hora%12)/hora;

    if(strHora[8]=='A')
        am_pm--;
    hora+=(12*am_pm);

    strHora.replace(0,2,(hora<10)?"0"+to_string(hora):to_string(hora));

    return strHora.substr(0,8);
}

int subarray_division_v1(int arrayNumCuadro[],int dia, int mes, int cantidad){
    /*
    Funcionamiento: Método responsable de calcular los caminos en los que se puede dividir
    la barra de chocolate.

    Entradas:
    -arrayNumCuadro[](int): Arreglo que contiene los números de cada cuadro de la barra de chocolate.
    -dia(int): Día del cumpleaños
    -mes (int): Mes del cumpleaños
    -cantidad (int): Cantidad de cuadros que tiene la barra de chocolate.

    Salidas:
    Resultado de la cantidad de caminos obtenidos.

    Comentarios: Este método es más eficiente que subarray_division_v2, debido a que en el otro algoritmo
    se utiliza una variable más llamada posiArreglo y un vector para almacenar los valores que se utilizarán
    luego para realizar la suma y saber si la suma de esos valores almacenados coinciden con el día del
    cumpleaños. Para este proceso se está añadiendo un for más, mientras que en este se evita utilizarlo y
    realiza la suma necesaria en el segundo for y luego salta a la comparación y así obtener el resultado.
    */
    int resultado=0,sumaTemp=0;

    for(int cont1=0; cont1<cantidad-mes+1; cont1++){
        for(int cont2 = cont1; cont2 < cont1+mes; cont2++){
            sumaTemp=sumaTemp+arrayNumCuadro[cont2];
        }
        if(sumaTemp==dia){
            resultado++;
        }
        sumaTemp=0;
    }
    return resultado;
}

int subarray_division_v2(int s[],int dia, int mes, int cantidad){
    /*
    Funcionamiento: Método responsable de calcular los caminos en los que se puede dividir
    la barra de chocolate.

    Entradas:
    -s[](int): Arreglo que contiene los números de cada cuadro de la barra de chocolate.
    -dia(int): Día del cumpleaños
    -mes (int): Mes del cumpleaños
    -cantidad (int): Cantidad de cuadros que tiene la barra de chocolate.

    Salidas:
    Resultado de la cantidad de caminos obtenidos.
    */
    int resultado=0, sumaTemp=0,posiArreglo=0;
    vector<int>nuevoArr(mes);

    for(int posi=0;posi<cantidad;posi++){
        for(int posi2=posi;posi2<mes;posi2++){
            nuevoArr.at(posiArreglo)=s[posi2];
            posiArreglo++;
        }
        for(int posi3=0;posi3<nuevoArr.size();posi3++){
            sumaTemp+=nuevoArr.at(posi3);
        }

        if(sumaTemp==dia){
            resultado++;
        }
        sumaTemp=0;
        posiArreglo=0;
        mes++;
    }
    return resultado;
}

string the_minion_game(string palabra){
    /*
    Funcionamiento: Método responsable de calcular la cantidad máxima de substring que se puede realizar que comience con
    consonante y con vocales con la palabra ingresada.

    Entradas:
    -palabra(string): Palabra con la que se tiene que formar los substrings.

    Salidas:
    Retorna un mensaje indicando el nombre y el puntaje del jugador que haya obtenido más puntos a la hora
    de hacer los substrings.
    */

    //puntaje[0] Kevin
    //puntaje[1] Stuart
    int puntaje[2]={0,0};

    for(int contador=0;contador<palabra.length();contador++){
        puntaje[0]+=((palabra[contador]=='A'||palabra[contador]=='E'||palabra[contador]=='I'||palabra[contador]=='O'||palabra[contador]=='U')?
                        palabra.length()-contador:0);
        puntaje[1]+=((palabra[contador]!='A'&&palabra[contador]!='E'&&palabra[contador]!='I'&&palabra[contador]!='O'&&palabra[contador]!='U')?
                        palabra.length()-contador:0);
    }

    if(puntaje[0]>puntaje[1]){
        return "Kevin "+to_string(puntaje[0]);
    }
    else if(puntaje[0]<puntaje[1]){
        return "Stuart "+to_string(puntaje[1]);
    }
    else{
        return "Draw";
    }
}

string cipher(string s, int longitud, int cantShift){
   /*
    Funcionamiento: Método responsable de decodificar un mensaje binario utilizando el xor.

    Entradas:
    -s(string): Mensaje a decodificar.
    -longitud(int): Longitud del mensaje original antes de ser codificado.
    -cantShift(int): Cantidad de veces que se shifteo el mensaje para ser codificado.

    Salidas:
    -resultado(string): Mensaje decodificado.
   */
    string resultado;
    int aux=0;

    resultado.append(s.substr(0,1));
    for(int contador=1;contador<cantShift;contador++){//Realizar el xor a los primeros digitos hasta la posicion k-1
        resultado.append(to_string(stoi(s.substr(contador,1))^stoi(s.substr(contador-1,1))));
    }

    for (int contador1 = cantShift; contador1 < longitud; contador1++) {
        for (int contador2 = contador1-(cantShift-1); contador2 < contador1; contador2++) {
            aux = aux ^ (int(resultado[contador2])-48);
        }
        resultado.append(to_string(aux^stoi(s.substr(contador1,1))));
        aux=0;
    }
    return resultado.substr(0,longitud);
}

int pairs(int arr[],int n, int k){
    /*
    Funcionamiento: Recibe un arreglo de enteros y calcula la cantidad total de parejas que cuando se restan dan
    el valor de k (la diferencia que debe de haber entre el primer y segundo numero).

    Entradas:
    -arr(vector<int>): Arreglo de enteros para obtener la cantidad de parejas.
    -n(int): Tamaño del arreglo.
    -k(int): Diferencia que tiene que haber entre el primer y el segundo numero de las parejas que se formen.

    Salidas:
    -resultado(int): La cantidad de parejas
    */
    int resultado=0;
    set<int> tabla;
    tabla.insert(arr[0]);

    for(int contador=1;contador<n;contador++){
        resultado+=((tabla.count(arr[contador]+k))?1:0);
        resultado+=((tabla.count(arr[contador]-k))?1:0);
        tabla.insert(arr[contador]);
    }
    return resultado;
}

int main(){
    //------------------------------------Compare the Triplets-------------------------------------------------

    int a1[3]={1,2,3}, b1[3]={3,2,1};
    vector<int>resultado=compare_the_triplets_v1(a1,b1);
    cout<<resultado.at(0)<<" "<<resultado.at(1)<<endl;
    int a11[3]={6,6,6}, b11[3]={6,6,6};
    resultado=compare_the_triplets_v1(a11,b11);
    cout<<resultado.at(0)<<" "<<resultado.at(1)<<endl;

    int a2[3]={17,28,30},b2[3]={99,16,8};
    resultado=compare_the_triplets_v2(a2,b2);
    cout<<resultado.at(0)<<" "<<resultado.at(1)<<endl;
    int a22[3]={88,28,50},b22[3]={5,3,8};
    resultado=compare_the_triplets_v2(a22,b22);
    cout<<resultado.at(0)<<" "<<resultado.at(1)<<endl;


    //------------------------------------Time Conversion-------------------------------------------------

    string hora="12:01:00PM";
    cout<<endl<<time_conversion_v1(hora)<<endl;
    hora="07:05:45PM";
    cout<<time_conversion_v1(hora)<<endl;

    hora="04:59:59AM";
    cout<<time_conversion_v2(hora)<<endl;
    hora="12:00:00AM";
    cout<<time_conversion_v2(hora)<<endl;

    //------------------------------------Subarray Division-------------------------------------------------

    int s1[5]={2,2,1,3,2},d1=4,m1=2,n1=5;
    cout<<endl<<subarray_division_v1(s1,d1,m1,n1)<<endl;
    int s11[1]={4};
    d1=4,m1=1,n1=1;
    cout<<subarray_division_v1(s11,d1,m1,n1)<<endl;

    int s2[5]={1,2,1,3,2},d2=3,m2=2,n2=5;
    cout<<subarray_division_v2(s2,d2,m2,n2)<<endl;
    int s22[6]={1,1,1,1,1,1};
    d2=3,m2=2,n2=6;
    cout<<subarray_division_v2(s22,d2,m2,n2)<<endl;

    //------------------------------------The Minion Game-------------------------------------------------

    string palabra="BANANA";
    cout<<endl<<the_minion_game(palabra)<<endl;

    palabra="BANAASA";
    cout<<the_minion_game(palabra)<<endl;


    //------------------------------------Cipher-------------------------------------------------
    int n=7,k=4;
    string s="1110100110";
    cout<<endl<<cipher(s,n,k)<<endl;

    n=17,k=3;
    s="1010111011101000101";
    cout<<cipher(s,n,k)<<endl;

    //------------------------------------Pairs-------------------------------------------------
    n=7,k=2;
    int arr1[7]={1,3,5,8,6,4,2};
    cout<<endl<<pairs(arr1,n,k)<<endl;

    n=5,k=2;
    int arr2[5]={1,5,3,4,2};
    cout<<pairs(arr2,n,k)<<endl;

}

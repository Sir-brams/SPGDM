#ifndef STRUCTURE_MESURE_H_INCLUDED
#define STRUCTURE_MESURE_H_INCLUDED

typedef struct {
    int j ; /*jour*/
    int m ;/*mois*/
    int a; /*années*/
    float T ; /*température(°C)*/
    float P ; /*pression(hPa)*/
    float H ; /*Humidité relative (%)*/
} mesure ;

#endif // STRUCTURE_MESURE_H_INCLUDED

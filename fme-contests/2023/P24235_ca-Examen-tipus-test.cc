/*
Després de veure els resultats del parcial, els professors d’Algorísmia han
decidit que a partir de l’any vinent l’examen final serà tipus test. Creuen que
així potser aprovarà algú.

L’examen estarà format per n preguntes, on cada pregunta tindrà r ≥ 2 respostes
diferents. Com és habitual, cada resposta correcta sumarà 1 punt, i cada
resposta errònia en restarà 1/(r−1), de tal forma que puntuació esperada
responent a l’atzar sigui exactament 0.

Ara bé, Atenea no permet posar notes negatives i, per tant, en el cas que algú
tingui una nota negativa, s’haurà d’arrodonir a 0. Decebut, el Roura està
preocupat perquè potser la mitjana serà aleshores massa alta.

Quina és la nota esperada d’un estudiant que respongui a l’atzar, tenint en
compte que si la nota és més petita que zero, s’arrodoneix a 0?

Entrada

L’entrada consisteix en diversos casos, cadascun amb n i r. Suposeu 1 ≤ n ≤ 25 i
2 ≤ r ≤ 40.

Sortida

Per a cada cas, escriviu la quantitat demanada amb cinc decimals. Escriviu
aquestes dues línies a l’inici del main():

    cout.setf(ios::fixed);
    cout.precision(5);
*/
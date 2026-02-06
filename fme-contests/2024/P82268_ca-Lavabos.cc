/*
Si alguna cosa és constant a la FME és l’extrema dificultat dels exàmens
d’Algorísmia. Però no pels problemes, sinó per la impossibilitat d’aguantar les
quatre hores d’examen sense anar al lavabo ni un sol cop. Així és: el Roura està
convençut que els alumnes només van al lavabo a fer trampes i, per tant, els
prohibeix sortir de l’aula en tot moment.

Tanmateix, després de moltes denúncies i un llarg procés burocràtic, ha sortit
un nou article judicial:




A Proclamation of Scholars’ Privilege Concerning Restroom Access




Let it be known that the comfort, dignity, and health of all scholars are
sacred. Thus, the liberty to answer the call of nature, unhindered by temporal
restrictions, is declared inviolable and enshrined within these hallowed halls
of learning.

Article I: The Right to Access All students, regardless of station or
circumstance, shall be free to attend the privy as necessity dictates. No
educator shall deny such access as a means of enforcing order or compliance.

Article II: Health and Well-Being Delaying such vital necessities shall not be
required, lest harm befall body or spirit. Tutors must regard nature’s call as
paramount over transient disruptions to instruction. Those with ailments
necessitating frequent visits shall be accommodated without undue burden or
inquiry.

Article III: Privacy and Dignity Restrooms shall offer solace and
privacy, free from intrusion or surveillance. Measures must safeguard against
harassment within these sacred confines.

Article IV: Accountability Denials must
be justified and recorded with reason. Students may petition redress for
grievances to the administration. Institutions shall undergo scrutiny to ensure
adherence to these principles. Conclusion By adherence to these precepts, the
dignity and welfare of all scholars shall be preserved, fostering a realm of
enlightenment wherein no student need suffer for want of access to the
necessary.







La Berta i la Laura estan fent l’examen d’Algorísmia. Ambdues noies presenten el
document anterior, amb la qual cosa el Roura no té més remei que permetre’ls
anar al lavabo.

Suposeu que l’examen dura n minuts. Per a la Berta es disposa d’un vector d’n
bits, on bi = 1 sii voldrà anar al lavabo durant el minut i. També es disposa
d’un vector similar ℓi per a la Laura. Per simplicitat, suposem que les anades i
vingudes duren menys d’un minut.

Podeu calcular el nombre màxim de cops que podran anar al lavabo? Tingueu en
compte que no podran anar-hi simultàniament, i que per equitat hauran d’anar-hi
el mateix nombre de vegades.

Entrada

L’entrada consisteix en diversos casos, cadascun amb dues paraules b i ℓ
compostes amb ‘0’ i ‘1’. Les mides de les dues paraules són iguals, entre 1 i
240.

Sortida

Per a cada cas, escriviu quantes vegades podran anar al lavabo.
*/

#include <iostream>

using namespace std;

int main () {
    string a, b;
    while(cin >> a >> b) {
        int size = a.size();
        int acount = 0, bcount = 0;
        int aandb = 0;
        for(int i = 0; i < size; ++i) {
            bool ai = a[i] == '1';
            bool bi = b[i] == '1';
            if(ai and bi) ++aandb;
            else if(ai) ++acount;
            else if(bi) ++bcount;
        }
        int maxa = acount + aandb;
        int maxb = bcount + aandb;
        int total = (acount + bcount + aandb)/2;
        int ans = min(min(maxa, maxb), total);

        cout << ans << endl;

    }
}
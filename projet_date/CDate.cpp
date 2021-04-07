/*************************************************/
// Rôle du fichier: code de la classe CDate
// Nom des composants utilises: CDate.h
// Nom programmeur: Valentin Andrieu
/*************************************************/

#include "CDate.h"


//Nom : CDate
//Rôle : Constructeur de classe
//Paramètres entree: jour, mois, annee, heures, minutes, secondes

CDate::CDate(int jour, int mois, int annee, int heures, int minutes, int secondes)
{
    this->m_jour = jour;
    this->m_mois = mois;
    this->m_annee = annee;
    this->m_heures = heures;
    this->m_minutes = minutes;
    this->m_secondes = secondes;

}

//Nom : ==
//Rôle : Compare deux dates(égalité)
//Paramètres entree/sortie : date constante par ref
//Retour : booleen

bool CDate::operator==(const CDate & Date){
    bool condition = false;

    if((this->m_annee == Date.m_annee) && (this->m_mois == Date.m_mois)
       && (this->m_jour == Date.m_jour)&& (this->m_heures == Date.m_heures)
       && (this->m_minutes == Date.m_minutes) && (this->m_secondes == Date.m_secondes)){
            condition= true;
    }

    return condition;
}

//Nom : >
//Rôle : Compare deux dates(supériorité)
//Paramètres entree/sortie : date constante par ref
//Retour : booleen

bool CDate::operator>(const CDate & Date){
    bool condition = true;

    if((this->m_annee < Date.m_annee)
       || (this->m_annee == Date.m_annee && this->m_mois < Date.m_mois)
       || (this->m_annee == Date.m_annee && this->m_mois == Date.m_mois && this->m_jour < Date.m_jour)
       || (this->m_annee == Date.m_annee && this->m_mois == Date.m_mois && this->m_jour == Date.m_jour && this->m_heures < Date.m_heures)
       || (this->m_annee == Date.m_annee && this->m_mois == Date.m_mois && this->m_jour == Date.m_jour && this->m_heures == Date.m_heures && this->m_minutes < Date.m_minutes)
       || (this->m_annee == Date.m_annee && this->m_mois == Date.m_mois && this->m_jour == Date.m_jour && this->m_heures == Date.m_heures && this->m_minutes == Date.m_minutes && this->m_secondes < Date.m_secondes)){
        condition = false;

    return condition;
}
}

//Nom : <
//Rôle : Compare deux dates(infériorité)
//Paramètres entree/sortie : date constante par ref
//Retour : booleen

bool CDate::operator<(const CDate & Date){
    bool condition = true;

    if((this->m_annee < Date.m_annee)
       || (this->m_annee == Date.m_annee && this->m_mois > Date.m_mois)
       || (this->m_annee == Date.m_annee && this->m_mois == Date.m_mois && this->m_jour > Date.m_jour)
       || (this->m_annee == Date.m_annee && this->m_mois == Date.m_mois && this->m_jour == Date.m_jour && this->m_heures > Date.m_heures)
       || (this->m_annee == Date.m_annee && this->m_mois == Date.m_mois && this->m_jour == Date.m_jour && this->m_heures == Date.m_heures && this->m_minutes > Date.m_minutes)
       || (this->m_annee == Date.m_annee && this->m_mois == Date.m_mois && this->m_jour == Date.m_jour && this->m_heures == Date.m_heures && this->m_minutes == Date.m_minutes && this->m_secondes > Date.m_secondes)){
        condition = false;

    return condition;

}
}

//Nom : getDate
//Rôle : valeurs par ref. aux quelles on attribue la valeur de la date courante
//Paramètres sorties : jour, mois, annee, heures, minutes, secondes

void CDate::getDate(int &jour, int &mois, int &annee, int &heures, int &minutes, int &secondes){
    jour = this->m_jour;
    mois = this->m_mois;
    annee = this->m_annee;
    heures = this->m_heures;
    minutes = this->m_minutes;
    secondes = this->m_secondes;
}

// Nom : ++
// Rôle : operateur qui ajoute 1 seconde a la date courante
void CDate::operator ++ (){
    if(this->m_secondes !=59){
        this->m_secondes= (this->m_secondes)+1;
    }else if(this->m_mois == 12 && this->m_jour == 31 && this->m_heures==23 && this->m_minutes==59 && this->m_secondes==59){
        (this->m_annee)++;
        this->m_secondes=0;
        this->m_minutes=0;
        this->m_heures=0;
        this->m_mois=1;
        this->m_jour=1;
    }else if(this->m_jour==31 && this->m_heures==23 && this->m_minutes==59 && this->m_secondes==59){
        (this->m_mois)++;
        this->m_jour=1;
        this->m_secondes=0;
        this->m_minutes=0;
        this->m_heures=0;
    }else if(this->jourDansLeMois()==30 && this->m_jour==30 && this->m_heures==23 && this->m_minutes==59 && this->m_secondes==59){
        (this->m_mois)++;
        this->m_jour=1;
        this->m_secondes=0;
        this->m_minutes=0;
        this->m_heures=0;
    }else if(this->anneeBisextile()==false && this->m_mois==2 && this->m_jour==28 && this->m_heures==23 && this->m_minutes==59 && this->m_secondes==59){
        (this->m_mois)++;
        this->m_jour=1;
        this->m_secondes=0;
        this->m_minutes=0;
        this->m_heures=0;
    }else if(this->m_mois==2 && this->m_jour==29 && this->m_heures==23 && this->m_minutes==59 && this->m_secondes==59){
        (this->m_mois)++;
        this->m_jour=1;
        this->m_secondes=0;
        this->m_minutes=0;
        this->m_heures=0;
    }else if(this->m_heures==23 && this->m_minutes==59 && this->m_secondes==59){
        (this->m_jour)++;
        this->m_secondes=0;
        this->m_minutes=0;
        this->m_heures=0;
    }else if(this->m_minutes==59 && this->m_secondes==59){
        this->m_secondes=0;
        this->m_minutes=0;
        (this->m_heures)++;
    }else{
        this->m_secondes=0;
        (this->m_minutes)++;
    }
}

// Nom : anneeBisextile
// Rôle : renvoie true si l'annee de la date courante est bisextile et false sinon
// Retour : booleen
bool CDate::anneeBisextile(){
    if((this->m_annee/4)*4 == this->m_annee)
    {
        if((this->m_annee/100)*100 == this->m_annee)
        {
            if((this->m_annee/400)*400 == this->m_annee)
                {
                    return true;
                }
            else
            {
                return false;
            }
        }
        return true;
    }
    else
    {
        return false;
    }

}

// Nom : jourDansLeMois
// Rôle : renvoie le nombre de jour dans le mois de la date courante
// Retour : entier qui represente le nombre de jours dans le mois
int CDate::jourDansLeMois(){
    switch(this->m_mois)
    {
    case 1:case 3:case 5:case 7:case 8:case 10:case 12:
        return 31;
        break;
    case 4:case 6:case 9: case 11 :
        return 30;
        break;
    case 2:
        {
            if(this->anneeBisextile()== false)
            {
                return 28;
            }
            else
            {
                return 29;
            }
            break;
        }
    }
}




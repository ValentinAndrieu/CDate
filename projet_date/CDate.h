#ifndef CDATE_H
#define CDATE_H


class CDate
{
    public:

        //Nom : CDate
        //Rôle : Constructeur de classe
        //Paramètres entree: jour, mois, annee, heures, minutes, secondes
        CDate(int jour, int mois, int annee, int heures, int minutes, int secondes);

        //Nom : ==
        //Rôle : Compare deux dates(égalité)
        //Paramètres entree/sortie : date constante par ref
        //Retour : booleen
        bool operator == (const CDate & Date);

        //Nom : >
        //Rôle : Compare deux dates(supériorité)
        //Paramètres entree/sortie : date constante par ref
        //Retour : booleen
        bool operator > (const CDate & Date);

        //Nom : <
        //Rôle : Compare deux dates(infériorité)
        //Paramètres entree/sortie : date constante par ref
        //Retour : booleen
        bool operator < (const CDate & Date);

        //Nom : getDate
        //Rôle : valeurs par ref. aux quelles on attribue la valeur de la date courante
        //Paramètres sorties : jour, mois, annee, heures, minutes, secondes
        void getDate(int &jour, int &mois, int &annee, int &heures, int &minutes, int &secondes);

        bool anneeBisextile();

        int jourDansLeMois();

        void operator ++();

    private:
        int m_jour;
        int m_mois;
        int m_annee;
        int m_heures;
        int m_minutes;
        int m_secondes;
};

#endif // CDATE_H

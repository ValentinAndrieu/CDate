#ifndef CDATE_H
#define CDATE_H


class CDate
{
    public:

        //Nom : CDate
        //R�le : Constructeur de classe
        //Param�tres entree: jour, mois, annee, heures, minutes, secondes
        CDate(int jour, int mois, int annee, int heures, int minutes, int secondes);

        //Nom : ==
        //R�le : Compare deux dates(�galit�)
        //Param�tres entree/sortie : date constante par ref
        //Retour : booleen
        bool operator == (const CDate & Date);

        //Nom : >
        //R�le : Compare deux dates(sup�riorit�)
        //Param�tres entree/sortie : date constante par ref
        //Retour : booleen
        bool operator > (const CDate & Date);

        //Nom : <
        //R�le : Compare deux dates(inf�riorit�)
        //Param�tres entree/sortie : date constante par ref
        //Retour : booleen
        bool operator < (const CDate & Date);

        //Nom : getDate
        //R�le : valeurs par ref. aux quelles on attribue la valeur de la date courante
        //Param�tres sorties : jour, mois, annee, heures, minutes, secondes
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

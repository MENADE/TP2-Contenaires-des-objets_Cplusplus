#include "Score.h"
#include <fstream>
#include <iostream>
#include <vector>
#include <set>
#include <string>



 void  afficherJoueurs( std::set<Score> ListeDesJoueurs);

int main()
{
                
    std::set<Score> ListeDesJoueurs;
     
   
 //--1---Lecture de fichier hiscore.txt et transformation de ces données a des objets de type <score> + les mettre dans un conteneur. 
    
      //--1-1-- Test si l'ouverture de fichier <hiscore.txt> s'est bien passée, on peut donc lire le fichier.
      //--1-2-- Gestion d'exception ( cas ou le numero identifiant est égal a zéro)
      //--1-3-- Conservation des objets de type <Score>­ dans un conteneur de type: <std::set> qu'on a appelé <ListeDesJoueurs>
      //--1-4-- Fermeture prématurée du fichier <hiscore.txt> 
   
    std::ifstream lecteur("hiscore.txt");

     //--1-1
    if (lecteur.is_open())
    {
            long identifiant;   
            std::string login;  
            long score; 
    //--1-2
        try 
       {
          
            while (lecteur.eof() == false)  
                {

                lecteur >> identifiant;
                lecteur >> login;
                 lecteur >> score;
                 if (identifiant ==0) throw 1;
     //--1-3
                 if (lecteur.eof() == false)  { ListeDesJoueurs.insert(Score(identifiant, login, score));}
                }                                                                                                  
      
       
         }
     catch (const int& code_erreur) {std::cout << "Le joueur dont le login est: " + login  ;
                                     std::cout << ", ne peut pas etre transformer car il a un numero identifiant invalid de Zero. " << std::endl;
                                    std::cout << std::endl;     }


    }
    else
    {
        std::cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << std::endl;
    }

    //--1-4   
    lecteur.close();




//--2---Conservation en ordre inverse des objets <Score> dans un nouveau fichier "Asterostorm.txt". 
    //--2-1--(voir classe Score.h) implémentation de l'operator< qui compare inversement les joueurs 
    //--2-2- Test d'ouverture de fichier pour assurer que le disque dur n'est pas plein et que vous avez les doit d'accès, donc on peut commencer l'écriture
    //--2-3--Fermeture prématurée du fichier <Asterostorm.txt>

    std::ofstream JoueursIntroduits("Asterostorm.txt");
    std::set<Score>::iterator it;

    //--2-2

       if (JoueursIntroduits.is_open()) 
       {
             for (it = ListeDesJoueurs.begin(); it != ListeDesJoueurs.end(); ++it) 
                {
           
            JoueursIntroduits << it->getLogin() << std::endl;

            JoueursIntroduits << it->getIdentifiantPartie() << std::endl;
                                                                 
            JoueursIntroduits << "Asterostorm="<< it->getScore() << std::endl;
                }
       }

       else
       {
           std::cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << std::endl;
       }
      
      //--2-3
         JoueursIntroduits.close();


//--3--Appel a la méthode d'affichage

        afficherJoueurs(ListeDesJoueurs);
      
    }




 //--3-1--Implémentation de la méthode d'affichage des objets de la classe <Score> 

void  afficherJoueurs( std::set<Score> ListeDesJoueurs)
{
    std::set<Score>::iterator it;
    for (it = ListeDesJoueurs.begin(); it != ListeDesJoueurs.end(); ++it) 
    {
        std::cout << it->getLogin() << std::endl;
        std::cout << it->getIdentifiantPartie() << std::endl;

        std::cout << "Asterostorm=" << it->getScore() << std::endl;
    }
}

//--4--Fin de programme---

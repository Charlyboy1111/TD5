////////////////////////////////////////////////////////////////////////////////
/// VOTRE ENTÊTE ICI
////////////////////////////////////////////////////////////////////////////////

#pragma region "Inclusions" //{

#include "CodeFourni.hpp"
#include "CodeDemande.hpp"

#include <ciso646>
#include <cstddef>
#include <cstdint>

#include <cmath>
#include <ctime>
#include <fstream>
#include <string>
#include <iostream>

using namespace std;

#pragma endregion //}


#pragma region "Globaux" //{

#pragma region "Fonctions" //{

/*
*
*/
void ajouterCible(ListeCibles& liste, const Cible& element){
	// TODO: S'il reste de la place, ajouter l'élément à la fin.
	if (liste.nbElements <= liste.capacite) {
		liste.elements[liste.nbElements] = element;
		liste.nbElements++;
	}
}

/*
*
*/
void retirerCible(ListeCibles& liste, uint32_t id){
	// TODO: Rechercher la cible avec le même ID et le retirer de la liste si
	//       présent. ATTENTION! On parle bien de Cible::id, pas de l'index
	//       dans le tableau.
	int size = liste.nbElements, i = 0;

	while (liste.nbElements == size){
		if (liste.elements[i].id == id) {
			for (int j = i + 1; j < liste.nbElements - 1; j++){
				liste.elements[j - 1] = liste.elements[j];			
			}
			//liste.elements.erase(liste.elements[liste.nbElements]);
			memmove(liste.elements + liste.nbElements, liste.elements + (liste.nbElements + 1), (liste.nbElements) * sizeof(int));//a verifier
			liste.nbElements--;
		}
		i++;
	}
}

/*
*
*/
void lireCibles(istream& fichier, ListeCibles& cibles){
	// TODO: Tant que la fin de fichier n'est pas atteinte :
	// TODO: Lire une 'Cible' à partir du ficher à la position
	//       courante et l'ajouter à la liste.
	while (fichier.peek() != EOF) {
		Cible cible;
		fichier.read((char*)&cible, sizeof(cible));
		ajouterCible(cibles,cible);
	}	
}

/*
*
*/
void ecrireCibles(ostream& fichier, const ListeCibles& cibles){
	// TODO: Écrire tous les éléments de la liste dans le fichier à partir de la position courante.
	fichier.seekp(2 * sizeof(cibles.elements), ios::beg); // Positionnement.
	fichier.write((char*)&cibles.elements, sizeof(cibles.elements)); // Écriture. 
}

/*
*
*/
void ecrireJournalDetection(const string& nomFichier, const JournalDetection& journal, bool& ok){
	// TODO: Ouvrir un fichier en écriture binaire.
	ofstream fichier(nomFichier + ".bin", ios::binary);

	// TODO: Indiquer la réussite ou l'échec de l'ouverture dans 'ok'.
	fichier.open("Fichier.ext", ios::binary | ios::in);
	if (fichier.fail()) {
		cout << "Probleme d’ouverture";
	}
	else {
		cout << "Reussite de l'ouverture" << endl;

		// TODO: Écrire les paramètres de mission dans le fichier.
		fichier.seekp(2 * sizeof(journal.parametres), ios::beg); // Positionnement.
		fichier.write((char*)&journal.parametres, sizeof(journal.parametres)); // Écriture. 
	
		// TODO: Écrire les cibles dans le fichier.
		ecrireCibles(fichier,journal.cibles);
	}	
}

/*
*
*/
void ecrireObservation(const string& nomFichier, size_t index, const string& observation){
	// TODO: Ouvrir un fichier en lecture/écriture binaire.
	fstream fichier(nomFichier + ".bin", ios::in | ios::out | ios::binary);
	
	// TODO: Se positionner (têtes de lecture et d'écriture) au début de la cible 
	//       à l'index donné. On parle ici de l'index dans le fichier, donc 0 est
	//       la première cible dans le fichier, etc.
	fichier.seekg(2 * sizeof(index), ios::beg);
	
	// TODO: Lire cette cible.
	//       ATTENTION! Vous ne devez lire que cette cible isolée, pas tout le
	//       tableau.
	Cible cible;
	fichier.read((char*)&cible, sizeof(cible));
	
	// TODO: Copier l'observation donnée en paramètre dans la cible.
	//       Astuce : strcpy()
	strcpy(cible.observation,observation[observation.size]);
	
	// TODO: Réécrire la cible (et seulement celle-là) dans le fichier.
	fichier.seekp(-1 * streamoff(sizeof(cible)), ios::cur); // Repositionnement.
	fichier.write((char*)&cible, sizeof(cible));
}


ListeCibles allouerListe(size_t capacite){
	// TODO: Créer une 'ListeDonnee' vide (nbElements = 0) avec la capacité donnée.

	
	// TODO: Allouer un tableau de 'Cible' de la taille demandée.
	return {};
}


void desallouerListe(ListeCibles& cibles)
{
	// TODO: Désallouer le tableau d'élément.
	// TODO: Remettre les membres à zéro.
}


JournalDetection lireJournalDetection(const string& nomFichier, bool& ok)
{
	// TODO: Ouvrir un fichier en lecture binaire.
	
	// TODO: Indiquer la réussite ou l'échec de l'ouverture dans 'ok'.
	
	// TODO: Lire les paramètres de mission
	
	// TODO: Compter le nombre de cibles dans le fichier.
	
	// TODO: Allouer la liste de cibles avec la bonne capacité.
	
	// TODO: Lire les cibles.
	return {};
}

#pragma endregion //}

#pragma endregion //}


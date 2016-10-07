// ProjetHugo.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "validationFormat.h"

using namespace std;

int main()
{
	bool resultatImmatriculation = validerImmatriculation("627 XNN");

	if (resultatImmatriculation) {
		cout << "Immatriculation valide\n";
	}
	else {
		cout << "Immatriculation non valide\n";
	}

	bool resultatNiv = validerNiv("11111111111111111");

	if (resultatNiv) {
		cout << "NIV valide\n";
	}
	else {
		cout << "NIV invalide\n";
	}
	
	int bonjour;

	cin >> bonjour;
}


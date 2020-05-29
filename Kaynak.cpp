#include<iostream>
#include "kisi.h"
#include"telefon.h"
#include<string>
#include<vector>

using namespace std;

int main()
{
	int secim = 0;
	telefon t1;
	t1.Id = 0;
	while (secim != '6')
	{
		cout << "\n....::::::TELEFON REHBERI MENU::::::....\n";
		cout << endl;
		cout << "1. Yeni kayit ekle.\n";
		cout << "2. Kayit listesini goster.\n";
		cout << "3. Kayit degistir.\n";
		cout << "4. Arama yap.\n";
		cout << "5. Kayit sil.\n";
		cout << "6. Cikis yap.\n";
		cout << "**Secim yapiniz: ";
		cin >> secim;



		if (secim == 1)
		{
			t1.kayit();

		}
		if (secim == 2)
		{
			t1.kayitGoster();
		}
		if (secim == 3)
		{
			t1.kayitModifiye();
		}
		if (secim == 4)
		{
			t1.arama();
		}
		if (secim == 5)
		{
			t1.kayitSilme();
		}
		if (secim == 6)
		{
			break;
		}
	}
}

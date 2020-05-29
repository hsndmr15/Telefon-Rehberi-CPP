#include "telefon.h"


telefon::telefon()
{



}

void telefon::kayit()
{
	Id++;
	cout << "\n...................::KAYIT SISTEMI::...................\n";
	cout << endl;
	cout << "Kayit edilecek kisinin ismi: ";
	cin >> ad;
	cout << "Kayit edilecek kisinin soyismi: ";
	cin >> soyad;
	cout << "Kayit edilecek kisinin numarasi: ";
	cin >> cep;
	cout << "Kayit edilecek kisinin is numarasi: ";
	cin >> is;



	ID_vec.push_back(Id);
	ad_vec.push_back(ad);
	soyad_vec.push_back(soyad);
	cep_vec.push_back(cep);
	is_vec.push_back(is);



}

void telefon::kayitGoster()
{
	cout << "\n...................::KAYIT LISTESI::...................\n";
	cout << endl;
	for (int i = 0; i < ad_vec.size(); i++)
	{
		for (int j = 0; j < i; j++)
		{
			string ad = ad_vec[i];
			string ad2 = ad_vec[j];
			if (ad.at(0) < ad2.at(0))
			{
				int temp_int;
				string temp_string;
				long long temp_long;

				temp_int = ID_vec[i];
				ID_vec[i] = ID_vec[j];
				ID_vec[j] = temp_int;

				temp_string = ad_vec[i];
				ad_vec[i] = ad_vec[j];
				ad_vec[j] = temp_string;

				temp_string = soyad_vec[i];
				soyad_vec[i] = soyad_vec[j];
				soyad_vec[j] = temp_string;

				temp_long = cep_vec[i];
				cep_vec[i] = cep_vec[j];
				cep_vec[j] = temp_long;

				temp_long = is_vec[i];
				is_vec[i] = is_vec[j];
				is_vec[j] = temp_long;

			}
		}
	}

	ofstream dosya;
	dosya.open("rehber.txt", ios::out);

	for (int i = 0; i < ad_vec.size(); i++)
	{
		if (ID_vec[i] != 0)
		{
			dosya << "ID:" << ID_vec[i] << " Adi:" << ad_vec[i] << " Soyadi:" << soyad_vec[i] << " Cep.No.:" << cep_vec[i] << " Is.No.:" << is_vec[i] << endl;
			cout << "ID:" << ID_vec[i] << " Adi:" << ad_vec[i] << " Soyadi:" << soyad_vec[i] << " Cep.No.:" << cep_vec[i] << " Is.No.:" << is_vec[i] << endl;
		}
	}
	dosya.close();
}

void telefon::kayitModifiye()
{
	cout << "\n...................::KAYIT MODIFIYE SISTEMI::...................\n";
	cout << endl;
	cout << "degistirmrk istenilen kaydin ID'sini giriniz:";
	int searchID;
	cin >> searchID;
	cout << endl;

	int i;
	int flag = 0;
	try {
		for (i = 0; i < ID_vec.size(); i++)
		{
			if (ID_vec[i] == searchID)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1)
		{
			cout << "yeni isim:";
			cin >> ad_vec[i];
			cout << "yeni soyisim:";
			cin >> soyad_vec[i];
			cout << "yeni cep no:";
			cin >> cep_vec[i];
			cout << "yeni is no:";
			cin >> is_vec[i];
		}
		else
			throw "ID'ye sahip kisi bulunamamistir.";
	}
	catch (const char* e)
	{
		cout << e << endl;
	}
	ofstream dosya;
	dosya.open("rehber.txt", ios::out);

	for (int i = 0; i < ad_vec.size(); i++)
	{
		if (ID_vec[i] != 0)
		{
			dosya << ID_vec[i] << " " << ad_vec[i] << " " << soyad_vec[i] << " " << cep_vec[i] << " " << is_vec[i] << endl;

		}
	}
	dosya.close();
}

void telefon::arama()
{
	cout << "\n...................::KAYIT ARAMA SISTEMI::...................\n";
	cout << endl;

	cout << "ID->1" << endl;
	cout << "isim->2" << endl;
	cout << "soyisim->3" << endl;
	cout << "cep no->4" << endl;
	cout << "is no->5" << endl;
	cout << "Aram kriteri seciniz:";
	int tercih;
	cin >> tercih;
	cout << endl;
	if (tercih == 1)
	{
		cout << "ID'ye gore arama yapiliyor" << endl;
		int searchID;
		cin >> searchID;
		cout << endl;
		int i;
		int flagID = 0;
		try {
			for (i = 0; i < ID_vec.size(); i++)
			{
				if (ID_vec[i] == searchID)
				{
					flagID = 1;
					break;
				}

			}
			if (flagID == 1)
			{
				cout << ID_vec[i] << " " << ad_vec[i] << " " << soyad_vec[i] << " " << cep_vec[i] << " " << is_vec[i] << endl;
			}
			else
				throw "Arama kriterinize uygun kisi bulunamadi !";
		}
		catch (const char* e)
		{
			cout << e << endl;
		}
	}

	if (tercih == 2)
	{
		cout << "Isim'e gore arama yapiliyor" << endl;

		string searchname;
		cin >> searchname;
		cout << endl;
		int i;
		int flagName = 0;
		try {
			for (i = 0; i < ad_vec.size(); i++)
			{

				if (ad_vec[i] == searchname)
				{
					flagName = 1;
					break;
				}
			}
			if (flagName == 1)
			{
				cout << ID_vec[i] << " " << ad_vec[i] << " " << soyad_vec[i] << " " << cep_vec[i] << " " << is_vec[i] << endl;
			}
			else
				throw "Arama kriterinize uygun kisi bulunamadi !";
		}
		catch (const char* e)
		{
			cout << e << endl;
		}

	}

	if (tercih == 3)
	{
		cout << "Soyisim'e gore arama yapiliyor" << endl;

		string searchname;
		cin >> searchname;
		cout << endl;
		int i;
		int flagLast = 0;
		try {
			for (i = 0; i < soyad_vec.size(); i++)
			{

				if (soyad_vec[i] == searchname)
				{
					flagLast = 1;
					break;
				}
			}
			if (flagLast == 1)
			{
				cout << ID_vec[i] << " " << ad_vec[i] << " " << soyad_vec[i] << " " << cep_vec[i] << " " << is_vec[i] << endl;

			}
			else
				throw "Arama kriterinize uygun kisi bulunamadi !";
		}
		catch (const char* e)
		{
			cout << e << endl;
		}


	}


	if (tercih == 4)
	{
		cout << "Cep No'ya gore arama yapiliyor" << endl;

		long long searchNo;
		cin >> searchNo;
		cout << endl;
		int i;
		int flagNo = 0;
		try
		{
			for (i = 0; i < cep_vec.size(); i++)
			{

				if (cep_vec[i] == searchNo)
				{
					flagNo = 1;
					break;
				}
			}
			if (flagNo == 1)
			{
				cout << ID_vec[i] << " " << ad_vec[i] << " " << soyad_vec[i] << " " << cep_vec[i] << " " << is_vec[i] << endl;

			}
			else
				throw "Arama kriterinize uygun kisi bulunamadi !";
		}
		catch (const char* e)
		{
			cout << e << endl;
		}

	}

	if (tercih == 5)
	{
		cout << "Is No'ya gore arama yapiliyor" << endl;

		long long searchNo;
		cin >> searchNo;
		cout << endl;
		int i;
		int flagÝs = 0;
		try
		{
			for (i = 0; i < is_vec.size(); i++)
			{

				if (is_vec[i] == searchNo)
				{
					flagÝs = 1;
					break;
				}
			}
			if (flagÝs == 1)
			{
				cout << ID_vec[i] << " " << ad_vec[i] << " " << soyad_vec[i] << " " << cep_vec[i] << " " << is_vec[i] << endl;

			}
			else
				throw "Arama kriterinize uygun kisi bulunamadi !";
		}
		catch (const char* e)
		{
			cout << e << endl;
		}

	}
}

void telefon::kayitSilme()
{
	cout << "\n...................::KAYIT SILME SISTEMI::...................\n";
	cout << endl;
	cout << "silinecek kaydin ID'sini giriniz:" << endl;

	int searchID;
	cin >> searchID;
	cout << endl;
	int i;
	int flagDelete = 0;
	try
	{
		for (i = 0; i < ID_vec.size(); i++)
		{
			if (ID_vec[i] == searchID)
			{
				flagDelete = 1;
				break;
			}
		}
		if (flagDelete == 1)
		{
			ID_vec[i] = 0;
			ad_vec[i] = ' ';
			soyad_vec[i] = ' ';
			cep_vec[i] = 0;
			is_vec[i] = 0;
			cout << "kayit silinmistir !" << endl;
		}
		else
			throw "silmek istediginiz ID'ye sahip kisi bulunamadi!";
	}
	catch (const char* e)
	{
		cout << e << endl;
	}



	ofstream dosya;
	dosya.open("rehber.txt", ios::out);
	for (int i = 0; i < ad_vec.size(); i++)
	{
		if (ID_vec[i] != 0)
		{
			dosya << ID_vec[i] << " " << ad_vec[i] << " " << soyad_vec[i] << " " << cep_vec[i] << " " << is_vec[i] << endl;

		}
	}
	dosya.close();

}


#pragma once
#include<string>
#include <iostream>
#include<vector>
#include "kisi.h"
#include <fstream>
#include <typeinfo>
using namespace std;
class telefon :public kisi
{
public:
	telefon();
	void kayit();
	void kayitGoster();
	void kayitModifiye();
	void arama();
	void kayitSilme();


};


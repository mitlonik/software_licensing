#include "Header.h"

void readFromFile(char s1[]) {
	std::ifstream file_read("input.txt");				// считываем содержимое файла
	if (!file_read.is_open())							// если файл не открыт
		std::cout << "File could not be opened!\n";		// сообщить об этом
	else {
		file_read.getline(s1, 255);						// записываем данные в буфер s1
		file_read.close();								// закрываем файл
		std::cout << s1 << "\n";
	}
}

void writeToFile(char s1[]) {
	std::ofstream file_write("output.txt", std::ios_base::out);	// дл€ записи в файл
	if (!file_write.is_open())									// если файл небыл открыт
		std::cout << "The file cannot be opened or created\n";	// сообщить об этом
	else {
		file_write << s1;
		std::cout << "Data recorded in output.txt \n";
	}
}
/*
void lisense() {
	

	
}*/

void boost(char s1[]) {

	char *pch;
	for (pch = s1; *pch; pch++) {
		if (isalpha(s1[0])) {
			//lisense();
			unsigned int timer = clock();						// running time
			std::cout << "timer: " << timer / 1000 << " seconds & " << timer % 1000 << " miliseconds \n\n";

			char licenseKey[255], licenseCheck[255];
			std::ifstream license_read("license.txt");			// считываем содержимое файла
			if (!license_read.is_open())						// если файл не открыт
				std::cout << "File could not be opened!\n";		// сообщить об этом
			else {
				license_read.getline(licenseKey, 255);			// записываем данные в буфер s1
				license_read.close();							// закрываем файл
				//std::cout << licenseKey << "\n";
			}
			do {
				printf("Please, input license key: ");
				std::cin >> licenseCheck;
				std::cout << "licenseCheck: " << licenseCheck << " \n" << "licenseKey: " << licenseKey << "\n";
				if (!strcmp(licenseCheck, licenseKey)) {             // проверка на неравенство строк
					std::cout << "U have 5 minutes \n";
					Sleep(3000);
					continue;
				}
				else {
					std::cout << "Key wrong \n";
					exit(0);
				}
			} while (timer >= 3000);

			if (isalpha(*pch)) {
				if (isupper(s1[0]))
					*pch = toupper(*pch);
				else
					*pch = tolower(*pch);
			}
			else continue;
		}
		else {
			if (isalpha(*pch)) {
				if (isupper(s1[0]))
					*pch = toupper(*pch);
				else
					*pch = tolower(*pch);
			}
			else continue;
		}
	}
	puts(s1);
}

int main()
{
	char s1[255];
	
	readFromFile(s1);									// функци€ считывани€ из файла
	boost(s1);											// функци€ - "ѕо¬ыЎаЋкј"
	writeToFile(s1);									// функци€ дл€ записи в файл
	
	_getch();
	return 0;
}
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

void licenseReadFromFile(char licenseKey[]) {
	licenseKey[255];
	std::ifstream license_read("license.txt");			// считываем содержимое файла
	if (!license_read.is_open())						// если файл не открыт
		std::cout << "File could not be opened!\n";		// сообщить об этом
	else {
		license_read.getline(licenseKey, 255);			// записываем данные в буфер s1
		license_read.close();							// закрываем файл
	}
}

void boost(char s1[]) {
	char *pch = nullptr, ask;
	/*
	clock_t start, finish;
	start = clock();
	finish = clock();
	std::cout << "start: " << start << "finish: " << finish << "finish - start: " << (finish - start) / CLOCKS_PER_SEC << "\n";
	*/
	unsigned int start = clock() / CLOCKS_PER_SEC;						// running time, CLOCKS_PER_SEC - the number of clock cycles per second
	std::cout << "timer: " << start << " seconds \n\n";
	unsigned int finish = 300;

	char licenseKey[255], licenseCheck[255];					// определили переменные храни€ и проверки ключей лицензии
	licenseReadFromFile(licenseKey);							// записали ключ из файла в переменную
	
	do {
		for (pch = s1; *pch; pch++) {
			if (isalpha(*pch) && isupper(s1[0])) {
				if ((finish - start) > 0)
					*pch = toupper(*pch);
				else {
					printf("Please, input license key: ");
					std::cin >> licenseCheck;
					if (!strcmp(licenseCheck, licenseKey)) {            // проверка на неравенство строк
						std::cout << "U have 5 minutes \n" ;
						*pch = toupper(*pch);
						finish += 300; // +5 минут , потому что условие работает на разницу значений
					}
					else {
						std::cout << "Key wrong \n";
						exit(0);
					}
				}
			}
			else if (isalpha(*pch) && islower(s1[0]))
				*pch = tolower(*pch);
			else continue;
		}
		puts(s1);

		std::cout << "would you like to enter manually? Y or N \n";
		std::cin >> ask;
		if (ask == 'y' || ask == 'Y') {
			std::cout << "Write the text! \n";
			std::cin >> s1;
		}
	} while (ask == 'y' || ask == 'Y');
	finish = clock();							// конечное врем€
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
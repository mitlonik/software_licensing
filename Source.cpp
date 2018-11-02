#include "Header.h"

void readFromFile(char s1[]) {
	std::ifstream file_read("input.txt");				// ��������� ���������� �����
	if (!file_read.is_open())							// ���� ���� �� ������
		std::cout << "File could not be opened!\n";		// �������� �� ����
	else {
		file_read.getline(s1, 255);						// ���������� ������ � ����� s1
		file_read.close();								// ��������� ����
		std::cout << s1 << "\n";
	}
}

void writeToFile(char s1[]) {
	std::ofstream file_write("output.txt", std::ios_base::out);	// ��� ������ � ����
	if (!file_write.is_open())									// ���� ���� ����� ������
		std::cout << "The file cannot be opened or created\n";	// �������� �� ����
	else {
		file_write << s1;
		std::cout << "Data recorded in output.txt \n";
	}
}

void licenseReadFromFile(char licenseKey[]) {
	licenseKey[255];
	std::ifstream license_read("license.txt");			// ��������� ���������� �����
	if (!license_read.is_open())						// ���� ���� �� ������
		std::cout << "File could not be opened!\n";		// �������� �� ����
	else {
		license_read.getline(licenseKey, 255);			// ���������� ������ � ����� s1
		license_read.close();							// ��������� ����
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

	char licenseKey[255], licenseCheck[255];					// ���������� ���������� ������ � �������� ������ ��������
	licenseReadFromFile(licenseKey);							// �������� ���� �� ����� � ����������
	
	do {
		for (pch = s1; *pch; pch++) {
			if (isalpha(*pch) && isupper(s1[0])) {
				if ((finish - start) > 0)
					*pch = toupper(*pch);
				else {
					printf("Please, input license key: ");
					std::cin >> licenseCheck;
					if (!strcmp(licenseCheck, licenseKey)) {            // �������� �� ����������� �����
						std::cout << "U have 5 minutes \n" ;
						*pch = toupper(*pch);
						finish += 300; // +5 ����� , ������ ��� ������� �������� �� ������� ��������
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
	finish = clock();							// �������� �����
}

int main()
{
	char s1[255];
	
	readFromFile(s1);									// ������� ���������� �� �����
	boost(s1);											// ������� - "���������"
	writeToFile(s1);									// ������� ��� ������ � ����
	
	_getch();
	return 0;
}
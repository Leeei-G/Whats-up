#include<iostream>;
using namespace std;
#include<string>;
#define MAX  1000


void showMenu()
{
	cout << "*****  1�������ϵ��  *****" << endl;
	cout << "*****  2����ʾ��ϵ��  *****" << endl;
	cout << "*****  3��ɾ����ϵ��  *****" << endl;
	cout << "*****  4��������ϵ��  *****" << endl;
	cout << "*****  5���޸���ϵ��  *****" << endl;
	cout << "*****  6�������ϵ��  *****" << endl;
	cout << "*****  0���˳�ͨѶ¼  *****" << endl;
}

struct Person
{
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_Phone;
	string m_Addr;
};

struct Addressbooks
{
	struct Person personArr[MAX];//ͨѶ¼�б������ϵ������
	int m_size;//ͨѶ¼����Ա����
};

void addPerson(Addressbooks* abs)
{
	if (abs->m_size == MAX)
	{
		cout<< "ͨѶ¼�������޷����" << endl;
		return;
	}
	else
	{
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArr[abs->m_size].m_Name = name;

		cout << "�������Ա�: " << endl;
		cout << "1 -- ��" << endl;
		cout << "2 -- Ů" << endl;

		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArr[abs->m_size].m_Sex = sex;
				break;
			}
			cout << "������������������";
		}

		cout << "����������: " << endl;
		int age = 0;
		cin >> age;
		abs->personArr[abs->m_size].m_Age = age;

		cout << "��������ϵ�绰��" << endl;
		string phone = "";
		cin >> phone;
		abs->personArr[abs->m_size].m_Phone = phone;

		cout << "�������ͥסַ��" << endl;
		string address = "";
		cin >> address;
		abs->personArr[abs->m_size].m_Addr = address;

		abs->m_size++;

		cout << "��ӳɹ�" << endl;
		system("pause");
		system("cls");
	}
}

int isExist(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_size; i++)
	{
		if (abs->personArr[i].m_Name == name)
		{
			return i;
		}
	}
	return -1;
}

void showPerson(Addressbooks* abs)
{
	if (abs->m_size == 0)
	{
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "xing ming: " << abs->personArr[i].m_Name << "\t";
			cout << "xing bie: " << (abs->personArr[i].m_Sex == 1 ? "��" : "Ů") << "\t";
			cout << "nian ning: " << abs->personArr[i].m_Age << "\t";
			cout << "dian hua: " << abs->personArr[i].m_Phone << "\t";
			cout << "zhu zhi: " << abs->personArr[i].m_Addr << endl;
		}
	}

	system("pause");
	system("cls");

}

void findPerson(Addressbooks* abs)
{
	cout << "��������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "������" << abs->personArr[ret].m_Name << "\t";
		cout << "�Ա�" << abs->personArr[ret].m_Sex << "\t";
		cout << "���䣺" << abs->personArr[ret].m_Age << "\t";
		cout << "�绰��" << abs->personArr[ret].m_Phone << "\t";
		cout << "סַ��" << abs->personArr[ret].m_Addr << endl;
	}
	else
	{
		cout << "���޴���" << endl;

	}

	system("pause");
	system("cls");
}

void deletePerson(Addressbooks* abs)
{
	cout << "��������Ҫɾ������ϵ��" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1)
	{
		for (int i = ret; i < abs->m_size; i++)
		{
			abs->personArr[i] = abs->personArr[i + 1];
		}
		abs->m_size--;
		cout << "ɾ���ɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}

	system("pause");
	system("cls");
}

void modifyPerson(Addressbooks* abs)
{
	cout << "��������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1)
	{
		string name;
		cout << "������������" << endl;
		cin >> name;
		abs->personArr[ret].m_Name = name;

		cout << "�������Ա�" << endl;
		cout << "1 -- ��" << endl;
		cout << "2 -- Ů" << endl;

		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArr[ret].m_Sex = sex;
				break;
			}
			cout << "������������������";
		}

		cout << "���������䣺" << endl;
		int age = 0;
		cin >> age;
		abs->personArr[ret].m_Age = age;

		cout << "��������ϵ�绰��" << endl;
		string phone = "";
		cin >> phone;
		abs->personArr[ret].m_Phone = phone;

		cout << "�������ͥסַ��" << endl;
		string address = "";
		cin >> address;
		abs->personArr[ret].m_Addr = address;

		cout << "�޸ĳɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}

	system("pause");
	system("cls");

}

void cleanPerson(Addressbooks* abs)
{
	abs->m_size = 0;
	cout << "ͨѶ¼�����" << endl;
	system("pause");
	system("cls");
}

int main()
{
	Addressbooks abs;
	abs.m_size = 0;

	int select = 0;
	
	while (true)
	{
		showMenu();

		cin >> select;

		switch (select)
		{
		case 1: //�����ϵ��
			addPerson(&abs);
			break;
		case 2: //��ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3: //ɾ����ϵ��
			deletePerson(&abs);
			break;
		case 4: //������ϵ��
			findPerson(&abs);
			break;
		case 5: //�޸���ϵ��
			modifyPerson(&abs);
			break;
		case 6: //�����ϵ��
			cleanPerson(&abs);
			break;
		case 0: //�˳�ͨѶ¼

			cout << "welcome back" << endl;
			system("pause");
			return 0;
			break;
		
		}
	}

	system("pause");

	return 0;
}
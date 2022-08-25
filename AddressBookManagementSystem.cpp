#include<iostream>;
using namespace std;
#include<string>;
#define MAX  1000


void showMenu()
{
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
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
	struct Person personArr[MAX];//通讯录中保存的联系人数组
	int m_size;//通讯录中人员个数
};

void addPerson(Addressbooks* abs)
{
	if (abs->m_size == MAX)
	{
		cout<< "通讯录已满，无法添加" << endl;
		return;
	}
	else
	{
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArr[abs->m_size].m_Name = name;

		cout << "请输入性别: " << endl;
		cout << "1 -- 男" << endl;
		cout << "2 -- 女" << endl;

		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArr[abs->m_size].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入";
		}

		cout << "请输入年龄: " << endl;
		int age = 0;
		cin >> age;
		abs->personArr[abs->m_size].m_Age = age;

		cout << "请输入联系电话：" << endl;
		string phone = "";
		cin >> phone;
		abs->personArr[abs->m_size].m_Phone = phone;

		cout << "请输入家庭住址：" << endl;
		string address = "";
		cin >> address;
		abs->personArr[abs->m_size].m_Addr = address;

		abs->m_size++;

		cout << "添加成功" << endl;
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
		cout << "当前记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_size; i++)
		{
			cout << "xing ming: " << abs->personArr[i].m_Name << "\t";
			cout << "xing bie: " << (abs->personArr[i].m_Sex == 1 ? "男" : "女") << "\t";
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
	cout << "请输入您要查找的联系人" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "姓名：" << abs->personArr[ret].m_Name << "\t";
		cout << "性别：" << abs->personArr[ret].m_Sex << "\t";
		cout << "年龄：" << abs->personArr[ret].m_Age << "\t";
		cout << "电话：" << abs->personArr[ret].m_Phone << "\t";
		cout << "住址：" << abs->personArr[ret].m_Addr << endl;
	}
	else
	{
		cout << "查无此人" << endl;

	}

	system("pause");
	system("cls");
}

void deletePerson(Addressbooks* abs)
{
	cout << "请输入您要删除的联系人" << endl;
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
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}

	system("pause");
	system("cls");
}

void modifyPerson(Addressbooks* abs)
{
	cout << "请输入您要修改的联系人" << endl;
	string name;
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1)
	{
		string name;
		cout << "请输入姓名：" << endl;
		cin >> name;
		abs->personArr[ret].m_Name = name;

		cout << "请输入性别：" << endl;
		cout << "1 -- 男" << endl;
		cout << "2 -- 女" << endl;

		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArr[ret].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入";
		}

		cout << "请输入年龄：" << endl;
		int age = 0;
		cin >> age;
		abs->personArr[ret].m_Age = age;

		cout << "请输入联系电话：" << endl;
		string phone = "";
		cin >> phone;
		abs->personArr[ret].m_Phone = phone;

		cout << "请输入家庭住址：" << endl;
		string address = "";
		cin >> address;
		abs->personArr[ret].m_Addr = address;

		cout << "修改成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}

	system("pause");
	system("cls");

}

void cleanPerson(Addressbooks* abs)
{
	abs->m_size = 0;
	cout << "通讯录已清空" << endl;
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
		case 1: //添加联系人
			addPerson(&abs);
			break;
		case 2: //显示联系人
			showPerson(&abs);
			break;
		case 3: //删除联系人
			deletePerson(&abs);
			break;
		case 4: //查找联系人
			findPerson(&abs);
			break;
		case 5: //修改联系人
			modifyPerson(&abs);
			break;
		case 6: //清空联系人
			cleanPerson(&abs);
			break;
		case 0: //退出通讯录

			cout << "welcome back" << endl;
			system("pause");
			return 0;
			break;
		
		}
	}

	system("pause");

	return 0;
}
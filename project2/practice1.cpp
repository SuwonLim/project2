/*
*Banking System ver0.1
*�ۼ��� : suwon lim
*���� : oop �ܰ躰 ������Ʈ�� �⺻ Ʋ ����*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>


using namespace std;
const int NAME_LEN = 20;

void ShowMenu(void); // �޴� ���
void MakeAccount(void); // ���� �����
void DepositMoney(void); // �Ա�
void WithdrawMoney(void); //���
void ShowAllAccInfo(void); // �ܾ� ��ȸ

enum{ MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};
// enum �� ������ ������� ����

typedef struct {
	int accID;	// ���¹�ȣ
	int balance;	// �ܾ�
	char customerName[NAME_LEN];	// ���̸�
} Account;	//���� ����ü �̸� ����

Account accArr[100];	// ���°� �� ����ü�� 100�� ����
int accNum = 0;	// ����� ���� ��

int main(void) {

	int choice;

	while (1)
	{
		ShowMenu();
		cout << "���� : ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case MAKE:
			MakeAccount();
			break;
		case DEPOSIT:
			DepositMoney();
			break;
		case WITHDRAW:
			WithdrawMoney();
			break;
		case INQUIRE:
			ShowAllAccInfo();
			break;
		case EXIT:
			return 0;
		default:
			cout << "not in form selection" << endl;
		}
	}
	return 0;
}


void ShowMenu(void)
{
	cout << "\n\n--------MENU-------" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �Ա�" << endl;
	cout << "3. ���" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
}


void MakeAccount(void) // ���� ����
{
	int id;
	char name[NAME_LEN];
	int balance;

	cout << "[���� ����]" << endl;
	cout << "���� id : "; cin >> id;
	cout << "�̸� : "; cin >> name;
	cout << "�Աݾ� : "; cin >> balance;
	cout << "- - �����Ϸ� - -"<<endl;

	accArr[accNum].accID = id;
	accArr[accNum].balance = balance;
	strcpy(accArr[accNum].customerName, name);
	accNum++;
}


void DepositMoney(void)
{
	int money;
	int id;
	cout << "[��  ��]" << endl;
	cout << "���� id : "; cin >> id;
	cout << "�Աݾ� : "; cin >> money;
	cout << "�ԱݿϷ�" << endl;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i].accID == id)
		{
			accArr[i].balance += money;
			cout << "- - �ԱݿϷ� - -" << endl;
			return; // �Լ����� ��ȯ���� void�� �׳� return;
		}
	}
}

void WithdrawMoney(void)
{
	int id;
	int money;
	cout << "[�� ��]" << endl;
	cout << "���� id : "; cin >> id;
	cout << "����� �ݾ� : " ; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i].accID == id)
		{
			cout << accArr[i].customerName << "�� ȯ���մϴ�\n";
			if (accArr[i].balance < money)
			{
				cout << "- - �ܾ׺��� - -" << endl;
			}
			accArr[i].balance -= money;
			cout << "���� �ܰ�� " << accArr[i].balance << " �� �Դϴ�\n";
			cout << "- - ��ݿϷ� - - " << endl;

		}
	}
	
}

void ShowAllAccInfo(void)
{
	for (int i = 0; i < accNum; i++)
	{
			cout << "���� id : " << accArr[i].accID << endl;
			cout << "�̸� : " << accArr[i].customerName << endl;
			cout << "�ܰ� : " << accArr[i].balance <<"\n\n"<< endl;
	}
}




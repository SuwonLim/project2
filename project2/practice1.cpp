/*
*Banking System ver0.1
*작성자 : suwon lim
*내용 : oop 단계별 프로젝트의 기본 틀 구성*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>


using namespace std;
const int NAME_LEN = 20;

void ShowMenu(void); // 메뉴 출력
void MakeAccount(void); // 계좌 만들기
void DepositMoney(void); // 입금
void WithdrawMoney(void); //출금
void ShowAllAccInfo(void); // 잔액 조회

enum{ MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT};
// enum 은 연관된 상수들의 집합

typedef struct {
	int accID;	// 계좌번호
	int balance;	// 잔액
	char customerName[NAME_LEN];	// 고객이름
} Account;	//끝에 구조체 이름 적기

Account accArr[100];	// 계좌가 들어갈 구조체를 100개 선언
int accNum = 0;	// 저장된 계좌 수

int main(void) {

	int choice;

	while (1)
	{
		ShowMenu();
		cout << "선택 : ";
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
	cout << "1. 계좌개설" << endl;
	cout << "2. 입금" << endl;
	cout << "3. 출금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;
}


void MakeAccount(void) // 계좌 개설
{
	int id;
	char name[NAME_LEN];
	int balance;

	cout << "[계좌 개설]" << endl;
	cout << "계좌 id : "; cin >> id;
	cout << "이름 : "; cin >> name;
	cout << "입금액 : "; cin >> balance;
	cout << "- - 개설완료 - -"<<endl;

	accArr[accNum].accID = id;
	accArr[accNum].balance = balance;
	strcpy(accArr[accNum].customerName, name);
	accNum++;
}


void DepositMoney(void)
{
	int money;
	int id;
	cout << "[입  금]" << endl;
	cout << "계좌 id : "; cin >> id;
	cout << "입금액 : "; cin >> money;
	cout << "입금완료" << endl;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i].accID == id)
		{
			accArr[i].balance += money;
			cout << "- - 입금완료 - -" << endl;
			return; // 함수종료 반환형이 void라서 그냥 return;
		}
	}
}

void WithdrawMoney(void)
{
	int id;
	int money;
	cout << "[출 금]" << endl;
	cout << "계좌 id : "; cin >> id;
	cout << "출금할 금액 : " ; cin >> money;

	for (int i = 0; i < accNum; i++)
	{
		if (accArr[i].accID == id)
		{
			cout << accArr[i].customerName << "님 환영합니다\n";
			if (accArr[i].balance < money)
			{
				cout << "- - 잔액부족 - -" << endl;
			}
			accArr[i].balance -= money;
			cout << "남은 잔고는 " << accArr[i].balance << " 원 입니다\n";
			cout << "- - 출금완료 - - " << endl;

		}
	}
	
}

void ShowAllAccInfo(void)
{
	for (int i = 0; i < accNum; i++)
	{
			cout << "계좌 id : " << accArr[i].accID << endl;
			cout << "이름 : " << accArr[i].customerName << endl;
			cout << "잔고 : " << accArr[i].balance <<"\n\n"<< endl;
	}
}




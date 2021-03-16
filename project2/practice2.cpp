#include<iostream>
#include<string>

using namespace std;

int BinarySearch(int* a, const int x, const int left, const int right)
{
	if (left <= right)
	{
		int middle = (left + right) / 2; // �߰��� ���ϱ� 2.5�� ��� 2�� ���Ѵ� (int)
		if (x < a[middle]) return BinarySearch(a, x, left, middle - 1); // �߰��� �������� Ž��
		else if (x > a[middle]) return BinarySearch(a, x, middle + 1, right); // �߰��� �������� Ž��
		return middle;	// �� ���� ã�� �ִ� ���� �߰����̾��� ���
	}
	return -1;
}

int main(void)
{
	int exArr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	cout << "ã�� ���� �ε��� :" << BinarySearch(exArr, 4, 1, 10) << endl;	//�迭�� �̸��� �ּ�.

	return 0;

}
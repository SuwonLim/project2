#include<iostream>
#include<string>

using namespace std;

int BinarySearch(int* a, const int x, const int left, const int right)
{
	if (left <= right)
	{
		int middle = (left + right) / 2; // 중간값 정하기 2.5일 경우 2를 취한다 (int)
		if (x < a[middle]) return BinarySearch(a, x, left, middle - 1); // 중간값 좌측에서 탐색
		else if (x > a[middle]) return BinarySearch(a, x, middle + 1, right); // 중간값 우측에서 탐색
		return middle;	// 이 경우는 찾고 있던 값이 중간값이었던 경우
	}
	return -1;
}

int main(void)
{
	int exArr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	cout << "찾는 수의 인덱스 :" << BinarySearch(exArr, 4, 1, 10) << endl;	//배열은 이름이 주소.

	return 0;

}
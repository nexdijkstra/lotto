#include<iostream>
#include<string>
#include<time.h>
#include<fstream>
#include<stdlib.h>

using namespace std;

class lottomachine {

	float lottoprobability[46];//로또의 확률을 저장하는 변수
	int lottonumber[46];//로또 번호의 빈도수를 저장하는 변수
	fstream Lottofile;

	lottomachine() {
		for (int i = 0; i < 46; i++) {
			lottonumber[i] = 0;
		}
	}

public:

	lottomachine(string filepath) {
		for (int i = 0; i < 46; i++) {
			lottonumber[i] = 0;
			lottoprobability[i] = 0;
		}
		Lottofile.open(filepath.c_str(), ios::in);//csv파일 오픈
	}

	void getNumber() {
		string str;
		int i = 0;
		while (getline(Lottofile, str, ',')) {
				/* 횟수에 따라 번호 7자리 구분*/
			if (i > 7) {
				i = 0;
			}
			if (i >= 1 && i <= 7) {
				AtoI(str);//번호에 따라 로또의 빈도수를 저장하는 변수에 저장
			}
			i++;
		}
	}

	void pickNumber() {//번호를 뽑는 함수
		for (int i = 0; i < 46; i++) {
			lottonumber[i] = 0;
			lottoprobability[i] = 0;
		}
		/*다음의 순서로 번호를 선택해야 선택이 된다.*/
		getNumber();
		ratingNumber();
		findProbability(); 
		allRandom(); 

		float tempnumber[46] = { 0.0 };
		for (int i = 0; i < 46; i++) {
			tempnumber[i] = lottoprobability[i];//원본 보존
		}

		int i = 7;
		int index = 1;
		float max = tempnumber[index];
		while (i--) {
			for (int j = 2; j < 46; j++) {
				if (max < tempnumber[j]) {//빈도수의 최대값 구하기
					index = j;
					max = tempnumber[j];
				} else if (max == tempnumber[j]) {//만약 빈도수가 같으면 랜덤하게 수 선택
					int coin = rand() % 2;
					if (coin == 0) {
						index = j;
						max = tempnumber[j];
					} else {
						continue;
					}
				}
			}

			cout << index << " ";
			tempnumber[index] = -1;
			index = 1;
			max = tempnumber[index];
		}
	}

private:
	void ratingNumber() {
		for (int i = 1; i < 46; i++) {
			lottoprobability[i] = ((float) lottonumber[i] / 624);//나온 숫자의 빈도수 구하기 나온 횟수/전체 횟수
		}

	}
	void findBigNumber() {

		int tempnumber[46] = { 0 };
		for (int i = 1; i < 46; i++) {
			tempnumber[i] = lottonumber[i];
		}

		int i = 45;
		int index = 1;
		int max = tempnumber[1];
		while (i--) {
			for (int j = 2; j < 46; j++) {
				if (max < tempnumber[j]) {
					index = j;
					max = tempnumber[j];
				}
			}
			lottoprobability[index] = (float) (tempnumber[index]) / 624;
			tempnumber[index] = 0;
			index = 1;
			max = tempnumber[index];
		}
	}

	void AtoI(string str) {

		if (str == "1") {
			lottonumber[1]++;
		} else if (str == "2") {
			lottonumber[2]++;
		} else if (str == "3") {
			lottonumber[3]++;
		} else if (str == "4") {
			lottonumber[4]++;
		} else if (str == "5") {
			lottonumber[5]++;
		} else if (str == "6") {

			lottonumber[6]++;

		} else if (str == "7") {

			lottonumber[7]++;

		} else if (str == "8") {

			lottonumber[8]++;

		} else if (str == "9") {

			lottonumber[9]++;

		} else if (str == "10") {

			lottonumber[10]++;

		} else if (str == "11") {

			lottonumber[11]++;

		} else if (str == "12") {

			lottonumber[12]++;

		} else if (str == "13") {

			lottonumber[13]++;

		} else if (str == "14") {

			lottonumber[14]++;

		} else if (str == "15") {

			lottonumber[15]++;

		} else if (str == "16") {

			lottonumber[16]++;

		} else if (str == "17") {

			lottonumber[17]++;

		} else if (str == "18") {

			lottonumber[18]++;

		} else if (str == "19") {

			lottonumber[19]++;

		} else if (str == "20") {

			lottonumber[20]++;

		} else if (str == "21") {

			lottonumber[21]++;

		} else if (str == "22") {

			lottonumber[22]++;

		} else if (str == "23") {

			lottonumber[23]++;

		} else if (str == "24") {

			lottonumber[24]++;

		} else if (str == "25") {

			lottonumber[25]++;

		} else if (str == "26") {

			lottonumber[26]++;

		} else if (str == "27") {

			lottonumber[27]++;

		} else if (str == "28") {

			lottonumber[28]++;

		} else if (str == "29") {

			lottonumber[29]++;

		} else if (str == "30") {

			lottonumber[30]++;

		} else if (str == "31") {

			lottonumber[31]++;

		} else if (str == "32") {

			lottonumber[32]++;

		} else if (str == "33") {

			lottonumber[33]++;

		} else if (str == "34") {

			lottonumber[34]++;

		} else if (str == "35") {

			lottonumber[35]++;

		} else if (str == "36") {

			lottonumber[36]++;

		} else if (str == "37") {

			lottonumber[37]++;

		} else if (str == "38") {

			lottonumber[38]++;

		} else if (str == "39") {

			lottonumber[39]++;

		} else if (str == "40") {

			lottonumber[40]++;

		} else if (str == "41") {

			lottonumber[41]++;

		} else if (str == "42") {

			lottonumber[42]++;

		} else if (str == "43") {

			lottonumber[43]++;

		} else if (str == "44") {

			lottonumber[44]++;

		} else if (str == "45") {

			lottonumber[45]++;

		}

	}

	void findProbability() {
		int i = 7;
		int odd = 0;
		int even = 0;
		int temp[8] = { 0 };

		while (1) {
			while (i--) {
					/* 1~10 , 11~ 20,...31~40 까지는 20프로의 확률로
					 * 41~45 까지는 10%의 확률로 구한다.*/
				int number = rand() % 9;
				if (number == 0 || number == 1) {
					int number = (rand() % 10) + 1;
					if (number % 2 != 0)
						odd++;
					else
						even++;
					temp[i] = number;

				} else if (number == 2 || number == 3) {

					int number = (rand() % 10) + 11;
					if (number % 2 != 0)
						odd++;
					else
						even++;
					temp[i] = number;
				} else if (number == 4 || number == 5) {
					int number = (rand() % 10) + 21;
					if (number % 2 != 0)
						odd++;
					else
						even++;
					temp[i] = number;

				} else if (number == 6 || number == 7) {
					int number = (rand() % 10) + 31;
					if (number % 2 != 0)
						odd++;
					else
						even++;
					temp[i] = number;
				} else if (number == 8) {
					int number = (rand() % 5) + 41;
					if (number % 2 != 0)
						odd++;
					else
						even++;
					temp[i] = number;
				}
			}

			if (odd < even) {//홀수가 더 커야지 숫자를 승인
				i = 7;
				odd = 0;
				even = 0;
				continue;

			} else {
				break;
			}

		}

		/*위에서 뽑은 번호에 확률을 더해준다.*/
		for (int k = 1; k < 8; k++) {
			if (temp[k] >= 1 && temp[k] <= 40) {
				if (lottoprobability[temp[k]] >= 0.0) {
					lottoprobability[temp[k]] += 0.04;
				} else {
					lottoprobability[temp[k]] = 0;
					lottoprobability[temp[k]] += 0.04;
				}
			} else {
				if (lottoprobability[temp[k]] >= 0.0) {
					lottoprobability[temp[k]] += 0.02;
				} else {
					lottoprobability[temp[k]] = 0;
					lottoprobability[temp[k]] += 0.02;
				}
			}
		}
	}

	void allRandom() {
			/*모든 번호를 랜덤으로 뽑아봄*/
		int num = (rand() % 45) + 1;
		lottoprobability[num] += (1 / 45);

	}
};

int main() {

	srand((int) time(NULL));

	lottomachine Lottomachine("lotto1.csv");

	for (int i = 0; i < 10; i++) {
		Lottomachine.pickNumber();
		cout << endl;
	}

	return 0;
}

#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;

vector<string> words;
string buffer;

int main() 
{
	ifstream in_file("harry.txt"); 
	try { // 예외처리
		if (in_file.fail())//파일없을때 true반환
		{
			throw "harry.txt";
		}
	}
	catch (string Filename)
	{
		cout << " 파일 " << Filename << "이 존재하지 않거나 올바른 형식이 아닙니다.." << endl;
		return 0;
	}
	ofstream out_file("alignedcpp.txt");

	int tot = -1; //한줄에 들어가는 문자수 계산
	while (!(in_file.eof())) //파일이 정상적인 경우에...
	{
		in_file >> buffer;

		if ((tot + buffer.length() + 1) <= 80)//+1은 띄어쓰기까지 고려한것  
		{
			words.push_back(buffer);
			++tot;  //띄어쓰기 고려
			tot += words.back().length();   // ->  count 인덱스의 값은 없다
		}
		else if ((tot + buffer.length()) >= 80)  // 출력: buffer는 포함하지않고 출력한다.
		{
			int j = 0;
			for (unsigned int i = 0; i < (int)words.size(); i++)
			{
				out_file << words.at(i);

				if (i == words.size() - 1) //마지막 단어
				{
					out_file << endl;
					break;
				}
				int a = (80 - tot) / (words.size() - 1); //전체적으로 추가적으로 띄워쓸 횟수
				int b = (80 - tot) % (words.size() - 1); //개별 띄워쓸 횟수
				for (int i = 0; i <= a; i++)
				{
					out_file << " ";
				}
				if (j++ < b)
					out_file << " ";
			}
			tot = buffer.length();
			
			words.clear();
			words.push_back(buffer);
		}
		else { //나오면안되는 오류
			printf("의도하지않은 오류\n");
		}
	}

	for (unsigned int i = 0; i < words.size() - 1; i++) //마지막줄 쓰기
	{
		out_file << words.at(i) << " ";
	}
	out_file << words.back() ;

	words.clear();
	out_file.close();
	in_file.close();
	return 0;
}
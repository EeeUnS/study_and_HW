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
	try { // ����ó��
		if (in_file.fail())//���Ͼ����� true��ȯ
		{
			throw "harry.txt";
		}
	}
	catch (string Filename)
	{
		cout << " ���� " << Filename << "�� �������� �ʰų� �ùٸ� ������ �ƴմϴ�.." << endl;
		return 0;
	}
	ofstream out_file("alignedcpp.txt");

	int tot = -1; //���ٿ� ���� ���ڼ� ���
	while (!(in_file.eof())) //������ �������� ��쿡...
	{
		in_file >> buffer;

		if ((tot + buffer.length() + 1) <= 80)//+1�� ������� ����Ѱ�  
		{
			words.push_back(buffer);
			++tot;  //���� ���
			tot += words.back().length();   // ->  count �ε����� ���� ����
		}
		else if ((tot + buffer.length()) >= 80)  // ���: buffer�� ���������ʰ� ����Ѵ�.
		{
			int j = 0;
			for (unsigned int i = 0; i < (int)words.size(); i++)
			{
				out_file << words.at(i);

				if (i == words.size() - 1) //������ �ܾ�
				{
					out_file << endl;
					break;
				}
				int a = (80 - tot) / (words.size() - 1); //��ü������ �߰������� ����� Ƚ��
				int b = (80 - tot) % (words.size() - 1); //���� ����� Ƚ��
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
		else { //������ȵǴ� ����
			printf("�ǵ��������� ����\n");
		}
	}

	for (unsigned int i = 0; i < words.size() - 1; i++) //�������� ����
	{
		out_file << words.at(i) << " ";
	}
	out_file << words.back() ;

	words.clear();
	out_file.close();
	in_file.close();
	return 0;
}
#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>
using namespace std;

// Hàm tô màu.
void textcolor(int x)
{
	HANDLE mau;
	mau=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau,x);
}

void XuatVector(vector<string> a)
{
	cout << endl;

	for(int i = 0; i < a.size() - 1; ++i)
		cout << a[i] << " ";

	cout << a[a.size() - 1];
}

string TinhKetQuaBieuThucKhongNgoac(string s)
{
	// Bước 1: Tách chuỗi lưu vào mảng vector
	vector<string> a;

	// Tách chuỗi nếu dùng substring bên C++ thì thế này
	//int start = 0;
	//int end;

	//for(int i = start + 1; i < s.length(); ++i)
	//{
	//	if(s[i] == ' ')
	//	{
	//		end = i;
	//		//cout << s.substr(start, end - start) << endl;
	//		a.push_back(s.substr(start, end - start));
	//		start = end + 1;
	//	}
	//}

	////cout << s.substr(start, s.length() - start) << endl;
	//a.push_back(s.substr(start, s.length() - start));

	char *p = strtok((char *)s.c_str(), " ");

	while(p != NULL)
	{
		a.push_back(p);
		p = strtok(NULL, " ");
	}

	// Bước 2: Xử lý tính toán trên mảng

	int dem = 1;
	// Thực hiện nhân chia trước
	for(int i = 1; i < a.size(); i += 2)
	{
		if(a[i] == "*" || a[i] == "/")
		{
			cout << "\n\n";
			system("pause");
			textcolor(12);
			cout << "\n\tBuoc "<< dem++ << endl;
			textcolor(7);
			cout << "\tBieu thuc con = ";
			for(int j = 0; j < a.size(); ++j)
			{
				if(j >= i - 1 && j <= i + 1)
					textcolor(14); // vàng

				cout << a[j] << " ";

				textcolor(7); // trở lại như thường
			}

			float x = stof(a[i - 1]);
			float y = stof(a[i + 1]);

			float ketqua;

			if(a[i] == "*")
				ketqua = x * y;
			else if(a[i] == "/")
				ketqua = x / y;

			a[i - 1] = to_string(ketqua);

			// xóa a[i] và a[i + 1] đi
			a.erase(a.begin() + i);
			a.erase(a.begin() + i); // do sau lần xóa vị trí i đầu tiên thì vị trí i + 1 đã bị lùi xuống thành i nên không được xóa i + 1 mà phải xóa i

			cout << endl;
			cout << "\tBieu thuc con = ";
			for(int j = 0; j < a.size(); ++j)
			{
				if(j == i - 1)
					textcolor(14); // vàng

				cout
					<< a[j] << " ";

				textcolor(7); // trở lại như thường
			}

			i -= 2; // Phải lùi về 2 cho biến i bởi sau khi xóa thì index đã bị thay đổi cho nên nếu không lùi thì sẽ bị bỏ qua 1 số phép toán
		}
	}

	

	// Thực hiện cộng trừ sau
	for(int i = 1; i < a.size(); i += 2)
	{
		if(a[i] == "+" || a[i] == "-")
		{
			cout << "\n\n";
			system("pause");
			textcolor(12);
			cout << "\n\tBuoc "<< dem++ << endl;
			textcolor(7);
			cout << "\tBieu thuc con = ";
			for(int j = 0; j < a.size(); ++j)
			{
				if(j >= i - 1 && j <= i + 1)
					textcolor(14); // vàng

				cout << a[j] << " ";

				textcolor(7); // trở lại như thường
			}

			float x = stof(a[i - 1]);
			float y = stof(a[i + 1]);

			float ketqua;

			if(a[i] == "+")
				ketqua = x + y;
			else if(a[i] == "-")
				ketqua = x - y;

			a[i - 1] = to_string(ketqua);

			
			// xóa a[i] và a[i + 1] đi
			a.erase(a.begin() + i);
			a.erase(a.begin() + i); // do sau lần xóa vị trí i đầu tiên thì vị trí i + 1 đã bị lùi xuống thành i nên không được xóa i + 1 mà phải xóa i

			cout << endl;
			cout << "\tBieu thuc con = ";
			for(int j = 0; j < a.size(); ++j)
			{
				if(j == i - 1)
					textcolor(14); // vàng

				cout << a[j] << " ";

				textcolor(7); // trở lại như thường
			}

			i -= 2; // Phải lùi về 2 cho biến i bởi sau khi xóa thì index đã bị thay đổi cho nên nếu không lùi thì sẽ bị bỏ qua 1 số phép toán
		}
	}
	return a[0];
}

// có ngoặc hay không ngoặc đều tính được hết
string TinhKetQuaBieuThucToanHoc(string s)
{
	// Chủ động thêm vào dấu mở ngoặc ở đầu và đóng ngoặc ở cuối biểu thức toán học
	s.insert(0, "(");
	s.insert(s.length(), ")"); // hay có thể viết là: s += ")";

	vector<int> a; // Chứa các index của dấu mở ngoặc

	int dem = 1;
	for(int i = 0; i < s.length(); ++i)
	{
		if(s[i] == '(')
			a.push_back(i);
		else if(s[i] == ')')
		{
			int end = i;
			int start = a[a.size() - 1];

			string bieuthuctrongngoac = s.substr(start + 1, end - 1 - start);

			cout << "\n\nBuoc " << dem++;

			cout << "\nBieu thuc = ";
			for(int j = 0; j < s.length(); ++j)
			{
				if(j >= start && j <= end)
					textcolor(14);

				cout << s[j];

				textcolor(7);
			}

			cout << "\nDi tinh bieu thuc con: " << bieuthuctrongngoac;

			string ketqua = TinhKetQuaBieuThucKhongNgoac(bieuthuctrongngoac);

			s.erase(start, end - start + 1); // Xóa đoạn biểu thức có ngoặc đã tính ra kết quả
			s.insert(start, ketqua); // Chèn chuỗi kết quả vào chuỗi s tại vị trí start

			cout << "\n\nKet qua sau khi tinh the vao bieu thuc ban dau = ";
			for(int j = 0; j < s.length(); ++j)
			{
				if(j >= start && j <= start + ketqua.length() - 1)
					textcolor(14);

				cout << s[j];

				textcolor(7);
			}

			i = start + ketqua.length() - 1;

			a.erase(a.begin() + a.size() - 1);
		}
	}

	return s;
}

int main()
{
	//string s = "1 + 2 * 3 - 4 / 5"; // 6.2
	//string s = "5 - 8 * 2 + 9 / 2 - 6";
	//string s = "1 - 2 + 3 / 4 * 5 - 6 * 7 / 2 + 9 - 1 * 8 + 5";
	//string s = "90.9 - 5 * 8.5 / 4 + 6.5 - 3 / 2 + 1 * 23.3 / 100";
	//string s = "1 + 2 * ((3 - 4) / 5)";  // 0.6
	//string s = "1 - 2 + 3 / 4 * (5 - 6 * 7) / 2 + (9 - 1 * 8) + 5"; // -8.87500
	//string s = "1 - 2 + 3 * (4 * (5 - 6 * 7)) / (2 + (9 - 1 * 8)) + 5"; // -144
	string s = "90 - (5 * 8 / (4 + 6) - 3 / (2 + 1) * 23) / 100"; // 90.19
	//string s = "1 - (-2 - -3) * 4"; // -3

	cout << "\nBieu thuc can tinh s = " << s;

	cout << "\nKet qua cuoi cung cua bieu thuc la: " << TinhKetQuaBieuThucToanHoc(s);

	

	// Cách để tra mã màu
	/*for(int i = 1; i <= 200; ++i)
	{
		textcolor(i);
		cout << i << endl;
	}*/

	system("pause");
	return 0;
}
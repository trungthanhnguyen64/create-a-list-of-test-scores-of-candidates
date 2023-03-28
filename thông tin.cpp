 #include<iostream>
#include<string>

using namespace std;

class thisinh
{
	private:
		string ts_ten;
		string ts_mats;
		int ts_tuoi;
		float ts_diemtoan;
		float ts_diemvan;
		float ts_diemanh;
		float ts_diemtb1;
		float ts_diemtb2;
	public:
		
		// ham tao
		thisinh(string ten, string mats, int tuoi, float diemtoan, float diemvan, float diemanh)
		{	
			this->ts_ten = ten;
			this->ts_mats = mats;
			this->ts_tuoi = tuoi;
			this->ts_diemtoan = diemtoan;
			this->ts_diemvan = diemvan;
			this->ts_diemanh = diemanh;
			cout<<"Goi ham tao"<<endl;
		}
		thisinh()
		{	
			this->ts_tuoi = 0;
			this->ts_diemtoan = 0;
			this->ts_diemvan = 0;
			this->ts_diemanh = 0;			
		}
		// ham huy
		~thisinh()
		{
			cout<<"Goi ham huy"<<endl;
		}
		
		void setTen(string ten)
		{
			ts_ten = ten;
		}
		void setMats(string mats)
		{
			ts_mats = mats;
		}
		int setTuoi(int tuoi)
		{
			ts_tuoi = tuoi;
			return ts_tuoi;
		}
		float setDiemtoan(float diemtoan)
		{
			ts_diemtoan = diemtoan;	
			return ts_diemtoan;
		}
		float setDiemvan(float diemvan)
		{
			ts_diemvan = diemvan;
			return ts_diemvan;
		}
		float setDiemanh(float diemanh)
		{
			ts_diemanh = diemanh;
			return ts_diemanh;
		}
		float getts_diemtb1(){
			return ts_diemtb1;
		}	
		float getts_diemtb2(){
			return ts_diemtb2;
		}

		// ham tinh diem trung binh khong co trong so
		void tinhTB1()
		{
			
			ts_diemtb1 = (ts_diemtoan + ts_diemvan + ts_diemanh)/3;
			
		}
		// ham tinh diem trung binh co trong so
		void tinhTB2()
		{
			ts_diemtb2 = (2*ts_diemtoan + ts_diemvan + ts_diemanh)/4;
		}

		void printTT()
		{	
			cout<<endl;
			cout<<"Ten thi sinh: "<<ts_ten<<endl;
			cout<<"Ma so thi sinh: "<<ts_mats<<endl;
			cout<<"Tuoi thi sinh: "<<ts_tuoi<<endl;
			cout<<"Diem toan: "<<ts_diemtoan<<" "<<"diem van: "<<ts_diemvan<<" "<<"diem anh: "<<ts_diemanh<<endl;
			cout<<"Diem trung binh khong co trong so:  "<<ts_diemtb1<<endl;
			cout<<"Diem trung binh co trong so "<<ts_diemtb2<<endl;
		}
		
			void getInfo() {
		cout << "-------------Set Infomation-----------\n";
		cin.ignore();
		cout << "ten: "; getline(std::cin, this->ts_ten);
		cout << "\ntuoi: "; cin >> this->ts_tuoi;
		cout << "\nMats: "; cin >> this->ts_mats;
		cout << "\nDiem Toan: "; cin >> this->ts_diemtoan;
		cout << "\nDiem Van: "; cin >> this->ts_diemvan;
		cout << "\nDiem Anh: "; cin >> this->ts_diemanh;
	}
	
};



int main()
{	

//Nhap vao n thi sinh
//Sinh ra danh sach n thi sinh va nhap thong tin
//Sap xep va in theo trat tu giam dan cua diem trung binh
int n;
cout << "Nhap so thi sinh n = ";
cin >> n;

thisinh* arr=new thisinh[n];
for(int i = 0; i < n; i++) {
	arr[i].getInfo();
	arr[i].tinhTB1();
	arr[i].tinhTB2();
}
	thisinh mediate;
	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = i + 1; j < n; j++)
		{
			if (arr[i].getts_diemtb1() > arr[j].getts_diemtb1()) {
				mediate = arr[i];
				arr[i] = arr[j];
				arr[j] = mediate;
			}
		}
	}
 cout<< "-------------Danh sach sap xep thi sinh theo diem tang dan---------------";
for(int i = 0; i < n; i++) {
	arr[i].printTT();
}




/*
	float toan,van,anh;
	string ten, mats;
	int tuoi;
	float diemtb1, diemtb2;
	// nhap thong tin thi sinh
	cout<<"Nhap ten cua thi sinh: ";
	getline(cin,ten);
	cout<<"Nhap ma thi sinh: ";
	getline(cin,mats);
	cout<<"Nhap tuoi cua thi sinh: ";
	cin>>tuoi;
	cout<<"Nhap diem toan cua thi sinh: ";
	cin>>toan;
	cout<<"Nhap diem van cua thi sinh: ";
	cin>>van;
	cout<<"Nhap diem anh cua thi sinh: ";
	cin>>anh;
	thisinh ts1 (ten, mats, tuoi, toan, van, anh);
	ts1.tinhTB1();
	ts1.tinhTB2();
	// diem trung binh khong co trong so
	//ts1.tinhTB1(toan,van,anh,diemtb1);
	// diem trung binh co trong so
	//ts1.tinhTB2(toan,van,anh,diemtb2);
	// in thong tin thi sinh
	ts1.printTT();	
	*/
	system("pause");
	return 0;
}
